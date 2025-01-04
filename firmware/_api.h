// Autogenerated by `tools/api/builder.sh` using declarations from `tools/api/api.sh`

#ifndef API_H_
#define API_H_

#include <wasm3.h>

#include "console.h"
#include "timing.h"
#include "input.h"
#include "ui.h"
#include "test.h"

namespace api {
    typedef int Sid;

    enum Type {EMPTY, timing_Time, timing_EarthTime, ui_Icon, ui_Screen, ui_Menu, ui_ContextualMenu, ui_Popup, test_TestClass, test_TestSubclass};

    struct StoredInstance {
        Type type;
        proc::Process* ownerProcess;
        void* instance;
    };

    extern dataTypes::List<StoredInstance> storedInstances;

    template<typename T> T* getBySid(Type type, Sid sid);
    Sid findOwnSid(void* instance);
    template<typename T> Sid store(Type type, proc::Process* ownerProcess, T* instance);
    void deleteBySid(Sid sid);
    void deleteAllByOwnerProcess(proc::Process* ownerProcess);

    m3ApiRawFunction(dc_getGlobalI32);
    m3ApiRawFunction(dc_deleteBySid);

    m3ApiRawFunction(dc_console_logString);
    m3ApiRawFunction(dc_timing_Time_new);
    m3ApiRawFunction(dc_timing_Time_newUsingDate);
    m3ApiRawFunction(dc_timing_Time_newUsingMilliseconds);
    m3ApiRawFunction(dc_timing_Time_daysInYear);
    m3ApiRawFunction(dc_timing_Time_daysInMonth);
    m3ApiRawFunction(dc_timing_Time_millisecondsInDay);
    m3ApiRawFunction(dc_timing_Time_inLeapMillisecond);
    m3ApiRawFunction(dc_timing_Time_postLeapMillisecondOffset);
    m3ApiRawFunction(dc_timing_Time_setDate);
    m3ApiRawFunction(dc_timing_Time_setTime);
    m3ApiRawFunction(dc_timing_Time_incrementTime);
    m3ApiRawFunction(dc_timing_Time_toLocalTime);
    m3ApiRawFunction(dc_timing_Time_toGlobalTime);
    m3ApiRawFunction(dc_timing_Time_timeShift);
    m3ApiRawFunction(dc_timing_Time_year);
    m3ApiRawFunction(dc_timing_Time_month);
    m3ApiRawFunction(dc_timing_Time_day);
    m3ApiRawFunction(dc_timing_Time_hour);
    m3ApiRawFunction(dc_timing_Time_minute);
    m3ApiRawFunction(dc_timing_Time_second);
    m3ApiRawFunction(dc_timing_Time_millisecond);
    m3ApiRawFunction(dc_timing_Time_dayOfYear);
    m3ApiRawFunction(dc_timing_Time_millisecondOfDay);
    m3ApiRawFunction(dc_timing_Time_millisecondOfDayIgnoringLeap);
    m3ApiRawFunction(dc_timing_Time_weekday);
    m3ApiRawFunction(dc_timing_EarthTime_new);
    m3ApiRawFunction(dc_timing_EarthTime_newUsingDate);
    m3ApiRawFunction(dc_timing_EarthTime_newUsingMilliseconds);
    m3ApiRawFunction(dc_timing_EarthTime_syncToSystemTime);
    m3ApiRawFunction(dc_timing_getCurrentTick);
    m3ApiRawFunction(dc_ui_Icon_new);
    m3ApiRawFunction(dc_ui_Icon_setPixel);
    m3ApiRawFunction(dc_ui_Screen_new);
    m3ApiRawFunction(dc_ui_Screen_clear);
    m3ApiRawFunction(dc_ui_Screen_setPosition);
    m3ApiRawFunction(dc_ui_Screen_setPixel);
    m3ApiRawFunction(dc_ui_Screen_printChar);
    m3ApiRawFunction(dc_ui_Screen_printChars);
    m3ApiRawFunction(dc_ui_Screen_print);
    m3ApiRawFunction(dc_ui_Screen_printIcon);
    m3ApiRawFunction(dc_ui_Screen_printRepeated);
    m3ApiRawFunction(dc_ui_Screen_scroll);
    m3ApiRawFunction(dc_ui_Screen_resetScroll);
    m3ApiRawFunction(dc_ui_Screen_rect);
    m3ApiRawFunction(dc_ui_Screen_filledRect);
    m3ApiRawFunction(dc_ui_Screen_open);
    m3ApiRawFunction(dc_ui_Screen_close);
    m3ApiRawFunction(dc_ui_Screen_swapWith);
    m3ApiRawFunction(dc_ui_Menu_new);
    m3ApiRawFunction(dc_ui_Menu_clearItems);
    m3ApiRawFunction(dc_ui_Menu_addItem);
    m3ApiRawFunction(dc_ui_ContextualMenu_new);
    m3ApiRawFunction(dc_ui_ContextualMenu_newWithTitle);
    m3ApiRawFunction(dc_ui_ContextualMenu_setTitle);
    m3ApiRawFunction(dc_ui_Popup_new);
    m3ApiRawFunction(dc_test_TestClass_new);
    m3ApiRawFunction(dc_test_TestClass_identify);
    m3ApiRawFunction(dc_test_TestClass_add);
    m3ApiRawFunction(dc_test_TestClass_bools);
    m3ApiRawFunction(dc_test_TestClass_nextRandomNumber);
    m3ApiRawFunction(dc_test_TestSubclass_new);
    m3ApiRawFunction(dc_test_TestSubclass_identify);
    m3ApiRawFunction(dc_test_TestSubclass_subclass);
    m3ApiRawFunction(dc_test_sayHello);
    m3ApiRawFunction(dc_test_add);

    void linkFunctions(IM3Runtime runtime);
}

#endif
