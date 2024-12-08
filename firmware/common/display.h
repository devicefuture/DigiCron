#ifndef DC_COMMON_DISPLAY_H_
#define DC_COMMON_DISPLAY_H_

namespace display {
    const unsigned int CHAR_COLUMNS = 5;
    const unsigned int CHAR_ROWS = 7;
    const unsigned int COLUMNS = 8;
    const unsigned int ROWS = 2;
    const unsigned int WIDTH = COLUMNS * CHAR_COLUMNS;
    const unsigned int HEIGHT = ROWS * CHAR_ROWS;
    const unsigned int CHAR_COUNT = COLUMNS * ROWS;
    const unsigned int DATA_SIZE = CHAR_COLUMNS * CHAR_COUNT;
}

#endif