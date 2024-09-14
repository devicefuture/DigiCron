#ifndef DC_SIMULATOR
    #include "HCMS39xx.h"
    #include "font5x7.h"
#endif

#include <Arduino.h>

#include "ui.h"
#include "display.h"

ui::Screen* ui::currentScreen;

void ui::Icon::setPixel(unsigned int x, unsigned int y, bool value) {
    char valueMask = 0;

    if (value) {
        iconData[x] |= 1 << y;
    } else {
        iconData[x] &= ~(1 << y);
    }
}

ui::Screen::Screen() {
    clear();
}

void ui::Screen::clear() {
    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = 0;
    }

    _currentPosition = 0;
}

void ui::Screen::print(char c) {
    char asciiOffset = pgm_read_byte(&font5x7[0]) - 1;
    char* fontByte = (char*)font5x7 + ((c - asciiOffset) * display::CHAR_COLUMNS);

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = fontByte[offset];
    }

    _nextPosition();
}

void ui::Screen::print(String string) {
    for (unsigned int i = 0; i < string.length(); i++) {
        print(string[i]);
    }
}

void ui::Screen::print(Icon icon) {
    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = icon.iconData[offset];
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

ui::Icon ui::constructIcon(String pixels) {
    Icon icon;

    for (unsigned int i = 0; i < pixels.length(); i++) {
        unsigned int x = i % display::CHAR_COLUMNS;
        unsigned int y = i / display::CHAR_COLUMNS;

        if (y >= 8) {
            break;
        }

        icon.setPixel(x, y, pixels[i] != ' ');
    }

    return icon;
}