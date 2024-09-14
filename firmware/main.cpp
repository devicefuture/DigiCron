#include <Arduino.h>

#ifndef DC_SIMULATOR
    #include <Adafruit_TinyUSB.h>
    #include "HCMS39xx.h"
    #include "font5x7.h"
#else
    #include <emscripten.h>
    #include <stdio.h>
#endif

#include "timing.h"
#include "power.h"
#include "display.h"
#include "ui.h"
#include "input.h"

#define BACK_BTN_PIN 6
#define HOME_BTN_PIN 5
#define JOY_UP_PIN 10
#define JOY_DOWN_PIN 12
#define JOY_LEFT_PIN 9
#define JOY_RIGHT_PIN 11
#define JOY_SELECT_PIN 13

timing::EarthTime timeKeeper(2024, 1, 1, 0, 0, 0);

ui::Screen* testScreen = new ui::Screen();

ui::Icon happyIcon = ui::constructIcon(
    " ### "
    "#####"
    "# # #"
    "#####"
    "# # #"
    "## ##"
    " ### "
);

unsigned int displayMode = 0;
long lastTick = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");

    timing::init();
    display::init();
    input::init();

    #ifndef DC_SIMULATOR
        display::driver.print("Hello, world! :)");
    #endif

    delay(3000);

    ui::currentScreen = testScreen;

    testScreen->print("Test screen ");
    testScreen->print(happyIcon);

    ui::renderCurrentScreen();

    delay(1000);
}

void loop() {
    long currentTick = timing::getCurrentTick();
    int difference = currentTick - lastTick;

    timeKeeper.incrementTime(difference);

    lastTick = currentTick;

    char timeString[17];

    if (displayMode == 0) {
        snprintf(timeString, 17, "%02d/%02d/%02d%02d:%02d:%02d",
            timeKeeper.day() % 100,
            timeKeeper.month() % 100,
            timeKeeper.year() % 100,
            timeKeeper.hour() % 100,
            timeKeeper.minute() % 100,
            timeKeeper.second() % 100
        );
    }

    if (displayMode == 1) {
        snprintf(timeString, 17, "%02d:%02d:%02d.%03d    ",
            timeKeeper.hour() % 100,
            timeKeeper.minute() % 100,
            timeKeeper.second() % 100,
            timeKeeper.millisecond()
        );
    }

    if (displayMode == 2) {
        snprintf(timeString, 17, "Battery %s %03d%%",
            power::isCharging() ? "chg" : "dsc",
            (int)round(power::getBatteryLevel())
        );
    }

    if (displayMode == 3) {
        snprintf(timeString, 17, "Battery %1.4f V",
            power::getBatteryVoltage()
        );
    }

    #ifdef DC_SIMULATOR
        Serial.println(timeString);

        displayMode++;

        if (displayMode == 4) {
            delay(1000);

            displayMode = 0;
        }
    #endif

    #ifndef DC_SIMULATOR
        switch (input::getButtonStatus()) {
            case input::Button::BACK: display::driver.print("Button      BACK"); break;
            case input::Button::HOME: display::driver.print("Button      HOME"); break;
            case input::Button::UP: display::driver.print("Button        UP"); break;
            case input::Button::DOWN: display::driver.print("Button      DOWN"); break;
            case input::Button::LEFT: display::driver.print("Button      LEFT"); break;
            case input::Button::RIGHT: display::driver.print("Button     RIGHT"); break;

            case input::Button::SELECT:
            {
                display::driver.print("Button    SELECT");

                displayMode++;

                if (displayMode > 3) {
                    displayMode = 0;
                }

                while (input::getButtonStatus() == input::Button::SELECT) {}
            }

            default: display::driver.print(timeString);
        }
    #endif
}

#ifdef DC_SIMULATOR

int main(int argc, char** argv) {
    setup();

    emscripten_set_main_loop(loop, 0, true);

    return 0;
}

#endif