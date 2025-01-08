#include "../../applib/digicron.h"

using namespace dc;
using namespace dc::dataTypes;

int count = 0;

test::TestClass* testClass;
test::TestSubclass* testSubclass;
timing::EarthTime* currentTime;
ui::Screen* screen;
ui::Popup* popup;
ui::Menu* menu;

ui::Icon* smileIcon = ui::constructIcon(
    "     "
    " # # "
    "     "
    "#   #"
    " ### "
);

class HelloScreen : public ui::Screen {
    public:
        void update() {
            clear();

            if (_selectPressed) {
                int secs = currentTime->second();

                print("Pressed!");
                print('0' + ((updateCycles / 10) % 10));
                print('0' + (updateCycles % 10));
                print(" ");
                print('0' + ((secs / 10) % 10));
                print('0' + (secs % 10));
                print('s');
                print(" ");
            } else {
                print("Hello,\nworld! ");
            }

            print(smileIcon);

            updateCycles++;
        }

        void handleEvent(ui::Event event) {
            if (event.type == ui::EventType::BUTTON_UP && event.data.button == input::Button::SELECT) {
                _selectPressed = false;
            }

            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::SELECT) {
                _selectPressed = true;
            }

            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::UP) {
                popup->open(false);
            }

            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::DOWN) {
                menu->open(false);
            }

            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::BACK) {
                proc::stop();
            }
        }

    private:
        bool _selectPressed = false;
        unsigned int updateCycles = 0;
};

class HelloPopup : public ui::Popup {
    void update() {
        clear();

        print("THIS IS\nA TEST");
    }

    void handleEvent(ui::Event event) {
        if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::BACK) {
            close();
        }
    }
};

class ConfirmationPopup : public ui::Popup {
    public:
        String selectedItem = "None";

        void setSelectedItem(String item) {
            selectedItem = item;
        }

        void update() {
            print(selectedItem);
            print("\nselected");
        }

        void handleEvent(ui::Event event) {
            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::BACK) {
                close();
            }
        }
};

ConfirmationPopup* confirmationPopup;

class HelloMenu : public ui::ContextualMenu {
    public:
        HelloMenu() : ui::ContextualMenu() {
            setTitle("TESTOPTS");

            items.push(new String("Item 1"));
            items.push(new String("Item 2"));
            items.push(new String("Item 3"));

            updateItems();
        }

        void handleEvent(ui::Event event) {
            if (event.type == ui::EventType::ITEM_SELECT) {
                confirmationPopup->setSelectedItem(*(items[event.data.index]));

                confirmationPopup->open(false);
            }
        }
};

void setup() {
    console::log("Hello from the WASM module!");
    console::log("Demo int:", 123, "float:", 456.789, "ptr:", (void*)smileIcon);

    console::log("Heap base:", (void*)dc_getGlobalI32("__heap_base"));
    console::log("Memory size:", __builtin_wasm_memory_size(0) << 16);

    test::sayHello();

    if (test::add(123, 456) == 579) {
        console::log("Adding function works!");
    }

    testClass = new test::TestClass(20);

    console::log("Called test!");

    if (testClass->add(456, 789) == 1245) {
        console::log("Adding method works!");
    }

    testClass->bools(true, false, true);

    testSubclass = new test::TestSubclass(10);

    testClass->identify();
    testSubclass->identify();
    testSubclass->subclass();

    currentTime = new timing::EarthTime();

    screen = new HelloScreen();
    popup = new HelloPopup();
    menu = new HelloMenu();
    confirmationPopup = new ConfirmationPopup();

    screen->open(true);
}

void loop() {
    currentTime->syncToSystemTime();

    if (count >= 10) {
        return;
    }

    unsigned int randomNumber = testClass->nextRandomNumber();

    console::log("Received random number:", randomNumber);

    console::log("Hello again!");

    count++;
}