#include "counterscreen.h"

void CounterScreen::update() {
    clear();

    print("Counter\n");
    pad(8, ' ');
    print("0");
}

void CounterScreen::handleEvent(ui::Event event) {

}