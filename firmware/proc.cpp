#include "proc.h"
#include "api.h"

unsigned int proc::pidCounter = 0;

proc::Process::Process() {
    _pid = pidCounter++;
}

unsigned int proc::Process::getPid() {
    return _pid;
}

bool proc::Process::isRunning() {
    return true;
}

proc::WasmProcess::WasmProcess(char* code, unsigned int codeSize) : proc::Process() {
    _environment = m3_NewEnvironment();
    _runtime = m3_NewRuntime(_environment, WASM_STACK_SLOTS, NULL);

    if (!_runtime) {
        _error = WasmError::INIT_FAILURE;
        return;
    }

    if (
        m3_ParseModule(_environment, &_module, (uint8_t*)code, codeSize) ||
        m3_LoadModule(_runtime, _module)
    ) {
        _error = WasmError::PARSE_FAILURE;
        return;
    }

    api::linkFunctions(_runtime);

    IM3Function startFunction;

    if (m3_FindFunction(&startFunction, _runtime, "_start")) {
        _error = WasmError::LOAD_FAILURE;
        return;
    }

    if (m3_CallV(startFunction)) {
        _error = WasmError::RUN_FAILURE;
        return;
    }
}

bool proc::WasmProcess::isRunning() {
    return false;
}

void proc::WasmProcess::step() {}

M3Result m3_Yield() {
    // TODO: Limit execution

    return m3Err_none;
}