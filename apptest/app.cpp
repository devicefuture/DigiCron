// #include "api.h"
#include "../applib/digicron.h"

using namespace dc;

int count = 0;

test::TestClass* testClass;
ui::Screen* screen;

void setup() {
    dc_log((uint8_t*)"Hello from the WASM module!", 27);

    testClass = new test::TestClass(20);

    dc_log((uint8_t*)"Called test!", 12);

    if (testClass->add(456, 789) == 1245) {
        dc_log((uint8_t*)"Adding method works!", 20);
    }

    testClass->bools(true, false, true);

    screen = new ui::Screen();

    screen->open(true);
}

void loop() {
    if (count >= 10) {
        dc_stop();

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