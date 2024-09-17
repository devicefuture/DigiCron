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

#define BACK_BTN_PIN 6
#define HOME_BTN_PIN 5
#define JOY_UP_PIN 10
#define JOY_DOWN_PIN 12
#define JOY_LEFT_PIN 9
#define JOY_RIGHT_PIN 11
#define JOY_SELECT_PIN 13

timing::EarthTime timeKeeper(2024, 1, 1, 12, 0, 0);

ui::Screen* testScreen = new ui::Screen();

ui::Icon tmIcon = ui::constructIcon(
    "###  "
    " #   "
    "     "
    "## ##"
    "# # #"
);

ui::Icon notificationsIcon = ui::constructIcon(
    "     "
    "  #  "
    " ### "
    " ### "
    " ### "
    "#####"
    "  #  "
);

ui::Icon batteryIcon = ui::constructIcon(
    "  #  "
    " ### "
    " # # "
    " ### "
    " ### "
    " ### "
    " ### "
);

dataTypes::List<String> mainMenuItems;
ui::Menu* mainMenu = new ui::Menu(mainMenuItems);

class MainScreen : public ui::Screen {
    public:
        unsigned int mode = 0;
        bool buttonIsDown = false;

        MainScreen() : Screen() {}

        void update() override {
            if (buttonIsDown) {
                return;
            }

            clear();

            switch (mode) {
                case 0:
                {
                    printf("%02d:%02d:%02d",
                        timeKeeper.hour() % 100,
                        timeKeeper.minute() % 100,
                        timeKeeper.second() % 100
                    );

                    print(notificationsIcon);
                    print("3     ");
                    print(batteryIcon);

                    break;
                }

                case 1:
                {
                    printf("%02d/%02d/%02d%02d:%02d:%02d",
                        timeKeeper.day() % 100,
                        timeKeeper.month() % 100,
                        timeKeeper.year() % 100,
                        timeKeeper.hour() % 100,
                        timeKeeper.minute() % 100,
                        timeKeeper.second() % 100
                    );

                    break;
                }

                case 2:
                {
                    printf("%02d:%02d:%02d.%03d",
                        timeKeeper.hour() % 100,
                        timeKeeper.minute() % 100,
                        timeKeeper.second() % 100,
                        timeKeeper.millisecond()
                    );

                    break;
                }

                case 3:
                {
                    printf("Battery %s %03d%%",
                        power::isCharging() ? "chg" : "dsc",
                        (int)round(power::getBatteryLevel())
                    );

                    break;
                }

                case 4:
                {
                    printf("Battery %1.4f V",
                        power::getBatteryVoltage()
                    );

                    break;
                }

                case 5:
                {
                    print("NOTICE\n");
                    scroll("This is a demo of using the scrolling feature!");

                    break;
                }
            }
        }

        void handleEvent(ui::Event event) override {
            if (event.type == ui::EventType::BUTTON_DOWN) {
                buttonIsDown = true;

                clear();

                switch (event.data.button) {
                    case input::Button::BACK: print("Button      BACK"); break;
                    case input::Button::HOME: print("Button      HOME"); break;
                    case input::Button::UP: print("Button        UP"); break;
                    case input::Button::DOWN: print("Button      DOWN"); break;
                    case input::Button::LEFT: print("Button      LEFT"); break;
                    case input::Button::RIGHT: print("Button     RIGHT"); break;

                    case input::Button::SELECT:
                    {
                        print("Button    SELECT");

                        resetScroll();

                        mode++;

                        if (mode > 5) {
                            mode = 0;
                        }

                        break;
                    }

                    default: break;
                }
            }

            if (event.type == ui::EventType::BUTTON_UP) {
                buttonIsDown = false;

                if (event.data.button == input::Button::HOME) {
                    ui::currentScreen = mainMenu;
                }
            }
        }
};

ui::Screen* mainScreen = new MainScreen();

unsigned int displayMode = 0;
long lastTick = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");

    mainMenu->items.push(new String("NOTIFS"));
    mainMenu->items.push(new String("APPS"));
    mainMenu->items.push(new String("CONFIG"));
    mainMenu->items.push(new String("REALLY LONG NAME"));
    mainMenu->items.push(new String("ANOTHER"));
    mainMenu->items.push(new String("ENDLESS"));

    mainMenu->onCancel = []() {
        ui::currentScreen = mainScreen;
    };

    mainMenu->onSelect = [](unsigned int selectedIndex) {
        ui::currentScreen = mainScreen;
    };

    timing::init();
    display::init();
    input::init();

    ui::currentScreen = testScreen;

    testScreen->print(" device  future");
    testScreen->print(tmIcon);
}

void loop() {
    long currentTick = timing::getCurrentTick();
    int difference = currentTick - lastTick;

    timeKeeper.incrementTime(difference);

    lastTick = currentTick;

    if (ui::currentScreen == testScreen && millis() > 3000) {
        ui::currentScreen = mainScreen;
    }

    ui::renderCurrentScreen();
}

#ifdef DC_SIMULATOR

int main(int argc, char** argv) {
    setup();

    emscripten_set_main_loop(loop, 0, true);

    return 0;
}

#endif