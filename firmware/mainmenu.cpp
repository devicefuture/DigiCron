#include <Arduino.h>

#include "mainmenu.h"
#include "proc.h"
#include "ui.h"

proc::Process mainMenu::mainMenuProcess;
mainMenu::MainMenuScreen mainMenu::mainMenuScreen;
mainMenu::AppsMenuScreen mainMenu::appsMenuScreen;

mainMenu::MainMenuScreen::MainMenuScreen() : ui::Menu() {
    ownerProcess = &mainMenuProcess;

    items.push(new String("NOTIFS"));
    items.push(new String("APPS"));
    items.push(new String("CONFIG"));
    items.push(new String("REALLY LONG NAME"));
    items.push(new String("ANOTHER"));
    items.push(new String("ENDLESS"));

    onSelect = [](ui::Menu* self, unsigned int selectedIndex) {
        if (*self->items[selectedIndex] == "APPS") {
            mainMenu::appsMenuScreen.open();
        }
    };
}

mainMenu::AppsMenuScreen::AppsMenuScreen() : ui::ContextualMenu("APPS") {
    ownerProcess = &mainMenuProcess;

    items.push(new String("Alarms"));
    items.push(new String("Timer"));
    items.push(new String("Stopwch"));
    items.push(new String("Counter"));
    items.push(new String("Fitness"));
    items.push(new String("atto"));
    items.push(new String("Calc"));
    items.push(new String("Cronogotchi"));
}