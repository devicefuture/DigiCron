#ifndef DC_COMMON_CONSOLE_CPP_
#define DC_COMMON_CONSOLE_CPP_

#ifndef DIGICRON_H_
    #include "../console.h"
    #include "console.h"
#endif

template<typename T> void console::log(T value) {
    logPart(value);
    logNewline();
}

template<typename T, typename ...Args> void console::log(T value, Args... args) {
    logPart(value);
    logPart(" ");
    log(args...);
}

#endif