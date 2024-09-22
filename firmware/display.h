#ifndef DISPLAY_H_
#define DISPLAY_H_

#ifndef DC_SIMULATOR
    #include "HCMS39xx.h"
#endif

#define DATA_PIN A0
#define RS_PIN A1
#define CLOCK_PIN A2
#define ENABLE_PIN A3
#define RESET_PIN A4

namespace display {
    const unsigned int CHAR_COLUMNS = 5;
    const unsigned int CHAR_ROWS = 7;
    const unsigned int COLUMNS = 8;
    const unsigned int ROWS = 2;
    const unsigned int WIDTH = COLUMNS * CHAR_COLUMNS;
    const unsigned int HEIGHT = ROWS * CHAR_ROWS;
    const unsigned int CHAR_COUNT = COLUMNS * ROWS;
    const unsigned int DATA_SIZE = CHAR_COLUMNS * CHAR_COUNT;

    #ifndef DC_SIMULATOR
        extern HCMS39xx driver;
    #endif

    void init();
    void render(char data[DATA_SIZE]);
}

#endif