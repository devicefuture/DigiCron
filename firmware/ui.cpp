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
#include "proc.h"
#include "_api.h"
#include "home.h"

#include "common/ui.h"

input::Button ui::lastButton;
ui::Screen* ui::currentScreen;
proc::Process* ui::foregroundProcess = nullptr;
proc::Process* ui::lastNonHomeProcess = nullptr;
dataTypes::List<ui::Screen> ui::screenStack;

ui::Icon* menuSelectionIcon = ui::constructIcon(
    "     "
    "  #  "
    "   # "
    "#####"
    "   # "
    "  #  "
);

ui::Icon* menuScrollableIcon = ui::constructIcon(
    "  #  "
    " ### "
    "# # #"
    "  #  "
    "# # #"
    " ### "
    "  #  "
);

void ui::Icon::setPixel(unsigned int x, unsigned int y, ui::PenMode value) {
    if (value == PenMode::ON) {
        iconData[x] |= 1 << y;
    } else {
        iconData[x] &= ~(1 << y);
    }
}

ui::Screen::Screen() {
    clear();
    resetScroll();
}

ui::Screen::Screen(proc::Process* process) : ui::Screen::Screen() {
    ownerProcess = process;

    Serial.printf("New screen for process %x\n", process);

    Screen();
}

ui::Screen::~Screen() {
    close();
}

void ui::Screen::clear() {
    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = 0;
    }

    _currentPosition = 0;
}

void ui::Screen::setPosition(unsigned int column, unsigned int row) {
    _currentPosition = (row * display::COLUMNS) + column;
}

void ui::Screen::setPixel(unsigned int x, unsigned int y, ui::PenMode value) {
    if (x >= display::WIDTH) {
        return;
    }

    unsigned int offset = x + ((y / display::CHAR_ROWS) * display::WIDTH);

    if (offset > display::DATA_SIZE) {
        return;
    }

    char* bytePointer = displayData + offset;

    y %= display::CHAR_ROWS;

    if (value == PenMode::ON) {
        *bytePointer |= 1 << y;
    } else {
        *bytePointer &= ~(1 << y);
    }
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

void ui::Screen::print(Icon* icon) {
    if (_currentPosition >= display::CHAR_COUNT) {
        return;
    }

    for (unsigned int offset = 0; offset < display::CHAR_COLUMNS; offset++) {
        displayData[(_currentPosition * display::CHAR_COLUMNS) + offset] = icon->iconData[offset];
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

        return;
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

void ui::Screen::rect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value) {
    for (unsigned int x = x1; x <= x2; x++) {
        setPixel(x, y1, value);
        setPixel(x, y2, value);
    }

    for (unsigned int y = y1; y <= y2; y++) {
        setPixel(x1, y, value);
        setPixel(x2, y, value);
    }
}

void ui::Screen::filledRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, PenMode value) {
    for (unsigned int y = y1; y <= y2; y++) {
        for (unsigned int x = x1; x <= x2; x++) {
            setPixel(x, y, value);
        }
    }
}

void ui::Screen::open(bool urgent) {
    Serial.printf("Opened %x (urgent: %d)\n", ownerProcess, urgent);

    screenStack.push(this);

    if (urgent) {
        foregroundProcess = ownerProcess;
    }

    determineCurrentScreen();
}

void ui::Screen::close() {
    int i = screenStack.indexOf(this);

    if (i < 0) {
        return;
    }

    screenStack.remove(i);

    determineCurrentScreen();
}

void ui::Screen::swapWith(ui::Screen* currentScreen) {
    int i = screenStack.indexOf(currentScreen);

    if (i < 0) {
        return;
    }

    screenStack.set(i, this);

    determineCurrentScreen();
}

void ui::Screen::_update() {
    update();

    if (ownerProcess && ownerProcess->getType() == proc::ProcessType::WASM) {
        ((proc::WasmProcess*)ownerProcess)->callVoidOn(this, "_callable_ui_Screen_update");
    }
}

void ui::Screen::_handleEvent(ui::Event event) {
    handleEvent(event);

    if (ownerProcess && ownerProcess->getType() == proc::ProcessType::WASM) {
        if (event.type == EventType::BUTTON_UP || event.type == EventType::BUTTON_DOWN) {
            ((proc::WasmProcess*)ownerProcess)->callVoidOn(this, "_callable_ui_Screen_handleButtonEvent", event.type, event.data.button);
        }
    }
}

void ui::Menu::update() {
    clear();

    if (items.length() == 0) {
        print("(Empty)");

        return;
    }

    if (_currentIndex >= items.length()) {
        _currentIndex = items.length() - 1;
    }

    if ((int)_currentIndex < _scrollPosition) {
        _scrollPosition = _currentIndex;
    }

    if ((int)_currentIndex > _scrollPosition + (display::ROWS - 1)) {
        _scrollPosition = _currentIndex - 1;
    }

    for (unsigned int row = 0; row < display::ROWS; row++) {
        unsigned int i = row + _scrollPosition;

        setPosition(0, row);

        if (i == _currentIndex) {
            print(menuSelectionIcon);
            scroll(*items[i], display::COLUMNS - 1);
        } else {
            print(" ");
            print((*items[i]).substring(0, display::COLUMNS - 1));
        }
    }
}

void ui::Menu::open(bool urgent) {
    _currentIndex = 0;
    _scrollPosition = 0;

    ui::Screen::open(urgent);
}

void ui::Menu::handleEvent(Event event) {
    if (event.type == EventType::BUTTON_DOWN) {
        switch (event.data.button) {
            case input::Button::BACK:
            {
                if (onCancel) onCancel(this);

                break;
            }

            case input::Button::UP:
            {
                if (_currentIndex > 0) {
                    _currentIndex--;
                } else {
                    _currentIndex = items.length() - 1;
                }

                resetScroll();

                break;
            }

            case input::Button::DOWN:
            {
                if (_currentIndex < items.length() - 1) {
                    _currentIndex++;
                } else {
                    _currentIndex = 0;
                }

                resetScroll();

                break;
            }

            case input::Button::SELECT:
            {
                if (_currentIndex < items.length()) {
                    if (onSelect) onSelect(this, _currentIndex);
                } else {
                    if (onCancel) onCancel(this);
                }

                break;
            }

            default: break;
        }
    }
}

void ui::ContextualMenu::update() {
    clear();

    scroll(title);

    if (items.length() == 0) {
        print("(Empty)");

        return;
    }

    if (_currentIndex >= items.length()) {
        _currentIndex = items.length() - 1;
    }

    scroll(*items[_currentIndex], display::COLUMNS - 1);
    print(menuScrollableIcon);
}

void ui::Popup::open(bool urgent) {
    _transitionState = PopupTransitionState::OPENING;
    _transitionEndsAt = timing::getCurrentTick() + POPUP_TRANSITION_DURATION;

    Screen::open(urgent);
}

void ui::Popup::close() {
    _transitionState = PopupTransitionState::CLOSING;
    _transitionEndsAt = timing::getCurrentTick() + POPUP_TRANSITION_DURATION;
}

void ui::Popup::_update() {
    unsigned long currentTick = timing::getCurrentTick();
    int rectInset = -1;

    if (_transitionState != PopupTransitionState::NONE) {
        if (currentTick < _transitionEndsAt) {
            unsigned long transitionTime = (
                _transitionState == PopupTransitionState::OPENING ?
                _transitionEndsAt - currentTick :
                currentTick - (_transitionEndsAt - POPUP_TRANSITION_DURATION)
            );

            rectInset = (transitionTime * display::CHAR_ROWS) / POPUP_TRANSITION_DURATION;

            clear();
            rect(rectInset * 2, rectInset, display::WIDTH - (rectInset * 2), display::HEIGHT - rectInset, PenMode::ON);

            return;
        } else {
            clear();

            if (_transitionState == PopupTransitionState::CLOSING) {
                Screen::close();
            }

            _transitionState = PopupTransitionState::NONE;
        }
    }

    Screen::_update();
}

void ui::Popup::_handleEvent(ui::Event event) {
    if (_transitionState == PopupTransitionState::NONE) {
        handleEvent(event);
    }
}

ui::Screen* ui::determineCurrentScreen() {
    if (screenStack.length() > 0) {
        bool anyScreensFoundInForeground = false;

        screenStack.start();

        while (ui::Screen* screen = screenStack.next()) {
            if (screen->ownerProcess != foregroundProcess) {
                continue;
            }

            currentScreen = screen;
            anyScreensFoundInForeground = true;
        }

        if (!anyScreensFoundInForeground) {
            ui::Screen* lastScreen = screenStack[-1];

            if (lastScreen) {
                currentScreen = lastScreen;
                foregroundProcess = lastScreen->ownerProcess;
            }
        }
    }

    if (foregroundProcess != &home::homeProcess) {
        lastNonHomeProcess = foregroundProcess;
    }

    return currentScreen;
}

void ui::renderCurrentScreen() {
    input::Button currentButton = input::getButtonStatus();

    if (currentButton != lastButton) {
        if (lastButton != input::Button::NONE) {
            Event buttonUpEvent = {
                .type = EventType::BUTTON_UP,
                .data = {.button = lastButton}
            };

            currentScreen->_handleEvent(buttonUpEvent);
        }

        if (currentButton != input::Button::NONE) {
            Event buttonDownEvent = {
                .type = EventType::BUTTON_DOWN,
                .data = {.button = currentButton}
            };

            currentScreen->_handleEvent(buttonDownEvent);

            if (currentButton == input::Button::HOME) {
                if (currentScreen == &home::homeScreen) {
                    if (lastNonHomeProcess) {
                        foregroundProcess = lastNonHomeProcess;

                        determineCurrentScreen();
                    }
                } else if (currentScreen->canGoHome) {
                    foregroundProcess = &home::homeProcess;

                    determineCurrentScreen();
                }
            }
        }

        lastButton = currentButton;
    }

    currentScreen->_update();

    display::render(currentScreen->displayData);
}

template<typename T>
void ui::defaultCancellationCallback(T* self) {
    self->close();
}

template void ui::defaultCancellationCallback<ui::Menu>(ui::Menu* self);