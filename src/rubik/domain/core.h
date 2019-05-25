#ifndef RUBIK_DOMAIN_CORE
#define RUBIK_DOMAIN_CORE
#include <stddef.h>
#include <stdbool.h>

/**
 * The colours of the Rubik's cube.
 */
typedef enum {
    White = 0, Red, Blue, Orange, Green, Yellow, Nr_of
        /* W, R, B, O, G, Y */
} R_colour;

/* Geometry */
typedef enum {
    Sqr_1 = 0, Sqr_2, Sqr_3, Sqr_4, Sqr_5, Sqr_6, Sqr_nr_of
} R_square;
typedef enum {
    Row_1 = 0, Row_2, Row_3, Row_nr_of
} R_row;
typedef enum {
    Col_1 = 0, Col_2, Col_3, Col_nr_of
} R_column;

/* Turning */
typedef enum {
    Turn_Col_1, Turn_Col_2, Turn_Col_3, Turn_Row_1, Turn_Row_2, Turn_Row_3
} R_turn;
typedef enum {
    Left, Right, Up, Down, NoDir
} R_dir;
char const * R_dir_as_string(R_dir const dir);

/**
 * Represents a Rubik.
 */
struct Rubik {
    size_t len;
    R_colour con[6][3][3];
};

/* Internal functions */
void PutColour(struct Rubik* const r, R_square const square, R_row const row, R_column const col, R_colour const colour);
void FillSquareWithColour(struct Rubik* const r, R_square const sqr, R_colour const c); void TurnSquare90DegreesClockWise(struct Rubik* const r, R_square const sqr);
void TurnSquare90DegreesAntiClockWise(struct Rubik* const r, R_square const sqr);
void TurnRowLeft(struct Rubik* const r, R_turn const t);
void TurnRowRight(struct Rubik* const r, R_turn const t);
void TurnColumnUp(struct Rubik* const r, R_turn const t);
void TurnColumnDown(struct Rubik* const r, R_turn const t);
bool AssertRubik(struct Rubik* const r);

/**
 * Get an individual colour.
 */
R_colour GetColour(struct Rubik const* const r, R_square const square, R_row const row, R_column const col);
/**
 * Starting point:
 *   Colours         Squares
 *    WWW
 *    WWW              1
 *    WWW
 * GGGRRRBBBOOO
 * GGGRRRBBBOOO     2  3  4  5
 * GGGRRRBBBOOO
 *    YYY
 *    YYY              6
 *    YYY
 */

/**
 * Allocate memory for the struct Rubik.
 */
struct Rubik* CreateRubik(size_t const len);

/**
 * Discard the struct Rubik, deallocate memory
 * and finalize.
 */
void DiscardRubik(struct Rubik *rubik);

/**
 * Make a move on the Rubik's Cube.
 * Select 1st, 2nd or 3rd column or row.
 * Turn left, right, up, down;
 *
 * Row 1
 * Row 2
 * Row 3
 *      CCC
 *      ooo
 *      lll
 *      123
 */
void TurnRubik(struct Rubik* const r, R_turn const t, R_dir const d);
#endif

