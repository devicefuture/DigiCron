// #include "api.h"
#include "../applib/digicron.h"

int count = 0;

void setup() {
    dc_log((uint8_t*)"Hello from the WASM module!", 27);

    auto test = new dc::test::TestClass(20);

    dc_log((uint8_t*)"Called test!", 12);
}

void loop() {
    if (count >= 10) {
        dc_stop();

        return;
    }

    dc_log((uint8_t*)"Hello again!", 12);

    count++;
}