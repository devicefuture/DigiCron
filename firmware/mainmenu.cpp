#include <Arduino.h>

#include "mainmenu.h"
#include "proc.h"
#include "ui.h"

proc::Process mainMenu::mainMenuProcess;
mainMenu::MainMenuScreen mainMenu::mainMenuScreen;

mainMenu::MainMenuScreen::MainMenuScreen() : ui::Menu() {
    ownerProcess = &mainMenuProcess;

    items.push(new String("NOTIFS"));
    items.push(new String("APPS"));
    items.push(new String("CONFIG"));
    items.push(new String("REALLY LONG NAME"));
    items.push(new String("ANOTHER"));
    items.push(new String("ENDLESS"));
}