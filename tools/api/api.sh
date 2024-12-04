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

namespace ui
    enum EventType BUTTON_DOWN BUTTON_UP

    enum PopupTransitionState NONE OPENING CLOSING

    enum PenMode OFF ON

    class Icon
        constructor

        method "void" setPixel "unsigned int" x "unsigned int" y "ENUM ui::PenMode" value

    class Screen
        constructor

        method "void" clear
        method "void" setPosition "unsigned int" column "unsigned int" row
        method "void" setPixel "unsigned int" x "unsigned int" y "ENUM ui::PenMode" value
        INTERNAL_NAME=dc_ui_Screen_printName method "void" print "char" c
        method "void" print "char*" chars
        INTERNAL_NAME=dc_ui_Screen_printIcon method "void" print "CLASS ui::Icon" icon
        method "void" printRepeated "STRING" string "unsigned int" times
        method "void" scroll "STRING" string "unsigned int" maxLength
        method "void" resetScroll
        method "void" rect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "ENUM ui::PenMode" value
        method "void" filledRect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "ENUM ui::PenMode" value

        method "void" open "bool" urgent
        method "void" close
        method "void" swapWith "CLASSPTR ui::Screen" currentScreen

namespace test
    class TestClass
        constructor "unsigned int" seed

        method "unsigned int" nextRandomNumber