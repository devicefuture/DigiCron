#ifndef INPUT_H_
#define INPUT_H_

namespace input {
    enum Button {
        NONE = 0,
        BACK = 1,
        HOME = 2,
        UP = 3,
        DOWN = 4,
        LEFT = 5,
        RIGHT = 6,
        SELECT = 7
    };

    void init();
    Button getButtonStatus();
}

#endif