// #include "api.h"
#include "../applib/digicron.h"

using namespace dc;
using namespace dc::dataTypes;

int count = 0;

test::TestClass* testClass;
test::TestSubclass* testSubclass;
ui::Screen* screen;

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
                print("Pressed!");
                print('0' + ((updateCycles / 10) % 10));
                print('0' + (updateCycles % 10));
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

            if (event.type == ui::EventType::BUTTON_DOWN && event.data.button == input::Button::BACK) {
                dc_stop();
            }
        }

    private:
        bool _selectPressed = false;
        unsigned int updateCycles = 0;
};

void addr(unsigned int ptr) {
    uint8_t buffer[8];

    for (unsigned int i = 0; i < 8; i++) {
        unsigned int j = 7 - i;

        buffer[j] = '0' + (ptr % 10);
        ptr /= 10;
    }

    dc_log(buffer, 8);
}

void setup() {
    dc_log((uint8_t*)"Hello from the WASM module!", 27);

    dc_log((uint8_t*)"HB", 2);
    addr(dc_getGlobalI32("__heap_base"));

    dc_log((uint8_t*)"MS", 2);
    addr(__builtin_wasm_memory_size(0) << 16);

    test::sayHello();

    if (test::add(123, 456) == 579) {
        dc_log((uint8_t*)"Adding function works!", 22);
    }

    testClass = new test::TestClass(20);

    dc_log((uint8_t*)"Called test!", 12);

    if (testClass->add(456, 789) == 1245) {
        dc_log((uint8_t*)"Adding method works!", 20);
    }

    testClass->bools(true, false, true);

    testSubclass = new test::TestSubclass(10);

    testClass->identify();
    testSubclass->identify();
    testSubclass->subclass();

    screen = new HelloScreen();

    screen->open(true);
}

void loop() {
    if (count >= 10) {
        return;
    }

    unsigned int randomNumber = testClass->nextRandomNumber();

    uint8_t numberBuffer[5] = {'0', '0', '0', '0'};

    for (unsigned int i = 0; i < 4; i++) {
        unsigned int j = 3 - i;

        numberBuffer[j] = '0' + (randomNumber % 10);
        randomNumber /= 10;
    }

    dc_log(numberBuffer, 4);

    dc_log((uint8_t*)"Hello again!", 12);

    count++;
}