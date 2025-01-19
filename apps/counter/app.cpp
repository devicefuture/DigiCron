#include "../../applib/digicron.h"

#include "counterscreen.h"

using namespace dc;
using namespace dc::dataTypes;

CounterScreen* counterScreen;

void setup() {
    counterScreen = new CounterScreen();

    counterScreen->open(true);
}

void loop() {}