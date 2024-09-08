#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HCMS39xx.h"
#include "font5x7.h"

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
}

void loop() {
    if (digitalRead(BACK_BTN_PIN) == LOW) {
        display.print("12:34:56    BACK");
    } else if (digitalRead(HOME_BTN_PIN) == LOW) {
        display.print("12:34:56    HOME");
    } else if (digitalRead(JOY_UP_PIN) == LOW) {
        display.print("12:34:56      UP");
    } else if (digitalRead(JOY_DOWN_PIN) == LOW) {
        display.print("12:34:56    DOWN");
    } else if (digitalRead(JOY_LEFT_PIN) == LOW) {
        display.print("12:34:56    LEFT");
    } else if (digitalRead(JOY_RIGHT_PIN) == LOW) {
        display.print("12:34:56   RIGHT");
    } else if (digitalRead(JOY_SELECT_PIN) == LOW) {
        display.print("12:34:56  SELECT");
    }
}