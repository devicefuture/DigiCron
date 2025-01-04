#include <Arduino.h>

#include "console.h"

void console::logString(proc::Process* ownerProcess, String value) {
    Serial.println(value);
}