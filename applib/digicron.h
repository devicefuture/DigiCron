// Autogenerated by `tools/api/builder.sh` using declarations from `tools/api/api.sh`

#ifndef DIGICRON_H_
#define DIGICRON_H_

#include <stdint.h>

#define WASM_EXPORT extern "C" __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(name) WASM_EXPORT __attribute__((export_name(name)))
#define WASM_IMPORT(module, name) __attribute__((import_module(module))) __attribute__((import_name(name)))
#define WASM_CONSTRUCTOR __attribute__((constructor))

namespace dc {
    typedef unsigned int _Enum;
    typedef int _Sid;
    typedef struct {} _Dummy;
}

void setup();
void loop();

extern "C" {

WASM_IMPORT("digicronold", "log") void dc_log(uint8_t* text, uint8_t length);
WASM_IMPORT("digicronold", "stop") void dc_stop();

WASM_IMPORT("digicron", "dc_getGlobalI32") uint32_t dc_getGlobalI32(const char* id);
WASM_IMPORT("digicron", "dc_deleteBySid") void dc_deleteBySid(dc::_Sid sid);

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
WASM_IMPORT("digicron", "dc_ui_Screen_print") void dc_ui_Screen_print(dc::_Sid sid, char* chars);
WASM_IMPORT("digicron", "dc_ui_Screen_printIcon") void dc_ui_Screen_printIcon(dc::_Sid sid, dc::_Sid icon);
WASM_IMPORT("digicron", "dc_ui_Screen_printRepeated") void dc_ui_Screen_printRepeated(dc::_Sid sid, char* string, unsigned int times);
WASM_IMPORT("digicron", "dc_ui_Screen_scroll") void dc_ui_Screen_scroll(dc::_Sid sid, char* string, unsigned int maxLength);
WASM_IMPORT("digicron", "dc_ui_Screen_resetScroll") void dc_ui_Screen_resetScroll(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Screen_rect") void dc_ui_Screen_rect(dc::_Sid sid, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_filledRect") void dc_ui_Screen_filledRect(dc::_Sid sid, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, dc::_Enum value);
WASM_IMPORT("digicron", "dc_ui_Screen_open") void dc_ui_Screen_open(dc::_Sid sid, bool urgent);
WASM_IMPORT("digicron", "dc_ui_Screen_close") void dc_ui_Screen_close(dc::_Sid sid);
WASM_IMPORT("digicron", "dc_ui_Screen_swapWith") void dc_ui_Screen_swapWith(dc::_Sid sid, dc::_Sid currentScreen);
WASM_IMPORT("digicron", "dc_ui_Popup_new") dc::_Sid dc_ui_Popup_new();
WASM_IMPORT("digicron", "dc_ui_Popup_open") void dc_ui_Popup_open(dc::_Sid sid, bool urgent);
WASM_IMPORT("digicron", "dc_ui_Popup_close") void dc_ui_Popup_close(dc::_Sid sid);
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

#define _DC_ALIGN_SIZE 4
#define _DC_ALIGN(value) (((value) + _DC_ALIGN_SIZE - 1) & ~(_DC_ALIGN_SIZE - 1))

#define _DC_FLAG_USED 0x8000
#define _DC_BLOCK_IS_USED(address) (*(address) & _DC_FLAG_USED)
#define _DC_BLOCK_SIZE(address) (*(address) & (_DC_FLAG_USED - 1))
#define _DC_BLOCK_IS_LAST(address) (*(address) == 0)

// #define _DC_DEBUG_HEAP

#ifdef _DC_DEBUG_HEAP
    #define _DC_DEBUG_HEAP_LOG(message) dc_log((uint8_t*)(message), sizeof(message) - 1)
#else
    #define _DC_DEBUG_HEAP_LOG(message)
#endif

typedef unsigned long size_t;

namespace dc::heap {
    typedef size_t Block;

    const Block* base = (Block*)dc_getGlobalI32("__heap_base");
    Block* firstFreeBlock = (Block*)base;
}

extern "C" {
    void* memset(void* destination, char value, size_t size) {
        for (size_t i = 0; i < size; i++) {
            *((char*)destination + size) = value;
        }


        return destination;
    }

    void* memcpy(void* destination, void* source, size_t size) {
        for (size_t i = 0; i < size; i++) {
            *((char*)destination + i) = *((char*)source + i);
        }

        return destination;
    }

    void* malloc(size_t size) {
        _DC_DEBUG_HEAP_LOG("> malloc");

        if (size == 0) {
            size = _DC_ALIGN_SIZE;
        }

        if (size & _DC_FLAG_USED) {
            return nullptr;
        }

        size = _DC_ALIGN(size);

        dc::heap::Block* currentBlock = dc::heap::firstFreeBlock;

        while (true) {
            if (_DC_BLOCK_IS_LAST(currentBlock)) {
                _DC_DEBUG_HEAP_LOG("Use last block");

                *currentBlock = _DC_FLAG_USED | size;
                *(currentBlock + sizeof(dc::heap::Block) + size) = 0; // Create a new last block after this one

                if (currentBlock == dc::heap::firstFreeBlock) {
                    _DC_DEBUG_HEAP_LOG("  Set next free block");

                    dc::heap::firstFreeBlock = currentBlock + sizeof(dc::heap::Block) + size;
                }

                return currentBlock + sizeof(dc::heap::Block);
            }

            size_t originalBlockSize = _DC_BLOCK_SIZE(currentBlock);

            if (_DC_BLOCK_IS_USED(currentBlock)) {
                // Skip over this block if it's used

                _DC_DEBUG_HEAP_LOG("Skip used");

                currentBlock += sizeof(dc::heap::Block) + originalBlockSize;

                continue;
            }

            if (originalBlockSize < size) {
                // Try and merge subsequent blocks to meet required size; if not, then skip

                dc::heap::Block* originalBlock = currentBlock;
                size_t totalUsableSize = originalBlockSize;
                bool encounteredUsedBlock = false;
                bool encounteredLastBlock = false;

                _DC_DEBUG_HEAP_LOG("Attempt resize");

                do {
                    currentBlock += sizeof(dc::heap::Block) + originalBlockSize;

                    if (_DC_BLOCK_IS_USED(currentBlock)) {
                        _DC_DEBUG_HEAP_LOG("  Encountered used block");

                        encounteredUsedBlock = true;

                        break;
                    }

                    if (_DC_BLOCK_IS_LAST(currentBlock)) {
                        // Looks like we can use the rest of the available memory

                        _DC_DEBUG_HEAP_LOG("  Encountered last block");

                        encounteredLastBlock = true;

                        break;
                    }

                    totalUsableSize += *currentBlock + sizeof(dc::heap::Block);
                } while (totalUsableSize < size);

                if (encounteredUsedBlock) {
                    continue;
                }

                currentBlock = originalBlock;

                if (encounteredLastBlock) {
                    _DC_DEBUG_HEAP_LOG("  Using last block");

                    *(currentBlock + sizeof(dc::heap::Block) + size) = 0; // Create a new last block after this one
                }
            }

            if (originalBlockSize > size + sizeof(dc::heap::Block) + _DC_ALIGN_SIZE) {
                // Split this block so that the rest can be used for other purposes

                _DC_DEBUG_HEAP_LOG("Split block");

                *currentBlock = size;
                *(currentBlock + sizeof(dc::heap::Block) + size) = originalBlockSize - size - sizeof(dc::heap::Block);
            }

            _DC_DEBUG_HEAP_LOG("Mark as used");

            *currentBlock |= _DC_FLAG_USED;

            if (currentBlock == dc::heap::firstFreeBlock) {
            _DC_DEBUG_HEAP_LOG("Search for a new first free block");

                while (_DC_BLOCK_IS_USED(dc::heap::firstFreeBlock)) {
                    _DC_DEBUG_HEAP_LOG("  Search next");

                    dc::heap::firstFreeBlock += _DC_BLOCK_SIZE(dc::heap::firstFreeBlock) + sizeof(dc::heap::Block);
                }
            }

            return currentBlock + sizeof(dc::heap::Block);
        }
    }

    void free(void* ptr) {
        dc::heap::Block* block = (dc::heap::Block*)ptr - sizeof(dc::heap::Block);

        _DC_DEBUG_HEAP_LOG("> free");

        *block &= ~_DC_FLAG_USED;
 
        if (block < dc::heap::firstFreeBlock) {
            _DC_DEBUG_HEAP_LOG("Set first free block");

            dc::heap::firstFreeBlock = block;
        }

        dc::heap::Block* currentBlock = block + sizeof(dc::heap::Block) + *block;

        // Merge together any subsequent free blocks
        while (!_DC_BLOCK_IS_USED(currentBlock)) {
            if (_DC_BLOCK_IS_LAST(currentBlock)) {
                _DC_DEBUG_HEAP_LOG("Convert to last block");

                *block = 0; // Make the penultimate block the last one instead

                return;
            }

            _DC_DEBUG_HEAP_LOG("Merge subsequent block");

            *block += _DC_BLOCK_SIZE(currentBlock) + sizeof(dc::heap::Block);
            currentBlock += _DC_BLOCK_SIZE(currentBlock) + sizeof(dc::heap::Block);
        }
    }

    void* calloc(size_t count, size_t size) {
        void* memory = malloc(count * size);

        if (memory) {
            memset(memory, '\0', count * size);
        }

        return memory;
    }

    void* realloc(void* ptr, size_t size) {
        _DC_DEBUG_HEAP_LOG("> realloc");

        if (!ptr || size & _DC_FLAG_USED) {
            return nullptr;
        }

        if (size == 0) {
            free(ptr);

            return nullptr;
        }

        size = _DC_ALIGN(size);

        dc::heap::Block* blockPtr = (dc::heap::Block*)ptr;
        dc::heap::Block* block = blockPtr - sizeof(dc::heap::Block);

        if (size == _DC_BLOCK_SIZE(block)) {
            _DC_DEBUG_HEAP_LOG("Equal size");

            return ptr;
        }

        if (_DC_BLOCK_IS_LAST(blockPtr + _DC_BLOCK_SIZE(block))) {
            // Modify last block to match new size

            _DC_DEBUG_HEAP_LOG("Modify last block");

            *block = _DC_FLAG_USED | _DC_ALIGN(size);
            *(blockPtr + size) = 0; // Set new position for last block

            return ptr;
        }

        if (size + sizeof(dc::heap::Block) < _DC_BLOCK_SIZE(block)) {
            // Truncate current block by splitting truncated portion off into new block

            _DC_DEBUG_HEAP_LOG("Truncate block");

            *(blockPtr + size) = _DC_BLOCK_SIZE(block) - size - sizeof(dc::heap::Block);
            *block = _DC_FLAG_USED | size;

            return ptr;
        }

        // Perform full reallocation

        _DC_DEBUG_HEAP_LOG("Fully reallocate");

        void* newPtr = malloc(size);

        if (!newPtr) {
            return nullptr;
        }

        memcpy(newPtr, ptr, _DC_BLOCK_SIZE(block));
        free(ptr);

        return newPtr;
    }
}

void* operator new(size_t size) {
    return malloc(size);
}

void* operator new[](size_t size) {
    return malloc(size);
}

void operator delete(void* ptr) {
    free(ptr);
}

void operator delete(void* ptr, size_t size) {
    free(ptr);
}

void operator delete[](void* ptr) {
    free(ptr);
}

void operator delete[](void* ptr, size_t size) {
    free(ptr);
}

extern "C" int __cxa_atexit(void (*function)(void*), void* argument, void* handle) {
    return 0;
}

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

                char operator[](int index);

                char* c_str();
                unsigned int length();
                char charAt(int index);
        };
    #else
        typedef String String;
    #endif

    template<typename T> class List {
        public:
            typedef void (*IterationCallback)(T* itemPtr, unsigned int index);
            typedef T* (*MappingFunction)(T* itemPtr, unsigned int index);
            typedef bool (*FilteringFunction)(T* itemPtr, unsigned int index);

            List<T>();
            ~List<T>();

            T* operator[](int index);

            void start();
            T* next();
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
            _ListItem<T>* _currentItemPtr;
            unsigned int _length;

            _ListItem<T>* getItemAtIndex(int index);
            _ListItem<T>* getLastItem();
    };
}

#endif

enum _Type {EMPTY, timing_Time, timing_EarthTime, ui_Icon, ui_Screen, ui_Popup, test_TestClass, test_TestSubclass};

struct _StoredInstance {
    _Type type;
    void* instance;
};

dataTypes::List<_StoredInstance> _storedInstances;

template<typename T> T* _getBySid(_Type type, _Sid sid) {
    _storedInstances.start();

    while (_StoredInstance* storedInstance = _storedInstances.next()) {
        if (storedInstance->type != type && !(
            (type == _Type::timing_Time && storedInstance->type == _Type::timing_EarthTime) ||
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

void _addStoredInstance(_Type type, void* instance) {
    auto storedInstance = new _StoredInstance {
        .type = type,
        .instance = instance
    };

    _storedInstances.push(storedInstance);
}

void _removeStoredInstance(void* instance) {
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

    unsigned long getCurrentTick() {return dc_timing_getCurrentTick();}
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
        union {input::Button button;} data;
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
            void print(char* chars) {return dc_ui_Screen_print(_sid, chars);}
            void print(ui::Icon* icon) {return dc_ui_Screen_printIcon(_sid, icon->_getSid());}
            void printRepeated(dataTypes::String string, unsigned int times) {return dc_ui_Screen_printRepeated(_sid, string.c_str(), times);}
            void scroll(dataTypes::String string, unsigned int maxLength) {return dc_ui_Screen_scroll(_sid, string.c_str(), maxLength);}
            void resetScroll() {return dc_ui_Screen_resetScroll(_sid);}
            void rect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, ui::PenMode value) {return dc_ui_Screen_rect(_sid, x1, y1, x2, y2, value);}
            void filledRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, ui::PenMode value) {return dc_ui_Screen_filledRect(_sid, x1, y1, x2, y2, value);}
            virtual void update() {}
            virtual void handleEvent(ui::Event event) {}
            virtual void open(bool urgent) {return dc_ui_Screen_open(_sid, urgent);}
            virtual void close() {return dc_ui_Screen_close(_sid);}
            void swapWith(ui::Screen* currentScreen) {return dc_ui_Screen_swapWith(_sid, currentScreen->_getSid());}
    };

    class Popup : public Screen {
        protected:
            Popup(_Dummy dummy) : Screen(dummy) {}

        public:
            using Screen::Screen;

            Popup() : Screen((_Dummy) {}) {_sid = dc_ui_Popup_new(); _addStoredInstance(_Type::ui_Popup, this);}

            void open(bool urgent) override {return dc_ui_Popup_open(_sid, urgent);}
            void close() override {return dc_ui_Popup_close(_sid);}
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

    void sayHello() {return dc_test_sayHello();}
    int add(int a, int b) {return dc_test_add(a, b);}
}

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

#ifndef DIGICRON_H_
    #include "../datatypes.h"
    #include "../ui.h"
#endif

namespace ui {
    Icon* constructIcon(dataTypes::String pixels);
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
    dataTypes::String::String(const char* value) {
        while (value[_length] != '\0') {
            _length++;
        }

        _value = (char*)malloc(_length + 1);

        for (unsigned int i = 0; i <= _length; i++) {
            _value[i] = value[i];
        }
    }

    char dataTypes::String::operator[](int index) {
        return charAt(index);
    }

    char* dataTypes::String::c_str() {
        return _value;
    }

    char dataTypes::String::charAt(int index) {
        if (!_value || index >= _length) {
            return '\0';
        }

        return _value[index];
    }

    unsigned int dataTypes::String::length() {
        return _length;
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

template<typename T> void dataTypes::List<T>::start() {
    _currentItemPtr = _firstItemPtr;
}

template<typename T> T* dataTypes::List<T>::next() {
    auto itemPtr = _currentItemPtr;

    if (!_currentItemPtr) {
        return nullptr;
    }

    _currentItemPtr = _currentItemPtr->nextItemPtr;

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

WASM_EXPORT_AS("_setup") void _setup() {
    setup();
}

WASM_EXPORT_AS("_loop") void _loop() {
    loop();
}

#ifndef DIGICRON_H_
    #define WASM_EXPORT_AS(name)
#endif

#define _DC_CALLABLE(type, namespace, class, method) WASM_EXPORT_AS("_callable_" #namespace "_" #class "_" #method) type _callable_##namespace##_##class##_##method

#define _DC_MAP_TO_METHOD(namespace, class, method, ...) do { \
        if (auto instance = dc::_getBySid<dc::namespace::class>(dc::_Type::namespace##_##class, sid)) { \
            return instance->method(__VA_ARGS__); \
        } \
    } while (0);

_DC_CALLABLE(void, ui, Screen, update)(dc::_Sid sid) {
    _DC_MAP_TO_METHOD(ui, Screen, update);
}

_DC_CALLABLE(void, ui, Screen, handleButtonEvent)(dc::_Sid sid, dc::ui::EventType eventType, dc::input::Button button) {
    _DC_MAP_TO_METHOD(ui, Screen, handleEvent, (dc::ui::Event) {
        .type = eventType,
        .data.button = button
    });
}
#endif
