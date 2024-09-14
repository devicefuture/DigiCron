#ifndef INPUT_H_
#define INPUT_H_

namespace input {
    enum Button {
        NONE,
        BACK,
        HOME,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SELECT
    };

    void init();
    Button getButtonStatus();
}

#endif