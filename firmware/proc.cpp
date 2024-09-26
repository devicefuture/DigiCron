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

m3ApiRawFunction(dc_log) {
    m3ApiGetArgMem(uint8_t*, text)
    m3ApiGetArg(uint32_t, length)

    Serial.write(text, length);
    Serial.println();

    m3ApiSuccess();
}

#define FATAL(msg, ...) { Serial.printf("Fatal: " msg "\n", ##__VA_ARGS__); return; }

#include <wasm3.h>
#include <m3_env.h>

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

    const char* MODULE_NAME = "digicron";

    m3_LinkRawFunction(_runtime->modules, MODULE_NAME, "log", "v(*i)", &dc_log);

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