#include <stdlib.h>
#include <assert.h>
#include <check.h>
#include "../../test_suite.h"
#include "core.h"

START_TEST (testCreateRubik) {
    struct Rubik* r = CreateRubik(3);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);
    DiscardRubik(r);
}
END_TEST

START_TEST (testTurnSquare90Degrees) {
    struct Rubik* r = CreateRubik(3);
    PutColour(r, Sqr_2, Row_1, Col_1, Orange);
    PutColour(r, Sqr_2, Row_1, Col_2, Orange);
    PutColour(r, Sqr_2, Row_1, Col_3, Orange);
    PutColour(r, Sqr_2, Row_3, Col_1, Red);
    PutColour(r, Sqr_2, Row_3, Col_2, Red);
    PutColour(r, Sqr_2, Row_3, Col_3, Red);
    PutColour(r, Sqr_2, Row_2, Col_1, Yellow);
    PutColour(r, Sqr_2, Row_2, Col_2, White);
    PutColour(r, Sqr_2, Row_2, Col_3, Yellow);
    TurnSquare90DegreesClockWise(r, Sqr_2);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Orange);
    TurnSquare90DegreesClockWise(r, Sqr_2);
    TurnSquare90DegreesClockWise(r, Sqr_2);
    TurnSquare90DegreesClockWise(r, Sqr_2);
    /* Starting values again */
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Yellow);
    DiscardRubik(r);
}
END_TEST

START_TEST (testTurnRowLeft) {
    struct Rubik* r = CreateRubik(3);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    TurnRowLeft(r, Turn_Row_2);

    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);
    /* Starting values again */
    TurnRowLeft(r, Turn_Row_2);
    TurnRowLeft(r, Turn_Row_2);
    TurnRowLeft(r, Turn_Row_2);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    TurnRowLeft(r, Turn_Row_1);

    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    DiscardRubik(r);
}
END_TEST

START_TEST (testTurnColumnUp) {
    struct Rubik* r = CreateRubik(3);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    TurnColumnUp(r, Turn_Col_2);

    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);
    /* Starting values again */
    TurnColumnUp(r, Turn_Col_2);
    TurnColumnUp(r, Turn_Col_2);
    TurnColumnUp(r, Turn_Col_2);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    TurnColumnUp(r, Turn_Col_1);

    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == White);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    DiscardRubik(r);
}
END_TEST

START_TEST (testFillSquareWithColour) {
    struct Rubik* r = malloc(sizeof(struct Rubik));
    FillSquareWithColour(r, Sqr_1, White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_1, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_2, Col_3) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_1) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_2) == White);
    ck_assert(GetColour(r, Sqr_1, Row_3, Col_3) == White);
    FillSquareWithColour(r, Sqr_2, Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_1, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_2, Col_3) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_1) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_2) == Green);
    ck_assert(GetColour(r, Sqr_2, Row_3, Col_3) == Green);
    FillSquareWithColour(r, Sqr_3, Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_1, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_2, Col_3) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_1) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_2) == Red);
    ck_assert(GetColour(r, Sqr_3, Row_3, Col_3) == Red);
    FillSquareWithColour(r, Sqr_4, Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_1, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_2, Col_3) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_1) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_2) == Blue);
    ck_assert(GetColour(r, Sqr_4, Row_3, Col_3) == Blue);
    FillSquareWithColour(r, Sqr_5, Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_1, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_2, Col_3) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_1) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_2) == Orange);
    ck_assert(GetColour(r, Sqr_5, Row_3, Col_3) == Orange);
    FillSquareWithColour(r, Sqr_6, Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_1, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_2, Col_3) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_1) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_2) == Yellow);
    ck_assert(GetColour(r, Sqr_6, Row_3, Col_3) == Yellow);

    free(r);
}
END_TEST

// cppcheck-suppress unusedFunction
void add_tests(size_t const n, TFun tests[n]) {
    assert(n > 0);
    tests[0] = testCreateRubik;
    tests[1] = testTurnSquare90Degrees;
    tests[2] = testTurnColumnUp;
    tests[3] = testFillSquareWithColour;
    tests[4] = testTurnRowLeft;
}


