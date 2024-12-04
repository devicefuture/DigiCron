#include <Arduino.h>

#include "test.h"

test::TestClass::TestClass(unsigned int seed) {
    Serial.println("Hello from the test class!");

    _counter = seed * 123;
}

test::TestClass::TestClass() {
    TestClass(0);
}

unsigned int test::TestClass::nextRandomNumber() {
    unsigned int number = (_counter++) * 3 + (_counter += _counter % 11) * 8;

    Serial.printf("The next random number is: %d\n", number);

    return number;
}