#include <Arduino.h>
#include <m3_env.h>

#include "api.h"

m3ApiRawFunction(api::log) {
    m3ApiGetArgMem(uint8_t*, text)
    m3ApiGetArg(uint32_t, length)

    Serial.write(text, length);
    Serial.println();

    m3ApiSuccess();
}

void api::linkFunctions(IM3Runtime runtime) {
    const char* MODULE_NAME = "digicron";

    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "log", "v(*i)", &log);
}