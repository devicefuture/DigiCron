#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HCMS39xx.h"
#include "font5x7.h"

#include "time.h"

#define DATA_PIN A0
#define RS_PIN A1
#define CLOCK_PIN A2
#define ENABLE_PIN A3
#define RESET_PIN A4

#define BACK_BTN_PIN 6
#define HOME_BTN_PIN 5
#define JOY_UP_PIN 10
#define JOY_DOWN_PIN 12
#define JOY_LEFT_PIN 9
#define JOY_RIGHT_PIN 11
#define JOY_SELECT_PIN 13

HCMS39xx display(16, DATA_PIN, RS_PIN, CLOCK_PIN, ENABLE_PIN);

time::EarthTime timeKeeper(2024, 1, 1, 0, 0, 0);

long lastMillis = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, world!");

    pinMode(BACK_BTN_PIN, INPUT_PULLUP);
    pinMode(HOME_BTN_PIN, INPUT_PULLUP);
    pinMode(JOY_UP_PIN, INPUT_PULLUP);
    pinMode(JOY_DOWN_PIN, INPUT_PULLUP);
    pinMode(JOY_LEFT_PIN, INPUT_PULLUP);
    pinMode(JOY_RIGHT_PIN, INPUT_PULLUP);
    pinMode(JOY_SELECT_PIN, INPUT_PULLUP);

    display.begin();
    display.clear();
    display.displayUnblank();
    display.setBrightness(7);
    display.print("Hello, world! :)");

    delay(3000);
}

void loop() {
    long currentMillis = millis();

    if (currentMillis - lastMillis > 100) {
        timeKeeper.incrementTime(currentMillis - lastMillis);

        lastMillis = currentMillis;
    }

    char timeString[17];

    snprintf(timeString, 17, "%02d/%02d/%02d%02d:%02d:%02d",
        timeKeeper.day() % 100,
        timeKeeper.month() % 100,
        timeKeeper.year() % 100,
        timeKeeper.hour() % 100,
        timeKeeper.minute() % 100,
        timeKeeper.second() % 100
    );

    if (digitalRead(BACK_BTN_PIN) == LOW) {
        display.print("Button      BACK");
    } else if (digitalRead(HOME_BTN_PIN) == LOW) {
        display.print("Button      HOME");
    } else if (digitalRead(JOY_UP_PIN) == LOW) {
        display.print("Button        UP");
    } else if (digitalRead(JOY_DOWN_PIN) == LOW) {
        display.print("Button      DOWN");
    } else if (digitalRead(JOY_LEFT_PIN) == LOW) {
        display.print("Button      LEFT");
    } else if (digitalRead(JOY_RIGHT_PIN) == LOW) {
        display.print("Button     RIGHT");
    } else if (digitalRead(JOY_SELECT_PIN) == LOW) {
        display.print("Button    SELECT");
    } else {
        display.print(timeString);
    }
}