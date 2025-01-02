#include <Arduino.h>

#include "mainmenu.h"
#include "proc.h"
#include "ui.h"
#include "input.h"

#include "app.wasm.h"

proc::Process mainMenu::mainMenuProcess;
mainMenu::MainMenuScreen mainMenu::mainMenuScreen;
mainMenu::AppsMenuScreen mainMenu::appsMenuScreen;

class TestPopup : public ui::Popup {
    proc::Process* ownerProcess = &mainMenu::mainMenuProcess;

    void update() {
        clear();
        print("Test\npopup!");
    }

    void handleEvent(ui::Event event) {
        if (event.type == ui::EventType::BUTTON_DOWN) {
            if (event.data.button == input::Button::BACK) {
                close();
            }
        }
    }
};

TestPopup testPopup;

mainMenu::MainMenuScreen::MainMenuScreen() : ui::Menu() {
    ownerProcess = &mainMenuProcess;

    items.push(new String("NOTIFS"));
    items.push(new String("APPS"));
    items.push(new String("CONFIG"));
    items.push(new String("REALLY LONG NAME"));
    items.push(new String("ANOTHER"));
    items.push(new String("ENDLESS"));
}

void mainMenu::MainMenuScreen::handleEvent(ui::Event event) {
    if (event.type == ui::EventType::ITEM_SELECT) {
        if (items[event.data.index]->equals("NOTIFS")) {
            testPopup.open(true);
        }

        if (items[event.data.index]->equals("APPS")) {
            mainMenu::appsMenuScreen.open();
        }
    }
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

void mainMenu::AppsMenuScreen::handleEvent(ui::Event event) {
    if (event.type == ui::EventType::ITEM_SELECT) {
        auto process = new proc::WasmProcess((char*)apptest_app_wasm, apptest_app_wasm_len);

        process->onStop = [](proc::Process* process) {
            delete process;

            Serial.println("WASM process deleted");
        };
    }
}