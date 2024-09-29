#include "proc.h"
#include "api.h"

#include <m3_env.h>

unsigned int proc::pidCounter = 0;
dataTypes::List<proc::Process> proc::processes;

proc::Process::Process() {
    _pid = pidCounter++;

    processes.push(this);
}

unsigned int proc::Process::getPid() {
    return _pid;
}

bool proc::Process::isRunning() {
    return true;
}

void proc::Process::step() {}

proc::WasmProcess::WasmProcess(char* code, unsigned int codeSize) : proc::Process() {
    _environment = m3_NewEnvironment();
    _runtime = m3_NewRuntime(_environment, WASM_STACK_SLOTS, NULL);
    _runtime->userdata = this;

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

    api::linkFunctions(_runtime);

    IM3Function startFunction;
    if (
        m3_FindFunction(&startFunction, _runtime, "_start") ||
        m3_FindFunction(&_stepFunction, _runtime, "_step")
    ) {
        _error = WasmError::LOAD_FAILURE;
        _running = false;
        return;
    }

    if (m3_CallV(startFunction)) {
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
    _running = false;
}

void proc::stepProcesses() {
    processes.start();

    while (auto process = processes.next()) {
        if (process->isRunning()) {
            process->step();
        }
    }
}

M3Result m3_Yield() {
    // TODO: Limit execution

    return m3Err_none;
}