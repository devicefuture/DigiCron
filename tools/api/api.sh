#!/bin/bash

namespace timing
    class EarthTime
        method "unsigned int" daysInYear
        method "unsigned int" daysInMonth
        method "unsigned long" millisecondsInDay
        method "struct LeapAdjustment" leapAdjustmentToday

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
        method "void" setPixel "unsigned int" x "unsigned int" y "PenMode" value

    class Screen
        method "void" clear
        method "void" setPosition "unsigned int" column "unsigned int" row
        method "void" setPixel "unsigned int" x "unsigned int" y "PenMode" value
        method "void" print "char" c
        method "void" print "char*" chars
        method "void" print "String" string
        method "void" print "Icon" icon
        method "void" printRepeated "String" string "unsigned int" times
        method "void" scroll "String" string "unsigned int" maxLength
        method "void" resetScroll
        method "void" rect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "PenMode" value
        method "void" filledRect "unsigned int" x1 "unsigned int" y1 "unsigned int" x2 "unsigned int" y2 "PenMode" value

        method "void" open "bool" urgent
        method "void" close
        method "void" swapWith "Screen*" currentScreen