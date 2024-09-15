#ifndef UI_H_
#define UI_H_

#include <Arduino.h>

#include "input.h"
#include "display.h"

namespace ui {
    enum EventType {
        BUTTON_DOWN,
        BUTTON_UP
    };

    struct Event {
        EventType type;
        union {
            input::Button button;
        } data;
    };

    class Icon {
        public:
            char iconData[display::CHAR_COLUMNS];

            void setPixel(unsigned int x, unsigned int y, bool value);
    };

    class Screen {
        public:
            char displayData[display::DATA_SIZE];

            Screen();

            void clear();
            void print(char c);
            void print(char* chars);
            void print(String string);
            void print(String format, ...);
            void print(Icon icon);

            virtual void update() {}
            virtual void handleEvent(Event event) {}

        private:
            unsigned int _currentPosition = 0;
    };

    extern input::Button lastButton;
    extern Screen* currentScreen;

    void renderCurrentScreen();

    Icon constructIcon(String pixels);
}

#endif