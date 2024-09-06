#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "LedDisplay.h"

#define DATA_PIN A0
#define RS_PIN A1
#define CLOCK_PIN A2
#define ENABLE_PIN A3
#define RESET_PIN A4

LedDisplay display = LedDisplay(DATA_PIN, RS_PIN, CLOCK_PIN, ENABLE_PIN, RESET_PIN, 16);

const char* message = "This is a demo of two HCMS-3917 displays! :)";
String messageString = message;

int scrolledBy = 16;

void setup() {
    Serial.begin(115200);

    display.begin();
    display.clear();

    display.home();
    display.setString(message);
    display.setBrightness(7);
    display.scroll(16);
}

void loop() {
    Serial.println("Hello, world!");

    display.scroll(-1);

    scrolledBy--;

    delay(250);

    if (-scrolledBy > (int)messageString.length()) {
        while (scrolledBy < 16) {
            display.scroll(1);

            scrolledBy++;

            delay(50);
        }
    }
}