#include "time.h"

int daysInEarthMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

time::Time::Time(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second) {
    _year = 0;
    _dayOfYear = 0;
    _millisecondOfDay = 0;

    setDate(year, month, day);
    setTime(hour, minute, second);
}

bool time::Time::inLeapMillisecond() {
    return _millisecondOfDay >= millisecondsInDay() - leapMillisecondsInDay();
}

void time::Time::setDate(int year, unsigned int month, unsigned int day) {
    if (year > 0) {
        year--;
    }

    _year = year;
    _dayOfYear = 0;

    day--;

    for (unsigned int currentMonth = 1; currentMonth < month; currentMonth++) {
        _dayOfYear += daysInMonth(currentMonth);
    }

    _dayOfYear += day;

}

void time::Time::setTime(unsigned int hour, unsigned int minute, unsigned int second) {
    _millisecondOfDay = 0;
    _millisecondOfDay += hour * 60 * 60 * 1000;
    _millisecondOfDay += minute * 60 * 1000;
    _millisecondOfDay += second * 1000;

    _accumulateDays();
}

void time::Time::incrementTime(unsigned int milliseconds) {
    _millisecondOfDay += milliseconds;

    _accumulateDays();
}

int time::Time::year() {
    return _year >= 0 ? _year + 1 : _year;
}

unsigned int time::Time::month() {
    int currentDay = _dayOfYear;
    unsigned int currentMonth = 1;

    while (true) {
        int daysInThisMonth = daysInMonth(currentMonth);

        if (currentDay < daysInThisMonth) {
            break;
        }

        currentMonth++;
        currentDay -= daysInThisMonth;
    }

    return currentMonth;
}

unsigned int time::Time::day() {
    unsigned int day = _dayOfYear;
    unsigned int dayMonth = month();

    for (unsigned int currentMonth = 1; currentMonth < dayMonth; currentMonth++) {
        day -= daysInMonth(currentMonth);
    }

    return day + 1;
}

unsigned int time::EarthTime::millisecondsInDay() {
    return time::Time::millisecondsInDay() + leapMillisecondsInDay();
}

int time::EarthTime::leapMillisecondsInDay() {
    if (dayOfYear() == 181 && year() == 2025) { // 30 June 2025
        return 1000;
    }

    return 0;
}

unsigned int time::Time::hour() {
    if (inLeapMillisecond()) {
        return 23;
    }

    return (_millisecondOfDay / 1000 / 60 / 60) % 24;
}

unsigned int time::Time::minute() {
    if (inLeapMillisecond()) {
        return 59;
    }

    return (_millisecondOfDay / 1000 / 60) % 60;
}

unsigned int time::Time::second() {
    if (inLeapMillisecond()) {
        return 60 + ((_millisecondOfDay - ((millisecondsInDay() - leapMillisecondsInDay()))) / 1000);
    }

    return (_millisecondOfDay / 1000) % 60;
}

unsigned int time::Time::dayOfYear() {
    return _dayOfYear + 1;
}

void time::Time::_accumulateDays() {
    while (_millisecondOfDay >= millisecondsInDay()) {
        _millisecondOfDay -= millisecondsInDay();
        _dayOfYear++;

        _accumulateYears();
    }
}

#include <Arduino.h>
void time::Time::_accumulateYears() {
    while (_dayOfYear >= daysInYear()) {
        _dayOfYear -= daysInYear();
        _year++;
    }
}

unsigned int time::EarthTime::daysInYear()
{
    unsigned int y = _year + 1;

    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        return 366;
    }

    return 365;
}

unsigned int time::EarthTime::daysInMonth(unsigned int month) {
    if (daysInYear() == 366 && month == 2) {
        return 29;
    }

    return daysInEarthMonth[(month - 1) % 12];
}

unsigned int time::EarthTime::hour() {
    return time::Time::hour();
}

unsigned int time::EarthTime::minute() {
    return time::Time::minute();
}

unsigned int time::EarthTime::second() {
    return time::Time::second();
}

// @source reference https://stackoverflow.com/a/53155217
unsigned int time::EarthTime::weekday() {
    int y = year();
    int m = month();
    int d = day();
    static int offsets[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (m < 3) {
        y--;
    }

    return (y + (y / 4) - (y / 100) + (y / 400) + offsets[m - 1] + d) % 7;
}