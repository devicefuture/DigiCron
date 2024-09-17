#ifndef DC_SIMULATOR
    #include "HCMS39xx.h"
#else
    #include <stdio.h>
    #include <stdarg.h>
#endif

#include <Arduino.h>
#include "font5x7.h"

#include "ui.h"
#include "input.h"
#include "display.h"
#include "timing.h"

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
    resetScroll();
}

void ui::Screen::clear() {
    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = 0;
    }

    _currentPosition = 0;
}

void ui::Screen::setPosition(unsigned int column, unsigned int row) {
    _currentPosition = (row * display::CHAR_COLUMNS) + column;
}

void ui::Screen::print(char c) {
    if (_currentPosition >= display::CHAR_COUNT) {
        return;
    }

    if (c == '\n') {
        _currentPosition += display::COLUMNS - (_currentPosition % display::COLUMNS);

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

void ui::Screen::print(Icon icon) {
    if (_currentPosition >= display::CHAR_COUNT) {
        return;
    }

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = icon.iconData[offset];
    }

    _currentPosition++;
}

void ui::Screen::printf(String format, ...) {
    va_list args;
    char formatCharArray[33];
    char outputCharArray[17];

    format.toCharArray(formatCharArray, sizeof(formatCharArray));

    va_start(args, format);
    vsnprintf(outputCharArray, sizeof(outputCharArray), formatCharArray, args);
    va_end(args);

    print(outputCharArray);
}

void ui::Screen::printRepeated(String string, unsigned int times) {
    for (unsigned int i = 0; i < times; i++) {
        print(string);
    }
}

void ui::Screen::scroll(String string, unsigned int maxLength) {
    if (string.length() <= maxLength) {
        print(string);
        printRepeated(" ", maxLength - string.length());
    }

    unsigned int maxTime = SCROLL_DELAY + (SCROLL_INTERVAL * (string.length() + 1));
    unsigned int currentTime = (timing::getCurrentTick() - _scrollStartTime) % maxTime;
    unsigned int scrollPosition = 0;

    if (currentTime > SCROLL_DELAY) {
        scrollPosition = (currentTime - SCROLL_DELAY) / SCROLL_INTERVAL;
    }

    String part = string.substring(scrollPosition, scrollPosition + maxLength);

    print(part);
    printRepeated(" ", maxLength - part.length());
}

void ui::Screen::resetScroll() {
    _scrollStartTime = timing::getCurrentTick();
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