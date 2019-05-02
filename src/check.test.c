#include <check.h>
#include <stdlib.h>

/* The basic unit test looks as follows: */
START_TEST (test_name) {
  /* unit test code */
    const char* mikko = "MIKKO";
    ck_assert_str_eq(mikko, "MIKKO");
    ck_assert_str_eq(mikko, "MAKKO");
}
END_TEST

Suite * money_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Money");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_name);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

