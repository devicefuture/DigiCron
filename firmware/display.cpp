#include "display.h"

#ifndef DC_SIMULATOR
HCMS39xx display::driver(16, DATA_PIN, RS_PIN, CLOCK_PIN, ENABLE_PIN);
#endif

void display::init() {
    #ifndef DC_SIMULATOR
        driver.begin();
        driver.clear();
        driver.displayUnblank();
        driver.setBrightness(7);
    #endif
}

void display::render(char data[display::DATA_SIZE]) {
    #ifndef DC_SIMULATOR
        driver.printDirect((uint8_t*)data, display::DATA_SIZE);
    #endif
}