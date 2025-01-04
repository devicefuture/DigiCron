#include <Arduino.h>

#include "console.h"

void console::logPart(proc::Process* ownerProcess, String value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, char* value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, unsigned int value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, int value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, unsigned long value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, long value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, double value) {
    Serial.print(value);
}

void console::logPart(proc::Process* ownerProcess, void* value) {
    Serial.print("0x");
    Serial.print((unsigned int)value, HEX);
}

template<typename T> void console::logPart(T value) {
    logPart(nullptr, value);
}

void console::logNewline(proc::Process* ownerProcess) {
    Serial.println();
}

void console::logNewline() {
    logNewline(nullptr);
}