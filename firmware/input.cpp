#ifndef DC_SIMULATOR
    #include <Arduino.h>
#else
    #include <emscripten.h>
    #include <emscripten/bind.h>
#endif

#include "input.h"

#ifndef DC_SIMULATOR

#define BTN_BACK_PIN 6
#define BTN_HOME_PIN 5
#define JOY_UP_PIN 10
#define JOY_DOWN_PIN 12
#define JOY_LEFT_PIN 9
#define JOY_RIGHT_PIN 11
#define JOY_SELECT_PIN 13

void input::init() {
    pinMode(BTN_BACK_PIN, INPUT_PULLUP);
    pinMode(BTN_HOME_PIN, INPUT_PULLUP);
    pinMode(JOY_UP_PIN, INPUT_PULLUP);
    pinMode(JOY_DOWN_PIN, INPUT_PULLUP);
    pinMode(JOY_LEFT_PIN, INPUT_PULLUP);
    pinMode(JOY_RIGHT_PIN, INPUT_PULLUP);
    pinMode(JOY_SELECT_PIN, INPUT_PULLUP);
}

input::Button input::getButtonStatus() {
    if (digitalRead(BTN_BACK_PIN) == LOW) return Button::BACK;
    if (digitalRead(BTN_HOME_PIN) == LOW) return Button::HOME;
    if (digitalRead(JOY_UP_PIN) == LOW) return Button::UP;
    if (digitalRead(JOY_DOWN_PIN) == LOW) return Button::DOWN;
    if (digitalRead(JOY_LEFT_PIN) == LOW) return Button::LEFT;
    if (digitalRead(JOY_RIGHT_PIN) == LOW) return Button::RIGHT;
    if (digitalRead(JOY_SELECT_PIN) == LOW) return Button::SELECT;

    return Button::NONE;
}

#else

input::Button currentButton = input::Button::NONE;

void input::init() {}

input::Button input::getButtonStatus() {
    return currentButton;
}

void setButtonStatus(uint32_t button) {
    currentButton = (input::Button)button;
}

EMSCRIPTEN_BINDINGS(dc_input) {
    emscripten::function("input_setButtonStatus", setButtonStatus);
}

#endif