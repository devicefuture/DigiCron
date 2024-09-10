#ifndef TIME_H_
#define TIME_H_

namespace time {
    class Time {
        public:
            Time(int year, unsigned int month, unsigned int day, unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);

            virtual unsigned int daysInYear() {return 1;}
            virtual unsigned int daysInMonth(unsigned int month) {return daysInYear();}
            virtual unsigned int millisecondsInDay() {return 24 * 60 * 60 * 1000;}
            virtual int leapMillisecondsInDay() {return 0;}

            bool inLeapMillisecond();

            void setDate(int year, unsigned int month, unsigned int day);
            void setTime(unsigned int hour, unsigned int minute, unsigned int second);
            void incrementTime(unsigned int milliseconds);

            virtual int year();
            virtual unsigned int month();
            virtual unsigned int day();
            virtual unsigned int hour();
            virtual unsigned int minute();
            virtual unsigned int second();

            unsigned int dayOfYear();
            virtual unsigned int weekday() {return 0;}

        protected:
            int _year;
            unsigned int _dayOfYear;
            unsigned long _millisecondOfDay;

            void _accumulateDays();
            void _accumulateYears();
    };

    class EarthTime : public Time {
        public:
            EarthTime(int year, unsigned int month, unsigned int day, unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0) : Time(year, month, day, hour, minute, second) {
                setDate(year, month, day);
                setTime(hour, minute, second);
            };

            unsigned int daysInYear() override;
            unsigned int daysInMonth(unsigned int month) override;
            unsigned int millisecondsInDay() override;
            int leapMillisecondsInDay() override;

            unsigned int hour() override;
            unsigned int minute() override;
            unsigned int second() override;

            unsigned int weekday() override;
    };
}

#endif