#ifndef DC_COMMON_UI_CPP_
#define DC_COMMON_UI_CPP_

#ifndef DIGICRON_H_
    #include "ui.h"
#endif

ui::Icon* ui::constructIcon(dataTypes::String pixels) {
    auto icon = new Icon();

    for (unsigned int i = 0; i < pixels.length(); i++) {
        unsigned int x = i % display::CHAR_COLUMNS;
        unsigned int y = i / display::CHAR_COLUMNS;

        if (y >= 8) {
            break;
        }

        icon->setPixel(x, y, pixels[i] != ' ' ? PenMode::ON : PenMode::OFF);
    }

    return icon;
}

#endif