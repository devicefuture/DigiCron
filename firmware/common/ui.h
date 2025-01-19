#ifndef DC_COMMON_UI_H_
#define DC_COMMON_UI_H_

#ifndef ONCE
#define ONCE
#endif

#ifndef DIGICRON_H_
    #include "../datatypes.h"
    #include "../ui.h"
#endif

namespace ui {
    ONCE Icon* constructIcon(dataTypes::String pixels);
}

#endif