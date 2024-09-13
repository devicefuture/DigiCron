#ifndef UI_H_
#define UI_H_

#include "display.h"

namespace ui {
    class Screen {
        public:
            char displayData[display::DATA_SIZE];

            Screen();

            void clear();
            void print(char c);

        private:
            unsigned int _currentPosition = 0;

            void _nextPosition();
    };

    Screen* currentScreen = nullptr;

    void renderCurrentScreen();
}

#endif