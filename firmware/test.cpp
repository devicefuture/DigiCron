#include <Arduino.h>

#include "test.h"

test::TestClass::TestClass(unsigned int seed) {
    Serial.println("Hello from the test class!");

    _counter = seed;
}

test::TestClass::TestClass() {
    TestClass(0);
}

unsigned int test::TestClass::add(unsigned int value, unsigned int value2) {
    Serial.printf("Add method called with values %d and %d\n", value, value2);

    return value + value2;
}

void test::TestClass::bools(bool a, bool b, bool c) {
    Serial.printf("Bools: %d%d%d\n", a, b, c);
}

unsigned int test::TestClass::nextRandomNumber() {
    unsigned int number = (_counter++) * 3 + (_counter += _counter % 11) * 8;

    Serial.printf("The next random number is: %d\n", number);

    return number;
}