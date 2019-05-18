#include <stdlib.h>
#include <assert.h>
#include <check.h>
#include "../../test_suite.h"
#include "core.h"

START_TEST (testCreateRubik) {
    struct Rubik* r = CreateRubik(3);
    ck_assert(GetColour(r, Sqr_1, Row_1, col_1) == White);
    ck_assert(GetColour(r, Sqr_3, Row_2, col_2) == Red);
    ck_assert(GetColour(r, Sqr_6, Row_3, col_3) == Yellow);
    /* TurnRubik(r, Row_2, (void*) 0, Left); */
    /* ck_assert(GetColour(r, Sqr_1, Row_1, col_1) == White); */
    /* ck_assert(GetColour(r, Sqr_3, Row_2, col_2) == Blue); */
    /* ck_assert(GetColour(r, Sqr_6, Row_3, col_3) == Yellow); */
    DiscardRubik(r);
}
END_TEST

START_TEST (testTurnSquare90Degrees) {
    struct Rubik* r = CreateRubik(3);
    ck_assert(GetColour(r, Sqr_1, Row_1, col_1) == White);
    ck_assert(GetColour(r, Sqr_3, Row_2, col_2) == Red);
    ck_assert(GetColour(r, Sqr_6, Row_3, col_3) == Yellow);
    PutColour(r, Sqr_1, Row_1, col_1, Orange);
    PutColour(r, Sqr_1, Row_1, col_2, Orange);
    PutColour(r, Sqr_1, Row_1, col_3, Orange);
    PutColour(r, Sqr_1, Row_3, col_1, Red);
    PutColour(r, Sqr_1, Row_3, col_2, Red);
    PutColour(r, Sqr_1, Row_3, col_3, Red);
    PutColour(r, Sqr_1, Row_2, col_1, Yellow);
    PutColour(r, Sqr_1, Row_2, col_2, White);
    PutColour(r, Sqr_1, Row_2, col_3, Yellow);
    TurnSquare90DegreesClockWise(r, Sqr_1);
    ck_assert(GetColour(r, Sqr_1, Row_1, col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_1, col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_1, Row_1, col_3) == Orange);
    ck_assert(GetColour(r, Sqr_1, Row_3, col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_3, col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_1, Row_3, col_3) == Orange);
    ck_assert(GetColour(r, Sqr_1, Row_2, col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_2, col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, col_3) == Orange);
}
END_TEST

// cppcheck-suppress unusedFunction
void add_tests(size_t const n, void const* tests[n]) {
    assert(n > 0);
    tests[0] = testCreateRubik;
    tests[1] = testTurnSquare90Degrees;
}


