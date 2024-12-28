#include "proc.h"
#include "api.h"
#include "_api.h"

#include <m3_env.h>

unsigned int proc::pidCounter = 0;
dataTypes::List<proc::Process> proc::processes;

proc::Process::Process() {
    _pid = pidCounter++;

    processes.push(this);
}

proc::Process::~Process() {
    stop();

    int i = processes.indexOf(this);

    if (i < 0) {
        return;
    }

    processes.remove(i);
}

unsigned int proc::Process::getPid() {
    return _pid;
}

bool proc::Process::isRunning() {
    return _running;
}

void proc::Process::step() {}

void proc::Process::stop() {
    if (!_running) {
        return;
    }

    _running = false;

    onStop(this);
}

proc::WasmProcess::WasmProcess(char* code, unsigned int codeSize) : proc::Process() {
    _environment = m3_NewEnvironment();
    _runtime = m3_NewRuntime(_environment, WASM_STACK_SLOTS, this);

    if (!_runtime) {
        _error = WasmError::INIT_FAILURE;
        _running = false;
        return;
    }

    if (
        m3_ParseModule(_environment, &_module, (uint8_t*)code, codeSize) ||
        m3_LoadModule(_runtime, _module)
    ) {
        _error = WasmError::PARSE_FAILURE;
        _running = false;
        return;
    }

    oldApi::linkFunctions(_runtime);
    api::linkFunctions(_runtime);

    IM3Function initFunction;
    IM3Function startFunction;

    bool shouldCallInit = !m3_FindFunction(&initFunction, _runtime, "__wasm_call_ctors");

    if (
        m3_FindFunction(&startFunction, _runtime, "_setup") ||
        m3_FindFunction(&_stepFunction, _runtime, "_loop")
    ) {
        _error = WasmError::LOAD_FAILURE;
        _running = false;
        return;
    }

    M3Result result = m3Err_none;

    if (shouldCallInit && (result = m3_CallV(initFunction))) {
        _error = WasmError::RUN_FAILURE;
        _running = false;
        return;
    }

    if ((result = m3_CallV(startFunction))) {
        _error = WasmError::RUN_FAILURE;
        _running = false;
        return;
    }
}

bool proc::WasmProcess::isRunning() {
    return _running;
}

void proc::WasmProcess::step() {
    if (!_running) {
        return;
    }

    if (m3_CallV(_stepFunction)) {
        _error = WasmError::RUN_FAILURE;
        return;
    }
}

void proc::WasmProcess::stop() {
    if (!_running) {
        return;
    }

    Process::stop();

    api::deleteAllByOwnerProcess(this);

    m3_FreeRuntime(_runtime);
    m3_FreeEnvironment(_environment);
}

template<typename ...Args> void proc::WasmProcess::callVoid(const char* name, Args... args) {
    IM3Function function;

    if (m3_FindFunction(&function, _runtime, name)) {
        return;
    }

    m3_CallV(function, args...);
}

template<typename T, typename ...Args> T proc::WasmProcess::call(const char* name, T defaultValue, Args... args) {
    IM3Function function;
    T result;

    if (
        m3_FindFunction(&function, _runtime, name) ||
        m3_CallV(function, args...) ||
        m3_GetResultsV(function, &result)
    ) {
        return defaultValue;
    }

    return result;
}

template<typename ...Args> void proc::WasmProcess::callVoidOn(void* instance, const char* name, Args... args) {
    api::Sid sid = api::findOwnSid(instance);

    if (sid < 0) {
        return;
    }

    callVoid(name, sid, args...);
}

template<typename T, typename ...Args> T proc::WasmProcess::callOn(void* instance, const char* name, T defaultValue, Args... args) {
    api::Sid sid = api::findOwnSid(instance);

    if (sid < 0) {
        return defaultValue;
    }

    return call(name, sid, args...);
}

void proc::stepProcesses() {
    processes.start();

    while (auto process = processes.next()) {
        if (process && process->isRunning()) {
            process->step();
        }
    }
}

M3Result m3_Yield() {
    // TODO: Limit execution

    return m3Err_none;
}

template void proc::WasmProcess::callVoidOn<>(void*, char const*);
template void proc::WasmProcess::callVoidOn<ui::EventType, input::Button>(void*, char const*, ui::EventType, input::Button);