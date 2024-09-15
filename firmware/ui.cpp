#ifndef DC_SIMULATOR
    #include "HCMS39xx.h"
    #include "font5x7.h"
#endif

#include <Arduino.h>

#include "ui.h"
#include "input.h"
#include "display.h"

input::Button ui::lastButton;
ui::Screen* ui::currentScreen;

void ui::Icon::setPixel(unsigned int x, unsigned int y, bool value) {
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
    if (_currentPosition >= display::CHAR_COUNT) {
        return;
    }

    char asciiOffset = pgm_read_byte(&font5x7[0]) - 1;
    char* fontByte = (char*)font5x7 + ((c - asciiOffset) * display::CHAR_COLUMNS);

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = fontByte[offset];
    }

    _currentPosition++;
}

void ui::Screen::print(String string) {
    for (unsigned int i = 0; i < string.length(); i++) {
        print(string[i]);
    }
}

void ui::Screen::print(char* chars) {
    unsigned int i = 0;

    while (chars[i] != '\0') {
        print(chars[i++]);
    }
}

void ui::Screen::print(String format, ...) {
    va_list args;
    char formatCharArray[33];
    char outputCharArray[17];

    format.toCharArray(formatCharArray, sizeof(formatCharArray));

    va_start(args, format);
    vsnprintf(outputCharArray, sizeof(outputCharArray), formatCharArray, args);
    va_end(args);

    print(outputCharArray);
}

void ui::Screen::print(Icon icon) {
    if (_currentPosition >= display::CHAR_COUNT) {
        return;
    }

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = icon.iconData[offset];
    }

    _currentPosition++;
}

void ui::renderCurrentScreen() {
    input::Button currentButton = input::getButtonStatus();

    if (currentButton != lastButton) {
        if (lastButton != input::Button::NONE) {
            Event buttonUpEvent = {
                .type = EventType::BUTTON_UP,
                .data = {.button = lastButton}
            };

            currentScreen->handleEvent(buttonUpEvent);
        }

        if (currentButton != input::Button::NONE) {
            Event buttonDownEvent = {
                .type = EventType::BUTTON_DOWN,
                .data = {.button = currentButton}
            };

            currentScreen->handleEvent(buttonDownEvent);
        }

        lastButton = currentButton;
    }

    currentScreen->update();

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