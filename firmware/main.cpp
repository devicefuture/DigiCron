#include <Arduino.h>

#ifndef DC_SIMULATOR
    #include <Adafruit_TinyUSB.h>
    #include "HCMS39xx.h"
    #include "font5x7.h"
#else
    #include <emscripten.h>
    #include <stdio.h>
#endif

#include "datatypes.h"
#include "timing.h"
#include "power.h"
#include "display.h"
#include "ui.h"
#include "input.h"
#include "home.h"
#include "proc.h"

#define BACK_BTN_PIN 6
#define HOME_BTN_PIN 5
#define JOY_UP_PIN 10
#define JOY_DOWN_PIN 12
#define JOY_LEFT_PIN 9
#define JOY_RIGHT_PIN 11
#define JOY_SELECT_PIN 13

ui::Screen* testScreen = new ui::Screen();

ui::Icon tmIcon = ui::constructIcon(
    "###  "
    " #   "
    "     "
    "## ##"
    "# # #"
);

unsigned int displayMode = 0;
long lastTick = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");

    timing::init();
    display::init();
    input::init();

    ui::currentScreen = testScreen;

    testScreen->print(" device  future");
    testScreen->print(tmIcon);

    #ifndef DC_SIMULATOR
        while (true) {
            loop();
        }
    #endif
}

void loop() {
    long currentTick = timing::getCurrentTick();
    int difference = currentTick - lastTick;

    timing::earthTime.incrementTime(difference);

    lastTick = currentTick;

    if (ui::currentScreen == testScreen && millis() > 3000) {
        home::homeScreen.open(true);

        // proc::WasmProcess testProcess((char*)apptest_app_wasm, apptest_app_wasm_len);
    }

    proc::stepProcesses();
    ui::renderCurrentScreen();
}

#ifdef DC_SIMULATOR

int main(int argc, char** argv) {
    setup();

    emscripten_set_main_loop(loop, 0, true);

    return 0;
}

#endif