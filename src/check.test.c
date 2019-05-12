#include <stdlib.h>
#include <assert.h>
#include <check.h>
#include "test_suite.h"

/* The basic unit test looks as follows: */
START_TEST (idiotic_test) {
  /* unit test code */
    const char* mikko = "MIKKO";
    ck_assert_str_eq(mikko, "MIKKO");
    /* ck_assert_str_eq(mikko, "MAKKO"); */
}
END_TEST

START_TEST (second_idiotic_test) {
    const char* mikko = "MIKKO";
    ck_assert_str_eq(mikko, "MIKKO");
    /* ck_assert_str_eq(mikko, "MOKKO"); */
}
END_TEST

void add_tests(size_t const n, void const* tests[n]) {
    assert(n > 0);
    tests[0] = idiotic_test;
    tests[1] = second_idiotic_test;
}

