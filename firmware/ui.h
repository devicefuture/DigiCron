#ifndef UI_H_
#define UI_H_

#include <Arduino.h>

#include "display.h"

namespace ui {
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
            void print(String string);
            void print(Icon icon);

        private:
            unsigned int _currentPosition = 0;

            void _nextPosition();
    };

    extern Screen* currentScreen;

    void renderCurrentScreen();

    Icon constructIcon(String pixels);
}

#endif