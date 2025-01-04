#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Arduino.h>

#include "proc.h"

namespace console {
    void logPart(proc::Process* ownerProcess, String value);
    void logPart(proc::Process* ownerProcess, char* value);
    void logPart(proc::Process* ownerProcess, unsigned int value);
    void logPart(proc::Process* ownerProcess, int value);
    void logPart(proc::Process* ownerProcess, unsigned long value);
    void logPart(proc::Process* ownerProcess, long value);
    void logPart(proc::Process* ownerProcess, double value);
    void logPart(proc::Process* ownerProcess, void* value);
    template<typename T> void logPart(T value);

    void logNewline(proc::Process* ownerProcess);
    void logNewline();
}

#endif