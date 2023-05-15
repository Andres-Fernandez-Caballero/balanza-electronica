#include <unity.h>
#include "History.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_should_create_history() {
    History history = History();

    int howManyRecords = history.howManyRecords();
    TEST_ASSERT_EQUAL(howManyRecords, 0);
}

void test_should_add_record() {
    History history = History();

    history.add(1.2);
    int howManyRecords = history.howManyRecords();
    TEST_ASSERT_EQUAL(howManyRecords, 1);

    history.add(2.3);
    howManyRecords = history.howManyRecords();
    TEST_ASSERT_EQUAL(howManyRecords, 2);
}

void test_should_get_record() {
    History history = History();

    history.add(1.2);
    float record = history.get(0);
    TEST_ASSERT_EQUAL(record, 1.2);

    history.add(2.3);
    record = history.get(1);
    TEST_ASSERT_EQUAL(record, 2.3);
}

void test_should_clear_history() {
    History history = History();

    history.add(1.2);
    history.add(2.3);
    int howManyRecords = history.howManyRecords();
    TEST_ASSERT_EQUAL(howManyRecords, 2);

    history.clear();
    howManyRecords = history.howManyRecords();
    TEST_ASSERT_EQUAL(howManyRecords, 0);
}

void test_should_get_last_record() {
    History history = History();

    history.add(1.2);
    history.add(2.3);
    float lastRecord = history.getLast();
    TEST_ASSERT_EQUAL(lastRecord, 2.3);
}

void test_should_calculate_total() {
    History history = History();

    history.add(1.2);
    history.add(2.3);
    float total = history.calculateTotal();
    TEST_ASSERT_EQUAL(total, 3.5);

    history.add(3.4);
    total = history.calculateTotal();
    TEST_ASSERT_EQUAL(total, 6.9);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_should_create_history);
    RUN_TEST(test_should_add_record);
    RUN_TEST(test_should_get_record);
    RUN_TEST(test_should_clear_history);
    RUN_TEST(test_should_get_last_record);
    RUN_TEST(test_should_calculate_total);
    UNITY_END();
    
}

void loop() {}