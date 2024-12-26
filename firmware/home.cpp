#include "home.h"
#include "proc.h"
#include "timing.h"
#include "power.h"
#include "ui.h"
#include "mainmenu.h"

ui::Icon* notificationsIcon = ui::constructIcon(
    "     "
    "  #  "
    " ### "
    " ### "
    " ### "
    "#####"
    "  #  "
);

ui::Icon* batteryIcon = ui::constructIcon(
    "  #  "
    " ### "
    " # # "
    " ### "
    " ### "
    " ### "
    " ### "
);

proc::Process home::homeProcess;
home::HomeScreen home::homeScreen;

#include <Arduino.h>

void home::HomeScreen::update() {
    if (_buttonIsDown) {
        return;
    }

    clear();

    switch (_mode) {
                case 0:
                {
                    printf("%02d:%02d:%02d",
                        timing::earthTime.hour() % 100,
                        timing::earthTime.minute() % 100,
                        timing::earthTime.second() % 100
                    );

                    print(notificationsIcon);
                    print("3     ");
                    print(batteryIcon);

                    break;
                }

                case 1:
                {
                    printf("%02d/%02d/%02d%02d:%02d:%02d",
                        timing::earthTime.day() % 100,
                        timing::earthTime.month() % 100,
                        timing::earthTime.year() % 100,
                        timing::earthTime.hour() % 100,
                        timing::earthTime.minute() % 100,
                        timing::earthTime.second() % 100
                    );

                    break;
                }

                case 2:
                {
                    printf("%02d:%02d:%02d.%03d",
                        timing::earthTime.hour() % 100,
                        timing::earthTime.minute() % 100,
                        timing::earthTime.second() % 100,
                        timing::earthTime.millisecond()
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

void home::HomeScreen::handleEvent(ui::Event event) {
    if (event.type == ui::EventType::BUTTON_UP) {
        _buttonIsDown = false;
    }

    if (event.type == ui::EventType::BUTTON_DOWN) {
        _buttonIsDown = true;

        clear();

        switch (event.data.button) {
            case input::Button::BACK: print("Button      BACK"); break;
            case input::Button::HOME: print("Button      HOME"); break;
            case input::Button::UP: print("Button        UP"); break;
            case input::Button::DOWN: print("Button      DOWN"); break;

            case input::Button::LEFT:
            {
                print("Button      LEFT");

                resetScroll();

                if (_mode == 0) {
                    _mode = 5;
                } else {
                    _mode--;
                }

                break;
            }

            case input::Button::RIGHT:
            {
                print("Button     RIGHT");

                resetScroll();

                _mode++;

                if (_mode > 5) {
                    _mode = 0;
                }

                break;
            }

            case input::Button::SELECT:
            {
                print("Button    SELECT");

                mainMenu::mainMenuScreen.open(true);

                break;
            }

            default: break;
        }
    }
}