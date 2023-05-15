#include <unity.h>
#include "Display_number.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_should_create_display_number() {
    DisplayNumber displayNumber = DisplayNumber();

    float value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 0.00);
}

void test_shoud_add_digit() {
    DisplayNumber displayNumber = DisplayNumber();

    displayNumber.addDigit(1);
    float value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 1.00);

    displayNumber.addDigit(2);
    value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 12.00);
}

void test_shoud_add_decimal() {
    DisplayNumber displayNumber = DisplayNumber();

    displayNumber.addDigit(1);
    displayNumber.addDecimal(2);
    float value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 1.20);

    displayNumber.addDigit(5);
    value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 15.2);


    displayNumber.addDecimal(4);
    value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 15.24);
}

void test_should_clear_display_number() {
    DisplayNumber displayNumber = DisplayNumber();

    displayNumber.addDigit(1);
    displayNumber.addDecimal(2);
    float value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 1.20);

    displayNumber.clear();
    value = displayNumber.getValue();
    TEST_ASSERT_EQUAL(value, 0.00);
}


void setup() {
    
    UNITY_BEGIN();
    RUN_TEST(test_should_create_display_number);
    RUN_TEST(test_shoud_add_digit);
    RUN_TEST(test_shoud_add_decimal);
    RUN_TEST(test_should_clear_display_number);
    UNITY_END();
}

void loop() {}