#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <Arduino.h>

#include "proc.h"

namespace console {
    void logString(proc::Process* ownerProcess, String value);
}

#endif