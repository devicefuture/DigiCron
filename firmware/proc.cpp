#include "proc.h"

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

proc::WasmProcess::WasmProcess(char* code) : proc::Process() {
    _environment = m3_NewEnvironment();
    _runtime = m3_NewRuntime(_environment, WASM_STACK_SLOTS, NULL);

    if (!_runtime) {
        _error = WasmError::INIT_FAILURE;

        return;
    }
}