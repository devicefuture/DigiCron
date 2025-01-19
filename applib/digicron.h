// Autogenerated by `tools/api/builder.sh` using declarations from `tools/api/api.sh`

#ifndef DIGICRON_H_
#define DIGICRON_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

#define ONCE inline

namespace dc {
    typedef unsigned int _Enum;
    typedef int _Sid;
    typedef struct {} _Dummy;
}

void setup();
void loop();

extern "C" {

WASM_IMPORT("digicron", "dc_getGlobalI32") uint32_t dc_getGlobalI32(const char* id);
WASM_IMPORT("digicron", "dc_deleteBySid") void dc_deleteBySid(dc::_Sid sid);

WASM_IMPORT("digicron", "dc_proc_stop") void dc_proc_stop();
WASM_IMPORT("digicron", "dc_console_logPart") void dc_console_logPart(char* value);
WASM_IMPORT("digicron", "dc_console_logPartChars") void dc_console_logPartChars(char* value);
WASM_IMPORT("digicron", "dc_console_logPartUInt") void dc_console_logPartUInt(unsigned int value);
WASM_IMPORT("digicron", "dc_console_logPartInt") void dc_console_logPartInt(int value);
WASM_IMPORT("digicron", "dc_console_logPartULong") void dc_console_logPartULong(unsigned long value);
WASM_IMPORT("digicron", "dc_console_logPartLong") void dc_console_logPartLong(long value);
WASM_IMPORT("digicron", "dc_console_logPartDouble") void dc_console_logPartDouble(double value);
WASM_IMPORT("digicron", "dc_console_logPartPtr") void dc_console_logPartPtr(void* value);
WASM_IMPORT("digicron", "dc_console_logNewline") void dc_console_logNewline();
WASM_IMPORT("digicron", "dc_timing_Time_new") dc::_Sid dc_timing_Time_new();
WASM_IMPORT("digicron", "dc_timing_Time_newUsingDate") dc::_Sid dc_timing_Time_newUsingDate(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second);
WASM_IMPORT("digicron", "dc_timing_Time_newUsingMilliseconds") dc::_Sid dc_timing_Time_newUsingMilliseconds(int year, unsigned int month, unsigned int day, unsigned long millisecondOfDay);
WASM_IMPORT("digicron", "dc_timing_Time_daysInYear") unsigned int dc_timing_Time_daysInYear(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_daysInMonth") unsigned int dc_timing_Time_daysInMonth(dc::_Sid sid, unsigned int month);
WASM_IMPORT("digicron", "dc_timing_Time_millisecondsInDay") unsigned long dc_timing_Time_millisecondsInDay(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_inLeapMillisecond") bool dc_timing_Time_inLeapMillisecond(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_postLeapMillisecondOffset") unsigned long dc_timing_Time_postLeapMillisecondOffset(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_setDate") void dc_timing_Time_setDate(dc::_Sid sid, int year, unsigned int month, unsigned int day);
WASM_IMPORT("digicron", "dc_timing_Time_setTime") void dc_timing_Time_setTime(dc::_Sid sid, unsigned int hour, unsigned int minute, unsigned int second);
WASM_IMPORT("digicron", "dc_timing_Time_incrementTime") void dc_timing_Time_incrementTime(dc::_Sid sid, int millseconds);
WASM_IMPORT("digicron", "dc_timing_Time_toLocalTime") void dc_timing_Time_toLocalTime(dc::_Sid sid, int timeShift);
WASM_IMPORT("digicron", "dc_timing_Time_toGlobalTime") void dc_timing_Time_toGlobalTime(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_timeShift") int dc_timing_Time_timeShift(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_year") int dc_timing_Time_year(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_month") unsigned int dc_timing_Time_month(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_day") unsigned int dc_timing_Time_day(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_hour") unsigned int dc_timing_Time_hour(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_minute") unsigned int dc_timing_Time_minute(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_second") unsigned int dc_timing_Time_second(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_millisecond") unsigned int dc_timing_Time_millisecond(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_dayOfYear") unsigned int dc_timing_Time_dayOfYear(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_millisecondOfDay") unsigned long dc_timing_Time_millisecondOfDay(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_millisecondOfDayIgnoringLeap") unsigned long dc_timing_Time_millisecondOfDayIgnoringLeap(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_Time_weekday") unsigned int dc_timing_Time_weekday(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_EarthTime_new") dc::_Sid dc_timing_EarthTime_new();
WASM_IMPORT("digicron", "dc_timing_EarthTime_newUsingDate") dc::_Sid dc_timing_EarthTime_newUsingDate(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second);
WASM_IMPORT("digicron", "dc_timing_EarthTime_newUsingMilliseconds") dc::_Sid dc_timing_EarthTime_newUsingMilliseconds(int year, unsigned int month, unsigned int day, unsigned long millisecondOfDay);
WASM_IMPORT("digicron", "dc_timing_EarthTime_syncToSystemTime") void dc_timing_EarthTime_syncToSystemTime(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_timing_getCurrentTick") unsigned long dc_timing_getCurrentTick();
WASM_IMPORT("digicron", "dc_ui_Icon_new") dc::_Sid dc_ui_Icon_new();
WASM_IMPORT("digicron", "dc_ui_Icon_setPixel") void dc_ui_Icon_setPixel(dc::_Sid sid, unsigned int x, unsigned int y, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_new") dc::_Sid dc_ui_Screen_new();
WASM_IMPORT("digicron", "dc_ui_Screen_clear") void dc_ui_Screen_clear(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Screen_setPosition") void dc_ui_Screen_setPosition(dc::_Sid sid, unsigned int column, unsigned int row);
WASM_IMPORT("digicron", "dc_ui_Screen_setPixel") void dc_ui_Screen_setPixel(dc::_Sid sid, unsigned int x, unsigned int y, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_printChar") void dc_ui_Screen_printChar(dc::_Sid sid, char c);
WASM_IMPORT("digicron", "dc_ui_Screen_print") void dc_ui_Screen_print(dc::_Sid sid, char* string);
WASM_IMPORT("digicron", "dc_ui_Screen_printChars") void dc_ui_Screen_printChars(dc::_Sid sid, char* chars);
WASM_IMPORT("digicron", "dc_ui_Screen_printUInt") void dc_ui_Screen_printUInt(dc::_Sid sid, unsigned int value);
WASM_IMPORT("digicron", "dc_ui_Screen_printInt") void dc_ui_Screen_printInt(dc::_Sid sid, int value);
WASM_IMPORT("digicron", "dc_ui_Screen_printULong") void dc_ui_Screen_printULong(dc::_Sid sid, unsigned long value);
WASM_IMPORT("digicron", "dc_ui_Screen_printLong") void dc_ui_Screen_printLong(dc::_Sid sid, long value);
WASM_IMPORT("digicron", "dc_ui_Screen_printDouble") void dc_ui_Screen_printDouble(dc::_Sid sid, double value);
WASM_IMPORT("digicron", "dc_ui_Screen_printIcon") void dc_ui_Screen_printIcon(dc::_Sid sid, dc::_Sid icon);
WASM_IMPORT("digicron", "dc_ui_Screen_printRepeated") void dc_ui_Screen_printRepeated(dc::_Sid sid, char* string, unsigned int times);
WASM_IMPORT("digicron", "dc_ui_Screen_scroll") void dc_ui_Screen_scroll(dc::_Sid sid, char* string, unsigned int maxLength);
WASM_IMPORT("digicron", "dc_ui_Screen_resetScroll") void dc_ui_Screen_resetScroll(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Screen_pad") void dc_ui_Screen_pad(dc::_Sid sid, unsigned int size, char c);
WASM_IMPORT("digicron", "dc_ui_Screen_rect") void dc_ui_Screen_rect(dc::_Sid sid, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_filledRect") void dc_ui_Screen_filledRect(dc::_Sid sid, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_open") void dc_ui_Screen_open(dc::_Sid sid, bool urgent);
WASM_IMPORT("digicron", "dc_ui_Screen_close") void dc_ui_Screen_close(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Screen_swapWith") void dc_ui_Screen_swapWith(dc::_Sid sid, dc::_Sid currentScreen);
WASM_IMPORT("digicron", "dc_ui_Menu_new") dc::_Sid dc_ui_Menu_new();
WASM_IMPORT("digicron", "dc_ui_Menu_clearItems") void dc_ui_Menu_clearItems(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Menu_addItem") void dc_ui_Menu_addItem(dc::_Sid sid, char* item);
WASM_IMPORT("digicron", "dc_ui_ContextualMenu_new") dc::_Sid dc_ui_ContextualMenu_new();
WASM_IMPORT("digicron", "dc_ui_ContextualMenu_newWithTitle") dc::_Sid dc_ui_ContextualMenu_newWithTitle(char* title);
WASM_IMPORT("digicron", "dc_ui_ContextualMenu_setTitle") void dc_ui_ContextualMenu_setTitle(dc::_Sid sid, char* title);
WASM_IMPORT("digicron", "dc_ui_Popup_new") dc::_Sid dc_ui_Popup_new();
WASM_IMPORT("digicron", "dc_test_TestClass_new") dc::_Sid dc_test_TestClass_new(unsigned int seed);
WASM_IMPORT("digicron", "dc_test_TestClass_identify") void dc_test_TestClass_identify(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_test_TestClass_add") unsigned int dc_test_TestClass_add(dc::_Sid sid, unsigned int value, unsigned int value2);
WASM_IMPORT("digicron", "dc_test_TestClass_bools") void dc_test_TestClass_bools(dc::_Sid sid, bool a, bool b, bool c);
WASM_IMPORT("digicron", "dc_test_TestClass_nextRandomNumber") unsigned int dc_test_TestClass_nextRandomNumber(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_test_TestSubclass_new") dc::_Sid dc_test_TestSubclass_new(unsigned int seed);
WASM_IMPORT("digicron", "dc_test_TestSubclass_identify") void dc_test_TestSubclass_identify(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_test_TestSubclass_subclass") void dc_test_TestSubclass_subclass(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_test_sayHello") void dc_test_sayHello();
WASM_IMPORT("digicron", "dc_test_add") int dc_test_add(int a, int b);

}

typedef unsigned long size_t;

namespace dc::heap {
    typedef size_t Block;

    extern const Block* base;
    extern Block* firstFreeBlock;
}

extern "C" {
    void* memset(void* destination, char value, size_t size);
    void* memcpy(void* destination, void* source, size_t size);
    void* malloc(size_t size);
    void free(void* ptr);
    void* calloc(size_t count, size_t size);
    void* realloc(void* ptr, size_t size);
}

void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* ptr);
void operator delete(void* ptr, size_t size);
void operator delete[](void* ptr);
void operator delete[](void* ptr, size_t size);

extern "C" int __cxa_atexit(void (*function)(void*), void* argument, void* handle);

namespace dc {

#ifndef DC_COMMON_DATATYPES_H_
#define DC_COMMON_DATATYPES_H_

#ifndef DIGICRON_H_
    #include <Arduino.h>
#endif

template<typename T> T* store(T value);
template<typename T> T discard(T* itemPtr);

namespace dataTypes {
    template<typename T> struct _ListItem {
        T* valuePtr;
        _ListItem<T>* nextItemPtr;
    };

    template<typename T> class StoredValue {
        public:
            T value;

            StoredValue<T>(T valueToStore);
            ~StoredValue<T>();
    };

    #ifdef DIGICRON_H_
        class String {
            private:
                char* _value = nullptr;
                unsigned int _length = 0;

            public:
                String(const char* value);
                String(const String& other);
                ~String();

                String& operator=(const String& other);
                char operator[](int index);

                char* c_str() const;
                unsigned int length() const;
                char charAt(int index);
        };
    #else
        typedef String String;
    #endif

    template<typename T> class List {
        public:
            typedef _ListItem<T>* Iterator;

            typedef void (*IterationCallback)(T* itemPtr, unsigned int index);
            typedef T* (*MappingFunction)(T* itemPtr, unsigned int index);
            typedef bool (*FilteringFunction)(T* itemPtr, unsigned int index);

            List<T>();
            ~List<T>();

            T* operator[](int index);

            void start(Iterator* iterator = nullptr);
            T* next(Iterator* iterator = nullptr);
            unsigned int length();
            void empty();
            unsigned int push(T* valuePtr);
            T* pop();
            unsigned int unshift(T* valuePtr);
            T* shift();
            unsigned int insert(unsigned int index, T* valuePtr);
            T* remove(unsigned int index);
            void set(unsigned int index, T* valuePtr);
            int indexOf(T* valuePtr);
            void forEach(IterationCallback iterationCallback);
            List<T> map(MappingFunction mappingFunction);
            List<T> filter(FilteringFunction filteringFunction);
            List<T> concat(List<T> otherList);

        private:
            _ListItem<T>* _firstItemPtr;
            Iterator _defaultIterator;
            unsigned int _length;

            _ListItem<T>* getItemAtIndex(int index);
            _ListItem<T>* getLastItem();
    };
}

#endif

enum _Type {EMPTY, timing_Time, timing_EarthTime, ui_Icon, ui_Screen, ui_Menu, ui_ContextualMenu, ui_Popup, test_TestClass, test_TestSubclass};

struct _StoredInstance {
    _Type type;
    void* instance;
};

inline dataTypes::List<_StoredInstance> _storedInstances;

template<typename T> T* _getBySid(_Type type, _Sid sid) {
    _storedInstances.start();

    while (_StoredInstance* storedInstance = _storedInstances.next()) {
        if (storedInstance->type != type && !(
            (type == _Type::timing_Time && storedInstance->type == _Type::timing_EarthTime) ||
            (type == _Type::ui_Screen && storedInstance->type == _Type::ui_Menu) ||
            (type == _Type::ui_Menu && storedInstance->type == _Type::ui_ContextualMenu) ||
            (type == _Type::ui_Screen && storedInstance->type == _Type::ui_ContextualMenu) ||
            (type == _Type::ui_Screen && storedInstance->type == _Type::ui_Popup) ||
            (type == _Type::test_TestClass && storedInstance->type == _Type::test_TestSubclass) ||
            false
        )) {
            continue;
        }

        T* castedInstance = (T*)(storedInstance->instance);

        if (castedInstance->_getSid() == sid) {
            return castedInstance;
        }
    }

    return nullptr;
}

inline void _addStoredInstance(_Type type, void* instance) {
    auto storedInstance = new _StoredInstance {
        .type = type,
        .instance = instance
    };

    _storedInstances.push(storedInstance);
}

inline void _removeStoredInstance(void* instance) {
    _storedInstances.start();

    unsigned int index = 0;

    while (_StoredInstance* storedInstance = _storedInstances.next()) {
        if (storedInstance->instance == instance) {
            delete _storedInstances.remove(index);

            return;
        }

        index++;
    }
}

namespace proc {
    inline void stop() {return dc_proc_stop();}
}

namespace console {
    inline void logPart(dataTypes::String value) {return dc_console_logPart(value.c_str());}
    inline void logPart(char* value) {return dc_console_logPartChars(value);}
    inline void logPart(unsigned int value) {return dc_console_logPartUInt(value);}
    inline void logPart(int value) {return dc_console_logPartInt(value);}
    inline void logPart(unsigned long value) {return dc_console_logPartULong(value);}
    inline void logPart(long value) {return dc_console_logPartLong(value);}
    inline void logPart(double value) {return dc_console_logPartDouble(value);}
    inline void logPart(void* value) {return dc_console_logPartPtr(value);}
    inline void logNewline() {return dc_console_logNewline();}
}

namespace timing {
    class Time {
        protected:
            dc::_Sid _sid;

            Time(_Dummy dummy) {}

        public:
            virtual dc::_Sid _getSid() {return _sid;}

            ~Time() {dc_deleteBySid(_sid); _removeStoredInstance(this);}

            Time() {_sid = dc_timing_Time_new(); _addStoredInstance(_Type::timing_Time, this);}
            Time(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second) {_sid = dc_timing_Time_newUsingDate(year, month, day, hour, minute, second); _addStoredInstance(_Type::timing_Time, this);}
            Time(int year, unsigned int month, unsigned int day, unsigned long millisecondOfDay) {_sid = dc_timing_Time_newUsingMilliseconds(year, month, day, millisecondOfDay); _addStoredInstance(_Type::timing_Time, this);}

            unsigned int daysInYear() {return dc_timing_Time_daysInYear(_sid);}
            unsigned int daysInMonth(unsigned int month) {return dc_timing_Time_daysInMonth(_sid, month);}
            unsigned long millisecondsInDay() {return dc_timing_Time_millisecondsInDay(_sid);}
            bool inLeapMillisecond() {return dc_timing_Time_inLeapMillisecond(_sid);}
            unsigned long postLeapMillisecondOffset() {return dc_timing_Time_postLeapMillisecondOffset(_sid);}
            void setDate(int year, unsigned int month, unsigned int day) {return dc_timing_Time_setDate(_sid, year, month, day);}
            void setTime(unsigned int hour, unsigned int minute, unsigned int second) {return dc_timing_Time_setTime(_sid, hour, minute, second);}
            void incrementTime(int millseconds) {return dc_timing_Time_incrementTime(_sid, millseconds);}
            void toLocalTime(int timeShift) {return dc_timing_Time_toLocalTime(_sid, timeShift);}
            void toGlobalTime() {return dc_timing_Time_toGlobalTime(_sid);}
            int timeShift() {return dc_timing_Time_timeShift(_sid);}
            int year() {return dc_timing_Time_year(_sid);}
            unsigned int month() {return dc_timing_Time_month(_sid);}
            unsigned int day() {return dc_timing_Time_day(_sid);}
            unsigned int hour() {return dc_timing_Time_hour(_sid);}
            unsigned int minute() {return dc_timing_Time_minute(_sid);}
            unsigned int second() {return dc_timing_Time_second(_sid);}
            unsigned int millisecond() {return dc_timing_Time_millisecond(_sid);}
            unsigned int dayOfYear() {return dc_timing_Time_dayOfYear(_sid);}
            unsigned long millisecondOfDay() {return dc_timing_Time_millisecondOfDay(_sid);}
            unsigned long millisecondOfDayIgnoringLeap() {return dc_timing_Time_millisecondOfDayIgnoringLeap(_sid);}
            unsigned int weekday() {return dc_timing_Time_weekday(_sid);}
    };

    class EarthTime : public Time {
        protected:
            EarthTime(_Dummy dummy) : Time(dummy) {}

        public:
            using Time::Time;

            EarthTime() : Time((_Dummy) {}) {_sid = dc_timing_EarthTime_new(); _addStoredInstance(_Type::timing_EarthTime, this);}
            EarthTime(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second) : Time((_Dummy) {}) {_sid = dc_timing_EarthTime_newUsingDate(year, month, day, hour, minute, second); _addStoredInstance(_Type::timing_EarthTime, this);}
            EarthTime(int year, unsigned int month, unsigned int day, unsigned long millisecondOfDay) : Time((_Dummy) {}) {_sid = dc_timing_EarthTime_newUsingMilliseconds(year, month, day, millisecondOfDay); _addStoredInstance(_Type::timing_EarthTime, this);}

            void syncToSystemTime() {return dc_timing_EarthTime_syncToSystemTime(_sid);}
    };

    inline unsigned long getCurrentTick() {return dc_timing_getCurrentTick();}
}

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
}

namespace ui {
    enum EventType {
        BUTTON_DOWN,
        BUTTON_UP,
        ITEM_SELECT,
        CANCEL
    };

    enum PopupTransitionState {
        NONE,
        OPENING,
        CLOSING
    };

    enum PenMode {
        OFF,
        ON
    };

    struct Event {
        EventType type;
        union {input::Button button; unsigned int index;} data;
    };

    class Icon {
        protected:
            dc::_Sid _sid;

            Icon(_Dummy dummy) {}

        public:
            virtual dc::_Sid _getSid() {return _sid;}

            ~Icon() {dc_deleteBySid(_sid); _removeStoredInstance(this);}

            Icon() {_sid = dc_ui_Icon_new(); _addStoredInstance(_Type::ui_Icon, this);}

            void setPixel(unsigned int x, unsigned int y, ui::PenMode value) {return dc_ui_Icon_setPixel(_sid, x, y, value);}
    };

    class Screen {
        protected:
            dc::_Sid _sid;

            Screen(_Dummy dummy) {}

        public:
            virtual dc::_Sid _getSid() {return _sid;}

            ~Screen() {dc_deleteBySid(_sid); _removeStoredInstance(this);}

            Screen() {_sid = dc_ui_Screen_new(); _addStoredInstance(_Type::ui_Screen, this);}

            void clear() {return dc_ui_Screen_clear(_sid);}
            void setPosition(unsigned int column, unsigned int row) {return dc_ui_Screen_setPosition(_sid, column, row);}
            void setPixel(unsigned int x, unsigned int y, ui::PenMode value) {return dc_ui_Screen_setPixel(_sid, x, y, value);}
            void print(char c) {return dc_ui_Screen_printChar(_sid, c);}
            void print(dataTypes::String string) {return dc_ui_Screen_print(_sid, string.c_str());}
            void print(char* chars) {return dc_ui_Screen_printChars(_sid, chars);}
            void print(unsigned int value) {return dc_ui_Screen_printUInt(_sid, value);}
            void print(int value) {return dc_ui_Screen_printInt(_sid, value);}
            void print(unsigned long value) {return dc_ui_Screen_printULong(_sid, value);}
            void print(long value) {return dc_ui_Screen_printLong(_sid, value);}
            void print(double value) {return dc_ui_Screen_printDouble(_sid, value);}
            void print(ui::Icon* icon) {return dc_ui_Screen_printIcon(_sid, icon->_getSid());}
            void printRepeated(dataTypes::String string, unsigned int times) {return dc_ui_Screen_printRepeated(_sid, string.c_str(), times);}
            void scroll(dataTypes::String string, unsigned int maxLength) {return dc_ui_Screen_scroll(_sid, string.c_str(), maxLength);}
            void resetScroll() {return dc_ui_Screen_resetScroll(_sid);}
            void pad(unsigned int size, char c) {return dc_ui_Screen_pad(_sid, size, c);}
            void rect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, ui::PenMode value) {return dc_ui_Screen_rect(_sid, x1, y1, x2, y2, value);}
            void filledRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, ui::PenMode value) {return dc_ui_Screen_filledRect(_sid, x1, y1, x2, y2, value);}
            virtual void update() {}
            virtual void handleEvent(ui::Event event) {}
            virtual void open(bool urgent) {return dc_ui_Screen_open(_sid, urgent);}
            virtual void close() {return dc_ui_Screen_close(_sid);}
            void swapWith(ui::Screen* currentScreen) {return dc_ui_Screen_swapWith(_sid, currentScreen->_getSid());}
    };

    class Menu : public Screen {
        protected:
            Menu(_Dummy dummy) : Screen(dummy) {}

        public:
            using Screen::Screen;

            Menu() : Screen((_Dummy) {}) {_sid = dc_ui_Menu_new(); _addStoredInstance(_Type::ui_Menu, this);}

            void clearItems() {return dc_ui_Menu_clearItems(_sid);}
            void addItem(dataTypes::String item) {return dc_ui_Menu_addItem(_sid, item.c_str());}
            dataTypes::List<dataTypes::String> items;
            void updateItems() {clearItems(); items.start(); while (auto item = items.next()) {addItem(*item);}}
    };

    class ContextualMenu : public Menu {
        protected:
            ContextualMenu(_Dummy dummy) : Menu(dummy) {}

        public:
            using Menu::Menu;

            ContextualMenu() : Menu((_Dummy) {}) {_sid = dc_ui_ContextualMenu_new(); _addStoredInstance(_Type::ui_ContextualMenu, this);}
            ContextualMenu(dataTypes::String title) {_sid = dc_ui_ContextualMenu_newWithTitle(title.c_str()); _addStoredInstance(_Type::ui_ContextualMenu, this);}

            void setTitle(dataTypes::String title) {return dc_ui_ContextualMenu_setTitle(_sid, title.c_str());}
    };

    class Popup : public Screen {
        protected:
            Popup(_Dummy dummy) : Screen(dummy) {}

        public:
            using Screen::Screen;

            Popup() : Screen((_Dummy) {}) {_sid = dc_ui_Popup_new(); _addStoredInstance(_Type::ui_Popup, this);}
    };
}

namespace test {
    class TestClass {
        protected:
            dc::_Sid _sid;

            TestClass(_Dummy dummy) {}

        public:
            virtual dc::_Sid _getSid() {return _sid;}

            ~TestClass() {dc_deleteBySid(_sid); _removeStoredInstance(this);}

            TestClass(unsigned int seed) {_sid = dc_test_TestClass_new(seed); _addStoredInstance(_Type::test_TestClass, this);}

            virtual void identify() {return dc_test_TestClass_identify(_sid);}
            unsigned int add(unsigned int value, unsigned int value2) {return dc_test_TestClass_add(_sid, value, value2);}
            void bools(bool a, bool b, bool c) {return dc_test_TestClass_bools(_sid, a, b, c);}
            unsigned int nextRandomNumber() {return dc_test_TestClass_nextRandomNumber(_sid);}
    };

    class TestSubclass : public TestClass {
        protected:
            TestSubclass(_Dummy dummy) : TestClass(dummy) {}

        public:
            using TestClass::TestClass;

            TestSubclass(unsigned int seed) : TestClass((_Dummy) {}) {_sid = dc_test_TestSubclass_new(seed); _addStoredInstance(_Type::test_TestSubclass, this);}

            void identify() override {return dc_test_TestSubclass_identify(_sid);}
            void subclass() {return dc_test_TestSubclass_subclass(_sid);}
    };

    inline void sayHello() {return dc_test_sayHello();}
    inline int add(int a, int b) {return dc_test_add(a, b);}
}

#ifndef DC_COMMON_CONSOLE_H_
#define DC_COMMON_CONSOLE_H_

namespace console {
    template<typename T> void log(T value);
    template<typename T, typename ...Args> void log(T value, Args... args);
}

#endif

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

#ifndef DC_COMMON_CONSOLE_CPP_
#define DC_COMMON_CONSOLE_CPP_

#ifndef DIGICRON_H_
    #include "../console.h"
    #include "console.h"
#endif

template<typename T> void console::log(T value) {
    logPart(value);
    logNewline();
}

template<typename T, typename ...Args> void console::log(T value, Args... args) {
    logPart(value);
    logPart(" ");
    log(args...);
}

#endif

#ifndef DC_COMMON_DATATYPES_CPP_
#define DC_COMMON_DATATYPES_CPP_

#ifndef DIGICRON_H_
    #include "datatypes.h"
#endif

template<typename T> T* store(T value) {
    auto storedValue = new dataTypes::StoredValue<T>(value);

    return &storedValue->value;
}

template<typename T> T discard(T* itemPtr) {
    auto itemValue = *itemPtr;

    free(itemPtr);

    return itemValue;
}

template<typename T> dataTypes::StoredValue<T>::StoredValue(T valueToStore) {
    value = valueToStore;
}

template<typename T> dataTypes::StoredValue<T>::~StoredValue() {}

#ifdef DIGICRON_H_
    inline dataTypes::String::String(const char* value) {
        while (value[_length] != '\0') {
            _length++;
        }

        _value = (char*)malloc(_length + 1);

        for (unsigned int i = 0; i <= _length; i++) {
            _value[i] = value[i];
        }
    }

    inline dataTypes::String::String(const dataTypes::String& other) : String(other.c_str()) {}

    inline dataTypes::String::~String() {
        if (_value) {
            free(_value);
        }
    }

    inline dataTypes::String& dataTypes::String::operator=(const dataTypes::String& other) {
        if (this == &other) {
            return *this;
        }

        char* otherCstr = other.c_str();

        _length = other.length();
        _value = (char*)malloc(_length + 1);

        for (unsigned int i = 0; i <= _length; i++) {
            _value[i] = otherCstr[i];
        }

        return *this;
    }

    inline char dataTypes::String::operator[](int index) {
        return charAt(index);
    }

    inline char* dataTypes::String::c_str() const {
        return _value;
    }

    inline unsigned int dataTypes::String::length() const {
        return _length;
    }

    inline char dataTypes::String::charAt(int index) {
        if (!_value || index >= _length) {
            return '\0';
        }

        return _value[index];
    }
#endif

template<typename T> dataTypes::List<T>::List() {
    _firstItemPtr = nullptr;
    _length = 0;
}

template<typename T> dataTypes::List<T>::~List() {
    empty();
}

template<typename T> dataTypes::_ListItem<T>* dataTypes::List<T>::getItemAtIndex(int index) {
    if (!_firstItemPtr) {
        return nullptr;
    }

    if (index < 0) {
        int resolvedIndex = _length + index;

        if (resolvedIndex < 0) {
            return nullptr;
        }

        return getItemAtIndex(resolvedIndex);
    }

    auto currentItemPtr = _firstItemPtr;

    while (index > 0) {
        if (!currentItemPtr) {
            return nullptr;
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index--;
    }

    return currentItemPtr;
}

template<typename T> T* dataTypes::List<T>::operator[](int index) {
    auto item = getItemAtIndex(index);

    if (!item) {
        return nullptr;
    }

    return item->valuePtr;
}

template<typename T> dataTypes::_ListItem<T>* dataTypes::List<T>::getLastItem() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    auto currentItemPtr = _firstItemPtr;
    _ListItem<T>* previousItemPtr;

    do {
        previousItemPtr = currentItemPtr;
        currentItemPtr = currentItemPtr->nextItemPtr;
    } while (currentItemPtr);

    return previousItemPtr;
}

template<typename T> void dataTypes::List<T>::start(Iterator* iterator) {
    if (iterator == nullptr) {
        iterator = &_defaultIterator;
    }

    *iterator = _firstItemPtr;
}

template<typename T> T* dataTypes::List<T>::next(Iterator* iterator) {
    if (iterator == nullptr) {
        iterator = &_defaultIterator;
    }

    auto itemPtr = *iterator;

    if (!*iterator) {
        return nullptr;
    }

    *iterator = (*iterator)->nextItemPtr;

    return itemPtr->valuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::length() {
    return _length;
}

template<typename T> void dataTypes::List<T>::empty() {
    if (!_firstItemPtr) {
        return;
    }

    auto currentItemPtr = _firstItemPtr;

    while (currentItemPtr) {
        auto nextItemPtr = currentItemPtr->nextItemPtr;

        delete currentItemPtr;

        currentItemPtr = nextItemPtr;
    }

    _firstItemPtr = nullptr;
    _length = 0;
}

template<typename T> unsigned int dataTypes::List<T>::push(T* valuePtr) {
    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = nullptr
    };

    _length++;

    if (!_firstItemPtr) {
        _firstItemPtr = itemPtr;

        return 1;
    }

    getLastItem()->nextItemPtr = itemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::pop() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    if (!_firstItemPtr->nextItemPtr) {
        auto item = _firstItemPtr;

        _firstItemPtr = nullptr;
        _length--;

        return item->valuePtr;
    }

    auto lastItemPtr = getLastItem();
    auto lastItemValuePtr = lastItemPtr->valuePtr;

    getItemAtIndex(-2)->nextItemPtr = nullptr;
    _length--;

    delete lastItemPtr;

    return lastItemValuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::unshift(T* valuePtr) {
    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = nullptr
    };

    _length++;

    if (!_firstItemPtr) {
        _firstItemPtr = itemPtr;

        return 1;
    }

    auto oldFirstItemPtr = _firstItemPtr;

    _firstItemPtr = itemPtr;

    itemPtr->nextItemPtr = oldFirstItemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::shift() {
    if (!_firstItemPtr) {
        return nullptr;
    }

    _length--;

    auto itemPtr = _firstItemPtr;
    auto itemValuePtr = itemPtr->valuePtr;

    _firstItemPtr = _firstItemPtr->nextItemPtr;

    delete itemPtr;

    return itemValuePtr;
}

template<typename T> unsigned int dataTypes::List<T>::insert(unsigned int index, T* valuePtr) {
    if (index == 0) {
        return unshift(valuePtr);
    }

    if (index == _length) {
        return push(valuePtr);
    }

    auto previousItemPtr = getItemAtIndex(index - 1);

    if (!previousItemPtr) {
        return _length;
    }

    _length++;

    auto itemPtr = new _ListItem<T> {
        .valuePtr = valuePtr,
        .nextItemPtr = previousItemPtr->nextItemPtr
    };

    previousItemPtr->nextItemPtr = itemPtr;

    return _length;
}

template<typename T> T* dataTypes::List<T>::remove(unsigned int index) {
    if (index == 0) {
        return shift();
    }

    if (index == _length - 1) {
        return pop();
    }

    auto previousItemPtr = getItemAtIndex(index - 1);

    if (!previousItemPtr) {
        return nullptr;
    }

    auto itemPtr = previousItemPtr->nextItemPtr;

    if (!itemPtr) {
        return nullptr;
    }

    _length--;

    auto itemValuePtr = itemPtr->valuePtr;
    auto nextItemPtr = itemPtr->nextItemPtr;

    previousItemPtr->nextItemPtr = nextItemPtr;

    delete itemPtr;

    return itemValuePtr;
}

template<typename T> void dataTypes::List<T>::set(unsigned int index, T* valuePtr) {
    auto item = getItemAtIndex(index);

    if (!item) {
        return;
    }

    item->valuePtr = valuePtr;
}

template<typename T> int dataTypes::List<T>::indexOf(T* valuePtr) {
    auto currentItemPtr = _firstItemPtr;
    int index = 0;

    while (currentItemPtr) {
        if (currentItemPtr->valuePtr == valuePtr) {
            return index;
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return -1;
}

template<typename T> void dataTypes::List<T>::forEach(IterationCallback iterationCallback) {
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        iterationCallback(currentItemPtr->valuePtr, index);

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::map(MappingFunction mappingFunction) {
    List<T> newList;
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        newList.push(mappingFunction(currentItemPtr->valuePtr, index));

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return newList;
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::filter(FilteringFunction filteringFunction) {
    List<T> newList;
    auto currentItemPtr = _firstItemPtr;
    unsigned int index = 0;

    while (currentItemPtr) {
        if (filteringFunction(currentItemPtr->valuePtr, index)) {
            newList.push(currentItemPtr->valuePtr);
        }

        currentItemPtr = currentItemPtr->nextItemPtr;
        index++;
    }

    return newList;
}

template<typename T> dataTypes::List<T> dataTypes::List<T>::concat(dataTypes::List<T> otherList) {
    List<T> newList;

    start();

    while (auto itemPtr = next()) {
        newList.push(itemPtr);
    }

    otherList.start();

    while (auto itemPtr = otherList.next()) {
        newList.push(itemPtr);
    }

    return newList;
}

#endif

#ifndef DC_COMMON_DISPLAY_CPP_
#define DC_COMMON_DISPLAY_CPP_

#endif

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

}

WASM_EXPORT_AS("_setup") inline void _setup() {
    setup();
}

WASM_EXPORT_AS("_loop") inline void _loop() {
    loop();
}

#ifndef DIGICRON_H_
    #define WASM_EXPORT_AS(name)
#endif

#define _DC_CALLABLE(type, namespace, class, method) WASM_EXPORT_AS("_callable_" #namespace "_" #class "_" #method) inline type _callable_##namespace##_##class##_##method

#define _DC_MAP_TO_METHOD(namespace, class, method, ...) do { \
        if (auto instance = dc::_getBySid<dc::namespace::class>(dc::_Type::namespace##_##class, sid)) { \
            return instance->method(__VA_ARGS__); \
        } \
    } while (0);

_DC_CALLABLE(void, ui, Screen, update)(dc::_Sid sid) {
    _DC_MAP_TO_METHOD(ui, Screen, update);
}

_DC_CALLABLE(void, ui, Screen, handleSimpleEvent)(dc::_Sid sid, dc::ui::EventType eventType) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType
    });
}

_DC_CALLABLE(void, ui, Screen, handleButtonEvent)(dc::_Sid sid, dc::ui::EventType eventType, dc::input::Button button) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType,
        .data.button = button
    });
}

_DC_CALLABLE(void, ui, Screen, handleItemEvent)(dc::_Sid sid, dc::ui::EventType eventType, unsigned int index) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType,
        .data.index = index
    });
}
#endif
