// Autogenerated by `tools/api/builder.sh` using declarations from `tools/api/api.sh`

#include <Arduino.h>
#include <m3_env.h>

#include "_api.h"
#include "proc.h"
#include "datatypes.h"
#include "timing.h"
#include "ui.h"
#include "test.h"

dataTypes::List<api::StoredInstance> api::storedInstances;

template<typename T> T* api::getBySid(api::Type type, api::Sid sid) {
    StoredInstance* storedInstance = api::storedInstances[sid];

    if (!storedInstance || storedInstance->type != type) {
        return new T(); // To ensure an object is always referenced
    }

    return (T*)storedInstance->instance;
}

template<typename T> api::Sid api::store(api::Type type, T* instance) {
    auto storedInstance = new StoredInstance();

    storedInstance->type = type;
    storedInstance->instance = instance;

    return api::storedInstances.push(storedInstance) - 1;
}

m3ApiRawFunction(api::dc_timing_EarthTime_new) {
    m3ApiReturnType(Sid)
    m3ApiGetArg(int, year)
    m3ApiGetArg(unsigned int, month)
    m3ApiGetArg(unsigned int, day)
    m3ApiGetArg(unsigned int, hour)
    m3ApiGetArg(unsigned int, minute)
    m3ApiGetArg(unsigned int, second)

    auto instance = new timing::EarthTime(year, month, day, hour, minute, second);

    Sid result = api::store<timing::EarthTime>(Type::timing_EarthTime, instance);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_newUsingMilliseconds) {
    m3ApiReturnType(Sid)
    m3ApiGetArg(int, year)
    m3ApiGetArg(unsigned int, month)
    m3ApiGetArg(unsigned int, day)
    m3ApiGetArg(unsigned long, millisecondOfDay)

    auto instance = new timing::EarthTime(year, month, day, millisecondOfDay);

    Sid result = api::store<timing::EarthTime>(Type::timing_EarthTime, instance);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_daysInYear) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->daysInYear();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_daysInMonth) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, month)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->daysInMonth(month);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_millisecondsInDay) {
    m3ApiReturnType(unsigned long)
    m3ApiGetArg(Sid, _sid)

    unsigned long result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->millisecondsInDay();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_inLeapMillisecond) {
    m3ApiReturnType(bool)
    m3ApiGetArg(Sid, _sid)

    bool result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->inLeapMillisecond();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_postLeapMillisecondOffset) {
    m3ApiReturnType(unsigned long)
    m3ApiGetArg(Sid, _sid)

    unsigned long result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->postLeapMillisecondOffset();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_setDate) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(int, year)
    m3ApiGetArg(unsigned int, month)
    m3ApiGetArg(unsigned int, day)

    api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->setDate(year, month, day);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_timing_EarthTime_setTime) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, hour)
    m3ApiGetArg(unsigned int, minute)
    m3ApiGetArg(unsigned int, second)

    api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->setTime(hour, minute, second);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_timing_EarthTime_incrementTime) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(int, millseconds)

    api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->incrementTime(millseconds);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_timing_EarthTime_toLocalTime) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(int, timeShift)

    api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->toLocalTime(timeShift);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_timing_EarthTime_toGlobalTime) {
    m3ApiGetArg(Sid, _sid)

    api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->toGlobalTime();

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_timing_EarthTime_year) {
    m3ApiReturnType(int)
    m3ApiGetArg(Sid, _sid)

    int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->year();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_month) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->month();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_day) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->day();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_hour) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->hour();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_minute) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->minute();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_second) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->second();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_millisecond) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->millisecond();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_dayOfYear) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->dayOfYear();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_millisecondOfDay) {
    m3ApiReturnType(unsigned long)
    m3ApiGetArg(Sid, _sid)

    unsigned long result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->millisecondOfDay();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_millisecondOfDayIgnoringLeap) {
    m3ApiReturnType(unsigned long)
    m3ApiGetArg(Sid, _sid)

    unsigned long result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->millisecondOfDayIgnoringLeap();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_timing_EarthTime_weekday) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<timing::EarthTime>(Type::timing_EarthTime, _sid)->weekday();

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_ui_Icon_new) {
    m3ApiReturnType(Sid)

    auto instance = new ui::Icon();

    Sid result = api::store<ui::Icon>(Type::ui_Icon, instance);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_ui_Icon_setPixel) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, x)
    m3ApiGetArg(unsigned int, y)
    m3ApiGetArg(unsigned int, value)

    api::getBySid<ui::Icon>(Type::ui_Icon, _sid)->setPixel(x, y, (ui::PenMode)value);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_new) {
    m3ApiReturnType(Sid)

    auto instance = new ui::Screen((proc::WasmProcess*)runtime->userdata);

    Sid result = api::store<ui::Screen>(Type::ui_Screen, instance);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_ui_Screen_clear) {
    m3ApiGetArg(Sid, _sid)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->clear();

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_setPosition) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, column)
    m3ApiGetArg(unsigned int, row)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->setPosition(column, row);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_setPixel) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, x)
    m3ApiGetArg(unsigned int, y)
    m3ApiGetArg(unsigned int, value)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->setPixel(x, y, (ui::PenMode)value);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_printName) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(char, c)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->print(c);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_print) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArgMem(char*, chars)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->print(chars);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_printIcon) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(Sid, icon)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->print(*api::getBySid<ui::Icon>(Type::ui_Screen, icon));

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_printRepeated) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArgMem(char*, string)
    m3ApiGetArg(unsigned int, times)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->printRepeated(String(string), times);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_scroll) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArgMem(char*, string)
    m3ApiGetArg(unsigned int, maxLength)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->scroll(String(string), maxLength);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_resetScroll) {
    m3ApiGetArg(Sid, _sid)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->resetScroll();

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_rect) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, x1)
    m3ApiGetArg(unsigned int, y1)
    m3ApiGetArg(unsigned int, x2)
    m3ApiGetArg(unsigned int, y2)
    m3ApiGetArg(unsigned int, value)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->rect(x1, y1, x2, y2, (ui::PenMode)value);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_filledRect) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, x1)
    m3ApiGetArg(unsigned int, y1)
    m3ApiGetArg(unsigned int, x2)
    m3ApiGetArg(unsigned int, y2)
    m3ApiGetArg(unsigned int, value)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->filledRect(x1, y1, x2, y2, (ui::PenMode)value);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_open) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(bool, urgent)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->open(urgent);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_close) {
    m3ApiGetArg(Sid, _sid)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->close();

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_ui_Screen_swapWith) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(Sid, currentScreen)

    api::getBySid<ui::Screen>(Type::ui_Screen, _sid)->swapWith(api::getBySid<ui::Screen>(Type::ui_Screen, currentScreen));

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_test_TestClass_new) {
    m3ApiReturnType(Sid)
    m3ApiGetArg(unsigned int, seed)

    auto instance = new test::TestClass(seed);

    Sid result = api::store<test::TestClass>(Type::test_TestClass, instance);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_test_TestClass_add) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(unsigned int, value)
    m3ApiGetArg(unsigned int, value2)

    unsigned int result = api::getBySid<test::TestClass>(Type::test_TestClass, _sid)->add(value, value2);

    m3ApiReturn(result);
}

m3ApiRawFunction(api::dc_test_TestClass_bools) {
    m3ApiGetArg(Sid, _sid)
    m3ApiGetArg(bool, a)
    m3ApiGetArg(bool, b)
    m3ApiGetArg(bool, c)

    api::getBySid<test::TestClass>(Type::test_TestClass, _sid)->bools(a, b, c);

    m3ApiSuccess();
}

m3ApiRawFunction(api::dc_test_TestClass_nextRandomNumber) {
    m3ApiReturnType(unsigned int)
    m3ApiGetArg(Sid, _sid)

    unsigned int result = api::getBySid<test::TestClass>(Type::test_TestClass, _sid)->nextRandomNumber();

    m3ApiReturn(result);
}

void api::linkFunctions(IM3Runtime runtime) {
    const char* MODULE_NAME = "digicron";

    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_new", "i(iiiiii)", &dc_timing_EarthTime_new);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_newUsingMilliseconds", "i(iiii)", &dc_timing_EarthTime_newUsingMilliseconds);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_daysInYear", "i(i)", &dc_timing_EarthTime_daysInYear);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_daysInMonth", "i(ii)", &dc_timing_EarthTime_daysInMonth);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_millisecondsInDay", "i(i)", &dc_timing_EarthTime_millisecondsInDay);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_inLeapMillisecond", "i(i)", &dc_timing_EarthTime_inLeapMillisecond);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_postLeapMillisecondOffset", "i(i)", &dc_timing_EarthTime_postLeapMillisecondOffset);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_setDate", "v(iiii)", &dc_timing_EarthTime_setDate);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_setTime", "v(iiii)", &dc_timing_EarthTime_setTime);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_incrementTime", "v(ii)", &dc_timing_EarthTime_incrementTime);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_toLocalTime", "v(ii)", &dc_timing_EarthTime_toLocalTime);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_toGlobalTime", "v(i)", &dc_timing_EarthTime_toGlobalTime);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_year", "i(i)", &dc_timing_EarthTime_year);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_month", "i(i)", &dc_timing_EarthTime_month);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_day", "i(i)", &dc_timing_EarthTime_day);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_hour", "i(i)", &dc_timing_EarthTime_hour);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_minute", "i(i)", &dc_timing_EarthTime_minute);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_second", "i(i)", &dc_timing_EarthTime_second);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_millisecond", "i(i)", &dc_timing_EarthTime_millisecond);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_dayOfYear", "i(i)", &dc_timing_EarthTime_dayOfYear);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_millisecondOfDay", "i(i)", &dc_timing_EarthTime_millisecondOfDay);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_millisecondOfDayIgnoringLeap", "i(i)", &dc_timing_EarthTime_millisecondOfDayIgnoringLeap);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_timing_EarthTime_weekday", "i(i)", &dc_timing_EarthTime_weekday);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Icon_new", "i()", &dc_ui_Icon_new);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Icon_setPixel", "v(iiii)", &dc_ui_Icon_setPixel);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_new", "i()", &dc_ui_Screen_new);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_clear", "v(i)", &dc_ui_Screen_clear);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_setPosition", "v(iii)", &dc_ui_Screen_setPosition);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_setPixel", "v(iiii)", &dc_ui_Screen_setPixel);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_printName", "v(ii)", &dc_ui_Screen_printName);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_print", "v(i*)", &dc_ui_Screen_print);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_printIcon", "v(ii)", &dc_ui_Screen_printIcon);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_printRepeated", "v(iii)", &dc_ui_Screen_printRepeated);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_scroll", "v(iii)", &dc_ui_Screen_scroll);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_resetScroll", "v(i)", &dc_ui_Screen_resetScroll);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_rect", "v(iiiiii)", &dc_ui_Screen_rect);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_filledRect", "v(iiiiii)", &dc_ui_Screen_filledRect);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_open", "v(ii)", &dc_ui_Screen_open);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_close", "v(i)", &dc_ui_Screen_close);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_ui_Screen_swapWith", "v(ii)", &dc_ui_Screen_swapWith);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_test_TestClass_new", "i(i)", &dc_test_TestClass_new);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_test_TestClass_add", "i(iii)", &dc_test_TestClass_add);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_test_TestClass_bools", "v(iiii)", &dc_test_TestClass_bools);
    m3_LinkRawFunction(runtime->modules, MODULE_NAME, "dc_test_TestClass_nextRandomNumber", "i(i)", &dc_test_TestClass_nextRandomNumber);
}
