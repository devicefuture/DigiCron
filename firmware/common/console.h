#ifndef DC_COMMON_CONSOLE_H_
#define DC_COMMON_CONSOLE_H_

namespace console {
    template<typename T> void log(T value);
    template<typename T, typename ...Args> void log(T value, Args... args);
}

#endif