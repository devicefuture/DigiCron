#ifndef DC_COMMON_UI_H_
#define DC_COMMON_UI_H_

#ifndef DIGICRON_H_
    #include "../datatypes.h"
    #include "../ui.h"
#endif

namespace ui {
    Icon constructIcon(dataTypes::String pixels);
}

#endif