#ifndef RUBIK_TEST_SUITE_H
#define RUBIK_TEST_SUITE_H

#include "project.h"
#include <check.h>

#define MAX_TESTS_IN_SUITE 20
void add_tests(size_t const n, TTest const * tests[n]);

#endif

