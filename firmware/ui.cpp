#ifndef DC_SIMULATOR
    #include "HCMS39xx.h"
    #include "font5x7.h"
#endif

#include "ui.h"
#include "display.h"

ui::Screen::Screen() {
    clear();
}

void ui::Screen::clear() {
    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = 0;
    }
}

void ui::Screen::print(char c) {
    char asciiOffset = pgm_read_byte(&font5x7[0]) - 1;
    char* fontByte = (char*)font5x7 + ((c - asciiOffset) * display::CHAR_COLUMNS);

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = fontByte[offset];
    }

    _nextPosition();
}

void ui::Screen::_nextPosition() {
    _currentPosition++;

    if (_currentPosition >= display::CHAR_COUNT) {
        _currentPosition = 0;
    }
}

void ui::renderCurrentScreen() {
    display::render(currentScreen->displayData);
}