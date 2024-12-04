#include <Arduino.h>
#include <m3_env.h>

#include "api.h"
#include "proc.h"

m3ApiRawFunction(oldApi::log) {
    m3ApiGetArgMem(uint8_t*, text)
    m3ApiGetArg(uint32_t, length)

    Serial.write(text, length);
    Serial.println();
    Serial.flush();

    m3ApiSuccess();
}

m3ApiRawFunction(oldApi::stop) {
    ((proc::WasmProcess*)runtime->userdata)->stop();

    m3ApiSuccess();
}

void oldApi::linkFunctions(IM3Runtime runtime) {
    const char* MODULE_NAME = "digicronold";

    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "log", "v(*i)", &log);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "stop", "v()", &stop);
}