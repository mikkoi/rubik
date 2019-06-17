/**
 * https://en.wikipedia.org/wiki/Rubik's_Cube
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "core.h"

char const* R_turn_strings[7] = {
    "Col 1", "Col 2", "Col 3", "Row 1", "Row 2", "Row 3", "NoTurn"
};
char const* R_turn_as_string(R_turn const t) {
    assert(0 <= t && t < 7);
    return R_turn_strings[t];
}
char const* R_dir_strings[5] = {
    "Left", "Right", "Up", "Down", "NoDir"
};
char const* R_dir_as_string(R_dir const d) {
    assert(0 <= d && d < 5);
    return R_dir_strings[d];
}
/* When undoing a turn, we need the opposite direction.
 * But not opposite col/row.*/
R_dir R_dir_opp[4] = { Right, Left, Down, Up };

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

/* Turning is always towards left */
static void TurnRow(struct Rubik* const r, R_turn const t) {
    assert(Turn_Row_1 == t || Turn_Row_2 == t || Turn_Row_3 == t);
    R_colour tmp[3] = { 0 };
    R_row row = (R_row) t - 3;
    tmp[Col_1] = GetColour(r, Sqr_2, row, Col_1);
    tmp[Col_2] = GetColour(r, Sqr_2, row, Col_2);
    tmp[Col_3] = GetColour(r, Sqr_2, row, Col_3);
    PutColour(r, Sqr_2, row, Col_1, GetColour(r, Sqr_3, row, Col_1));
    PutColour(r, Sqr_2, row, Col_2, GetColour(r, Sqr_3, row, Col_2));
    PutColour(r, Sqr_2, row, Col_3, GetColour(r, Sqr_3, row, Col_3));

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
void TurnRowLeft(struct Rubik* const r, R_turn const t) {
    TurnRow(r, t);
}
void TurnRowRight(struct Rubik* const r, R_turn const t) {
    TurnRow(r, t);
    TurnRow(r, t);
    TurnRow(r, t);
}

/* Turning is always upwards */
static void TurnColumn(struct Rubik* const r, R_turn const t) {
    assert(Turn_Col_1 == t || Turn_Col_2 == t || Turn_Col_3 == t);
    R_colour tmp[3] = { 0 };
    R_column col = (R_column) t;
    assert(Col_1 == col || Col_2 == col || Col_3 == col);

    /* the order of copy is: tmp <- Sqr_1 <- Sqr_3 <- Sqr_6 <- Sqr_5 <- tmp */
    tmp[Row_1] = GetColour(r, Sqr_1, Row_1, col);
    tmp[Row_2] = GetColour(r, Sqr_1, Row_2, col);
    tmp[Row_3] = GetColour(r, Sqr_1, Row_3, col);

    PutColour(r, Sqr_1, Row_1, col, GetColour(r, Sqr_3, Row_1, col));
    PutColour(r, Sqr_1, Row_2, col, GetColour(r, Sqr_3, Row_2, col));
    PutColour(r, Sqr_1, Row_3, col, GetColour(r, Sqr_3, Row_3, col));

    PutColour(r, Sqr_3, Row_1, col, GetColour(r, Sqr_6, Row_1, col));
    PutColour(r, Sqr_3, Row_2, col, GetColour(r, Sqr_6, Row_2, col));
    PutColour(r, Sqr_3, Row_3, col, GetColour(r, Sqr_6, Row_3, col));
    
    /* Sqr_5 is upside down, look at picture in core.h */
    if(Col_1 == col) {
        PutColour(r, Sqr_6, Row_1, Col_1, GetColour(r, Sqr_5, Row_3, Col_3));
        PutColour(r, Sqr_6, Row_2, Col_1, GetColour(r, Sqr_5, Row_2, Col_3));
        PutColour(r, Sqr_6, Row_3, Col_1, GetColour(r, Sqr_5, Row_1, Col_3));
        PutColour(r, Sqr_5, Row_3, Col_3, tmp[Row_1]);
        PutColour(r, Sqr_5, Row_2, Col_3, tmp[Row_2]);
        PutColour(r, Sqr_5, Row_1, Col_3, tmp[Row_3]);
    } else if(Col_3 == col) {
        PutColour(r, Sqr_6, Row_1, Col_3, GetColour(r, Sqr_5, Row_3, Col_1));
        PutColour(r, Sqr_6, Row_2, Col_3, GetColour(r, Sqr_5, Row_2, Col_1));
        PutColour(r, Sqr_6, Row_3, Col_3, GetColour(r, Sqr_5, Row_1, Col_1));
        PutColour(r, Sqr_5, Row_3, Col_1, tmp[Row_1]);
        PutColour(r, Sqr_5, Row_2, Col_1, tmp[Row_2]);
        PutColour(r, Sqr_5, Row_1, Col_1, tmp[Row_3]);
    } else /* Col_2 == col */ {
        PutColour(r, Sqr_6, Row_1, Col_2, GetColour(r, Sqr_5, Row_3, Col_2));
        PutColour(r, Sqr_6, Row_2, Col_2, GetColour(r, Sqr_5, Row_2, Col_2));
        PutColour(r, Sqr_6, Row_3, Col_2, GetColour(r, Sqr_5, Row_1, Col_2));
        PutColour(r, Sqr_5, Row_3, Col_2, tmp[Row_1]);
        PutColour(r, Sqr_5, Row_2, Col_2, tmp[Row_2]);
        PutColour(r, Sqr_5, Row_1, Col_2, tmp[Row_3]);
    }
}
void TurnColumnUp(struct Rubik* const r, R_turn const t) {
    TurnColumn(r, t);
}
void TurnColumnDown(struct Rubik* const r, R_turn const t) {
    TurnColumn(r, t);
    TurnColumn(r, t);
    TurnColumn(r, t);
}

bool AssertRubik(struct Rubik* const r) {
    size_t nr_colours[Nr_of] = { 0 };
    for(R_square sqr = Sqr_1; sqr < Sqr_nr_of; ++sqr) {
        for(R_row row = Row_1; row < Row_nr_of; ++row) {
            for(R_column col = Col_1; col < Col_nr_of; ++col) {
                nr_colours[r->con[sqr][row][col]] += 1;
            }
        }
    }
    for(R_colour colour = White; colour < Nr_of; ++colour) {
        if(nr_colours[colour] != 9)
            return false;
    }
    return true;
}

void SeedRandomRubikColour(unsigned int const seed) {
    srand(seed);
}

R_colour GetRandomRubikColour() {
    return (R_colour) ((unsigned long) rand() / ((RAND_MAX + 1UL) / 6UL));
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

/* Turn the edge squares, every one must be handled individually! I think! */
void TurnRubik(struct Rubik* const r, R_turn const t, R_dir const d) {
    if(Left == d) {
        TurnRowLeft(r, t);
        if(Turn_Row_1 == t) {
            TurnSquare90DegreesClockWise(r, Sqr_1);
        } else if(Turn_Row_3 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_6);
        }
    } else if(Right == d) {
        TurnRowRight(r, t);
        if(Turn_Row_1 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_1);
        } else if(Turn_Row_3 == t) {
            TurnSquare90DegreesClockWise(r, Sqr_6);
        }
    } else if(Up == d) {
        TurnColumnUp(r, t);
        if(Turn_Col_1 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_2);
        } else if(Turn_Col_3 == t) {
            TurnSquare90DegreesClockWise(r, Sqr_4);
        }
    } else if(Down == d) {
        TurnColumnDown(r, t);
        if(Turn_Col_1 == t) {
            TurnSquare90DegreesClockWise(r, Sqr_2);
        } else if(Turn_Col_3 == t) {
            TurnSquare90DegreesAntiClockWise(r, Sqr_4);
        }
    } else {
        assert(0);
    }
}

void ShuffleRubik(struct Rubik* const r) {
    assert(r);
    R_colour colours[6] = { 9, 9, 9, 9, 9, 9 };
    for(R_square sqr = Sqr_1; sqr < Sqr_nr_of; ++sqr)
        for(R_row row = Row_1; row < Row_nr_of; ++row)
            for(R_column col = Col_1; col < Col_nr_of; ++col) {
                GET_RANDOM:;
                R_colour colour = GetRandomRubikColour();
                assert(colour < Nr_of);
                if(0 == colours[colour]) /* All colours already used */
                    goto GET_RANDOM;
                colours[colour] -= 1;
                r->con[sqr][row][col] = colour;
            }
    for(int i = 0; i < 6; ++i)
        assert(0 == colours[i]); /* Double check we used all colours, 9 each */
}

static struct RubikTurnListNode* LastTurn(struct RubikGame* const game) {
    struct RubikTurnListNode* last_turn = (void*) 0;
    if(game->rbg_first_turn) {
        last_turn = game->rbg_first_turn;
        while(last_turn->rbtln_next) {
            last_turn = last_turn->rbtln_next;
        }
    }
    return last_turn;
}

struct RubikGame* StartRubikGame(void) {
    struct RubikGame* g = malloc(sizeof(struct RubikGame));
    if(!g) {
        perror("malloc"); exit(EXIT_FAILURE);
    }
    g->rbg_rubik = CreateRubik(3);
    g->rbg_first_turn = (void*) 0;
    /* g->rbg_first_player_turn = (void*) 0; */
    g->rbg_current_turn = (void*) 0;
    return g;
}

static struct RubikTurnListNode* RemoveTurnsFromEnd(struct RubikGame* g, struct RubikTurnListNode* until_turn) {
    struct RubikTurnListNode* last_turn = LastTurn(g);
    assert(last_turn);
    while(last_turn->rbtln_prev != until_turn) {
        last_turn = last_turn->rbtln_prev;
        free(last_turn->rbtln_next);
    }
    last_turn->rbtln_next = (void*) 0;
    return last_turn;
}

void FinishRubikGame(struct RubikGame* g) {
    DiscardRubik(g->rbg_rubik);
    /* Traverse list to the last node. */
    struct RubikTurnListNode* last_turn = (void*) 0;
    if(g->rbg_first_turn) {
        last_turn = g->rbg_first_turn;
        while(last_turn->rbtln_next) {
            last_turn = last_turn->rbtln_next;
        }
        /* We know the last node. Now we traverse backwards and free the nodes. */
        while(last_turn->rbtln_prev) {
            last_turn = last_turn->rbtln_prev;
            free(last_turn->rbtln_next);
        }
        free(g->rbg_first_turn);
    }
    g->rbg_first_turn = (void*) 0;
    g->rbg_current_turn = (void*) 0;
    free(g);
}

/* void ShuffleTurnRubikGame(struct RubikGame* const game) { */
/* } */

struct RubikTurn* PlayerTurnRubikGame(struct RubikGame* g, R_dir const d, R_turn const t) {
    /* Is the current turn, i.e. the previous turn, the last turn? */
    struct RubikTurnListNode* last_turn = LastTurn(g);
    struct RubikTurnListNode* curr_turn = g->rbg_current_turn;

    /* If the current turn is not last, it means player has undone
     * one or more turns.
     * Delete the following turns to free their memory.
     * Not implemented: if this_turn is equal to next turn, just move
     * g->rbg_current_turn pointer.
     */
    if(curr_turn != last_turn) {
        last_turn = RemoveTurnsFromEnd(g, curr_turn);
    }

    struct RubikTurnListNode* this_turn = malloc(sizeof(struct RubikTurnListNode));
    if(!this_turn) {
        perror("malloc"); exit(EXIT_FAILURE);
    }
    this_turn->rbtln_next = (void*) 0;
    if(last_turn) {
        this_turn->rbtln_prev = last_turn;
        last_turn->rbtln_next = this_turn;
    } else {
        this_turn->rbtln_prev = (void*) 0;
        g->rbg_first_turn = this_turn;
    }
    g->rbg_current_turn = this_turn;

    struct RubikTurn* rbt = &(this_turn->rbtln_turn);
    rbt->rbt_dir = d;
    rbt->rbt_turn = t;
    TurnRubik(g->rbg_rubik, t, d);
    return rbt;
}

unsigned long LastTurnNumberRubikGame(struct RubikGame const* const g) {
    unsigned long nr_turns = 0;
    if(g->rbg_first_turn) {
        ++nr_turns;
        struct RubikTurnListNode* last_turn = g->rbg_first_turn;
        while(last_turn->rbtln_next) {
            ++nr_turns;
            last_turn = last_turn->rbtln_next;
        }
    }
    return nr_turns;
}

unsigned long CurrentTurnNumberRubikGame(struct RubikGame const* const g) {
    unsigned long nr_turns = 0;
    /* Current turn can be NULL ever if there are later turns! */
    /* If player has undone all turns, that would be the case. */
    if(g->rbg_current_turn) {
        assert(g->rbg_first_turn);
        ++nr_turns;
        struct RubikTurnListNode* this_turn = g->rbg_first_turn;
        /* while(last_turn->rbtln_next && last_turn != g->rbg_current_turn) { */
        while(this_turn != g->rbg_current_turn) {
            ++nr_turns;
            this_turn = this_turn->rbtln_next;
        }
    }
    return nr_turns;
}

struct RubikTurn* UndoTurnRubikGame(struct RubikGame* const game) {
    if(game->rbg_current_turn) {
        struct RubikTurnListNode* curr_turn = game->rbg_current_turn;
        struct RubikTurn* curr_t = &(curr_turn->rbtln_turn);
        struct RubikTurnListNode* prev_turn = curr_turn->rbtln_prev;

        /* Reverse current turn */
        assert(0 <= curr_t->rbt_dir && curr_t->rbt_dir <= 3);
        R_dir d = R_dir_opp[curr_turn->rbtln_turn.rbt_dir];
        R_turn t = curr_turn->rbtln_turn.rbt_turn;
        TurnRubik(game->rbg_rubik, t, d);
        game->rbg_current_turn = prev_turn;
    }
    struct RubikTurn* rbt = (void*) 0;
    if(game->rbg_current_turn)
        rbt = &(game->rbg_current_turn->rbtln_turn);
    return rbt;
}

struct RubikTurn* CurrentTurnRubikGame(struct RubikGame const* const game) {
    if(game->rbg_current_turn)
        return &(game->rbg_current_turn->rbtln_turn);
    else
        return (void*) 0;
}

struct RubikTurn* NextTurnRubikGame(struct RubikGame const* const game) {
    struct RubikTurn* next_turn = (void*) 0;
    if(game->rbg_current_turn) {
        struct RubikTurnListNode* const next_node = game->rbg_current_turn->rbtln_next;
        assert(next_node);
        next_turn = &(next_node->rbtln_turn);
        assert(next_turn);
    }
    return next_turn;
}

/* struct RubikTurn* RedoTurnRubikGame(struct RubikGame* const game) { */
/* } */

