#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "HCMS39xx.h"
#include "font5x7.h"

#define DATA_PIN A0
#define RS_PIN A1
#define CLOCK_PIN A2
#define ENABLE_PIN A3
#define RESET_PIN A4

HCMS39xx display(16, DATA_PIN, RS_PIN, CLOCK_PIN, ENABLE_PIN);

char displayData[16 * 5];

void setup() {
    Serial.begin(115200);

    display.begin();
    display.clear();
    display.displayUnblank();
}

void fadeOut() {
    for (unsigned int i = 15; i != 0; i--) {
        display.setBrightness(i);
        delay(100);
    }
}

void fadeIn() {
    for (unsigned int i = 0; i <= 15; i++) {
        display.setBrightness(i);
        delay(100);
    }
}

void loop() {
    Serial.println("Hello, world!");

    display.clear();
    display.print("Hello, world! :)");

    fadeIn();
    delay(2000);
    fadeOut();

    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = i % 2 == 0 ? 0b01010101 : 0b10101010;
    }

    display.printDirect((uint8_t*)displayData, sizeof(displayData));

    fadeIn();
    delay(2000);
    fadeOut();

    for (unsigned int i = 0; i < sizeof(displayData); i++) {
        displayData[i] = i % 2 == 1 ? 0b01010101 : 0b10101010;
    }

    display.printDirect((uint8_t*)displayData, sizeof(displayData));

    fadeIn();
    delay(2000);
    fadeOut();
}