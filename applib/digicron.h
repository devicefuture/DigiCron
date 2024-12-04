#ifndef DIGICRON_H_
#define DIGICRON_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

void setup();
void loop();

extern "C" {

WASM_IMPORT("digicron", "log") void dc_log(uint8_t* text, uint8_t length);
WASM_IMPORT("digicron", "stop") void dc_stop();

}

WASM_EXPORT void _start() {
    setup();
}

WASM_EXPORT void _step() {
    loop();
}

class String {};

namespace dc {

namespace timing {
    class EarthTime {
        public:
            unsigned int daysInYear();
            unsigned int daysInMonth();
            unsigned long millisecondsInDay();
            struct LeapAdjustment leapAdjustmentToday();
            bool inLeapMillisecond();
            unsigned long postLeapMillisecondOffset();
            void setDate(int year, unsigned int month, unsigned int day);
            void setTime(unsigned int hour, unsigned int minute, unsigned int second);
            void incrementTime(int millseconds);
            void toLocalTime(int timeShift);
            void toGlobalTime();
            int year();
            unsigned int month();
            unsigned int day();
            unsigned int hour();
            unsigned int minute();
            unsigned int second();
            unsigned int millisecond();
            unsigned int dayOfYear();
            unsigned long millisecondOfDay();
            unsigned long millisecondOfDayIgnoringLeap();
            unsigned int weekday();
    };
}

namespace ui {
    enum EventType {
        BUTTON_DOWN,
        BUTTON_UP
    };

    enum PopupTransitionState {
        NONE,
        OPENING,
        CLOSING
    };

    enum PenMode {
        OFF,
        ON
    };

    class Icon {
        public:
            void setPixel(unsigned int x, unsigned int y, PenMode value);
    };

    class Screen {
        public:
            void clear();
            void setPosition(unsigned int column, unsigned int row);
            void setPixel(unsigned int x, unsigned int y, PenMode value);
            void print(char c);
            void print(char* chars);
            void print(String string);
            void print(Icon icon);
            void printRepeated(String string, unsigned int times);
            void scroll(String string, unsigned int maxLength);
            void resetScroll();
            void rect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value);
            void filledRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value);
            void open(bool urgent);
            void close();
            void swapWith(Screen* currentScreen);
    };
}

}
#endif
