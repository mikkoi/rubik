/**
 * https://en.wikipedia.org/wiki/Rubik's_Cube
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "core.h"

void PutColour(struct Rubik* const r, R_square const square, R_row const row, R_column const col, R_colour const colour) {
    r->con[square][row][col] = colour;
}

R_colour GetColour(struct Rubik const* const r, R_square const square, R_row const row, R_column const col) {
    return r->con[square][row][col];
}

/* Only used during initialization */
void FillSquareWithColour(struct Rubik* const r, R_square const sqr, R_colour const c) {
    for(R_row row = Row_1; row <= Row_3; ++row) {
        for(R_column col = Col_1; col <= Col_3; ++col) {
            /* r->con[sqr][row][col] = c; */
            PutColour(r, sqr, row, col, c);
        }
    }
}

/* Only used when turning col1/col3/row1/row3 */
/* Turn clockwise */
static void TurnSquare90Degrees(struct Rubik* const r, R_square const sqr) {
    R_colour tmp[3] = { 0 };
    tmp[Col_1] = GetColour(r, sqr, Row_1, Col_1);
    tmp[Col_2] = GetColour(r, sqr, Row_1, Col_2);
    tmp[Col_3] = GetColour(r, sqr, Row_1, Col_3);
    PutColour(r, sqr, Row_1, Col_1, GetColour(r, sqr, Row_3, Col_1));
    PutColour(r, sqr, Row_1, Col_2, GetColour(r, sqr, Row_2, Col_1));
    PutColour(r, sqr, Row_1, Col_3, GetColour(r, sqr, Row_1, Col_1));

    PutColour(r, sqr, Row_1, Col_1, GetColour(r, sqr, Row_3, Col_1));
    PutColour(r, sqr, Row_2, Col_1, GetColour(r, sqr, Row_3, Col_2));
    PutColour(r, sqr, Row_3, Col_1, GetColour(r, sqr, Row_3, Col_3));
    
    PutColour(r, sqr, Row_3, Col_1, GetColour(r, sqr, Row_3, Col_3));
    PutColour(r, sqr, Row_3, Col_2, GetColour(r, sqr, Row_2, Col_3));
    PutColour(r, sqr, Row_3, Col_3, GetColour(r, sqr, Row_1, Col_3));

    PutColour(r, sqr, Row_1, Col_3, tmp[Col_1]);
    PutColour(r, sqr, Row_2, Col_3, tmp[Col_2]);
    PutColour(r, sqr, Row_3, Col_3, tmp[Col_3]);
}

void TurnSquare90DegreesClockWise(struct Rubik* const r, R_square const sqr) {
    TurnSquare90Degrees(r, sqr);
}

void TurnSquare90DegreesAntiClockWise(struct Rubik* const r, R_square const sqr) {
    TurnSquare90Degrees(r, sqr);
    TurnSquare90Degrees(r, sqr);
    TurnSquare90Degrees(r, sqr);
}

void TurnColumn(struct Rubik* const r, R_turn const t) {
    assert(Turn_Row_1 == t || Turn_Row_2 == t || Turn_Row_3 == t);
    R_colour tmp[3] = { 0 };
    R_row row = (R_row) t - 3;
    tmp[Col_1] = GetColour(r, Sqr_2, row, Col_1);
    tmp[Col_2] = GetColour(r, Sqr_2, row, Col_2);
    tmp[Col_3] = GetColour(r, Sqr_2, row, Col_3);
    PutColour(r, Sqr_2, row, Col_1, GetColour(r, Sqr_3, row, Col_1));
    PutColour(r, Sqr_2, row, Col_2, GetColour(r, Sqr_3, row, Col_2));
    PutColour(r, Sqr_2, row, Col_3, GetColour(r, Sqr_3, row, Col_2));

    PutColour(r, Sqr_3, row, Col_1, GetColour(r, Sqr_4, row, Col_1));
    PutColour(r, Sqr_3, row, Col_2, GetColour(r, Sqr_4, row, Col_2));
    PutColour(r, Sqr_3, row, Col_3, GetColour(r, Sqr_4, row, Col_3));
    
    PutColour(r, Sqr_4, row, Col_1, GetColour(r, Sqr_5, row, Col_1));
    PutColour(r, Sqr_4, row, Col_2, GetColour(r, Sqr_5, row, Col_2));
    PutColour(r, Sqr_4, row, Col_3, GetColour(r, Sqr_5, row, Col_3));

    PutColour(r, Sqr_5, row, Col_1, tmp[Col_1]);
    PutColour(r, Sqr_5, row, Col_2, tmp[Col_2]);
    PutColour(r, Sqr_5, row, Col_3, tmp[Col_3]);
}
void TurnColumnLeft(struct Rubik* const r, R_turn const t) {
    TurnColumn(r, t);
}
void TurnColumnRight(struct Rubik* const r, R_turn const t) {
    TurnColumn(r, t);
    TurnColumn(r, t);
    TurnColumn(r, t);
}

void TurnRow(struct Rubik* const r, R_turn const t) {
    assert(Turn_Col_1 == t || Turn_Col_2 == t || Turn_Col_3 == t);
    R_colour tmp[3] = { 0 };
    R_column col = (R_column) t;

    /* the order of copy is: tmp <- Sqr_1 <- Sqr_3 <- Sqr_6 <- Sqr_5 <- tmp */
    tmp[Row_1] = GetColour(r, Sqr_1, col, Row_1);
    tmp[Row_2] = GetColour(r, Sqr_1, col, Row_2);
    tmp[Row_3] = GetColour(r, Sqr_1, col, Row_3);

    PutColour(r, Sqr_1, col, Row_1, GetColour(r, Sqr_3, col, Row_1));
    PutColour(r, Sqr_1, col, Row_2, GetColour(r, Sqr_3, col, Row_2));
    PutColour(r, Sqr_1, col, Row_3, GetColour(r, Sqr_3, col, Row_3));

    PutColour(r, Sqr_3, col, Row_1, GetColour(r, Sqr_6, col, Row_1));
    PutColour(r, Sqr_3, col, Row_2, GetColour(r, Sqr_6, col, Row_2));
    PutColour(r, Sqr_3, col, Row_3, GetColour(r, Sqr_6, col, Row_3));
    
    PutColour(r, Sqr_6, col, Row_1, GetColour(r, Sqr_5, col, Row_1));
    PutColour(r, Sqr_6, col, Row_2, GetColour(r, Sqr_5, col, Row_2));
    PutColour(r, Sqr_6, col, Row_3, GetColour(r, Sqr_5, col, Row_3));

    PutColour(r, Sqr_5, col, Row_1, tmp[Row_1]);
    PutColour(r, Sqr_5, col, Row_2, tmp[Row_2]);
    PutColour(r, Sqr_5, col, Row_3, tmp[Row_3]);
}
void TurnRowUp(struct Rubik* const r, R_turn const t) {
    TurnRow(r, t);
}
void TurnRowDown(struct Rubik* const r, R_turn const t) {
    TurnRow(r, t);
    TurnRow(r, t);
    TurnRow(r, t);
}

struct Rubik* CreateRubik(size_t const len) {
    assert(len == 3); /* Only allowed size now. */
    struct Rubik* r = malloc(sizeof(struct Rubik));
    if(!r) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    r->len = len;
    FillSquareWithColour(r, Sqr_1, White);
    FillSquareWithColour(r, Sqr_2, Green);
    FillSquareWithColour(r, Sqr_3, Red);
    FillSquareWithColour(r, Sqr_4, Blue);
    FillSquareWithColour(r, Sqr_5, Orange);
    FillSquareWithColour(r, Sqr_6, Yellow);
    return r;
}

void DiscardRubik(struct Rubik *rubik) {
    free(rubik);
}

void TurnRubik(struct Rubik* const r, R_turn const t, R_dir const d) {
    /* R_row const row, R_column const col,  */
    if(Left == d) {
        TurnColumnLeft(r, t);
        if(Turn_Col_1 == t || Turn_Col_3 == t) { /* Turn the edge squares */
            TurnSquare90DegreesClockWise(r, Sqr_1);
            TurnSquare90DegreesAntiClockWise(r, Sqr_6);
        }
    } else if(Right == d) {
        TurnColumnRight(r, t);
        if(Turn_Col_1 == t || Turn_Col_3 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_1);
            TurnSquare90DegreesClockWise(r, Sqr_6);
        }
    } else if(Up == d) {
        TurnRowUp(r, t);
        if(Turn_Row_1 == t || Turn_Row_3 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_2);
            TurnSquare90DegreesClockWise(r, Sqr_4);
        }
    } else if(Down == d) {
        TurnRowDown(r, t);
        if(Turn_Row_1 == t || Turn_Row_3 == t) {
            TurnSquare90DegreesClockWise(r, Sqr_2);
            TurnSquare90DegreesAntiClockWise(r, Sqr_4);
        }
    } else {
        assert(0);
    }
}

