#!/bin/bash

namespace timing
    class EarthTime
        constructor "int" year "unsigned int" month "unsigned int" day "unsigned int" hour "unsigned int" minute "unsigned int" second
        INTERNAL_NAME=dc_timing_EarthTime_newUsingMilliseconds constructor "int" year "unsigned int" month "unsigned int" day "unsigned long" millisecondOfDay

        method "unsigned int" daysInYear
        method "unsigned int" daysInMonth "unsigned int" month
        method "unsigned long" millisecondsInDay

        method "bool" inLeapMillisecond
        method "unsigned long" postLeapMillisecondOffset

        method "void" setDate "int" year "unsigned int" month "unsigned int" day
        method "void" setTime "unsigned int" hour "unsigned int" minute "unsigned int" second
        method "void" incrementTime "int" millseconds
        method "void" toLocalTime "int" timeShift
        method "void" toGlobalTime

        method "int" year
        method "unsigned int" month
        method "unsigned int" day
        method "unsigned int" hour
        method "unsigned int" minute
        method "unsigned int" second
        method "unsigned int" millisecond

        method "unsigned int" dayOfYear
        method "unsigned long" millisecondOfDay
        method "unsigned long" millisecondOfDayIgnoringLeap

        method "unsigned int" weekday

namespace input
    enum Button \
        "NONE = 0" \
        "BACK = 1" \
        "HOME = 2" \
        "UP = 3" \
        "DOWN = 4" \
        "LEFT = 5" \
        "RIGHT = 6" \
        "SELECT = 7"

namespace ui
    enum EventType BUTTON_DOWN BUTTON_UP

    enum PopupTransitionState NONE OPENING CLOSING

    enum PenMode OFF ON

    struct Event "EventType" type "union {input::Button button;}" data

    class Icon
        constructor

        method "void" setPixel "unsigned int" x "unsigned int" y "ENUM ui::PenMode" value

    class Screen
        PASS_PROCESS=true constructor

        method "void" clear
        method "void" setPosition "unsigned int" column "unsigned int" row
        method "void" setPixel "unsigned int" x "unsigned int" y "ENUM ui::PenMode" value
        INTERNAL_NAME=dc_ui_Screen_printChar method "void" print "char" c
        method "void" print "char*" chars
        INTERNAL_NAME=dc_ui_Screen_printIcon method "void" print "CLASS ui::Icon" icon
        method "void" printRepeated "String" string "unsigned int" times
        method "void" scroll "String" string "unsigned int" maxLength
        method "void" resetScroll
        method "void" rect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "ENUM ui::PenMode" value
        method "void" filledRect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "ENUM ui::PenMode" value

        callable "void" update
        callable "void" handleEvent "ui::Event" event

        method "void" open "bool" urgent
        method "void" close
        method "void" swapWith "CLASSPTR ui::Screen" currentScreen

namespace test
    class TestClass
        constructor "unsigned int" seed

        method "unsigned int" add "unsigned int" value "unsigned int" value2
        method "void" bools "bool" a "bool" b "bool" c
        method "unsigned int" nextRandomNumber