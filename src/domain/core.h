#ifndef RUBIK_DOMAIN_CORE_H
#define RUBIK_DOMAIN_CORE_H
#include "../project.h"
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
    Turn_Col_1 = 0, Turn_Col_2, Turn_Col_3, Turn_Row_1, Turn_Row_2, Turn_Row_3, NoTurn
} R_turn;

/* TURN_DIRECTION(<enum constant>, <same as string>, <opposite>) */
#define LIST_OF_TURN_DIRECTIONS                                                \
TURN_DIRECTION(Left, "Left", Right)                                            \
TURN_DIRECTION(Right, "Right", Left)                                           \
TURN_DIRECTION(Up, "Up", Down)                                                 \
TURN_DIRECTION(Down, "Down", Up)                                               \
TURN_DIRECTION(NoDir, "NoDir", NoDir)

#define TURN_DIRECTION(a,b,c) a,
typedef enum {
    LIST_OF_TURN_DIRECTIONS
} R_dir;
#undef TURN_DIRECTION
char const* R_turn_as_string(R_turn const turn);
char const* R_dir_as_string(R_dir const dir);

/**
 * Represents a Rubik.
 */
struct Rubik {
    size_t len;
    R_colour con[6][3][3];
};

/**
 * Represents a turn, i.e. direction and column/row.
 */
struct RubikTurn {
    R_dir rbt_dir;
    R_turn rbt_turn;
};
/*
 * rbtln_next == (void*) 0: last turn.
 * rbtln_prev == (void*) 0: first turn.
 */
struct RubikTurnListNode {
    struct RubikTurnListNode* rbtln_next;
    struct RubikTurnListNode* rbtln_prev;
    struct RubikTurn rbtln_turn;
};

/**
 * A Game of Rubik
 */
struct RubikGame {
    struct Rubik* rbg_rubik;
    struct RubikTurnListNode* rbg_first_turn; /* Begin list or null */
    struct RubikTurnListNode* rbg_current_turn; /* Current turn or null */
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
void SeedRandomRubikColour(unsigned int const seed);
R_colour GetRandomRubikColour(void);

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

/**
 * Shuffle rubik.
 */
void ShuffleRubik(struct Rubik* const r);

/**
 * Start Rubik game.
 * Allocate struct RubikGame and return pointer to initialized struct.
 */
struct RubikGame* StartRubikGame(void);

/**
 * Finish game, deallocate memory and finalize.
 */
void FinishRubikGame(struct RubikGame* game);

/**
 * Turn the cube (initial shuffle).
 */
/* struct RubikTurn* ShuffleTurnRubikGame(struct RubikGame* game, R_dir const d, R_turn const t); */

/**
 * Turn the cube.
 */
struct RubikTurn* PlayerTurnRubikGame(struct RubikGame* game, R_dir const d, R_turn const t);

/**
 * Get the number of turns made.
 */
unsigned long LastTurnNumberRubikGame(struct RubikGame const* const g);

/**
 * Get the number of turns until and including current turn.
 * (current can be earlier than the last turn in the list
 * if player has undone (UndoTurnRubikGame()) turns.
 */
unsigned long CurrentTurnNumberRubikGame(struct RubikGame const* const g);

/**
 * Undo previous turn, i.e. the current turn.
 *
 * Return RubikTurn* of the previous previous turn
 * (becoming the "current turn", i.e. previous turn).
 *
 * @param game struct RubikGame const* const
 * @return pointer to the new current turn or null pointer, i.e. (void*) 0.
 * @note If no previous turn exists, do nothing and return (void*) 0.
 */
struct RubikTurn* UndoTurnRubikGame(struct RubikGame* const game);

/**
 * Redo next turn, if exists.
 *
 * If no next turn, do nothing and return null pointer, (void*) 0.
 *
 * @param game struct RubikGame const* const
 */
struct RubikTurn* RedoTurnRubikGame(struct RubikGame* const game);

/**
 * Get the first turn of the game.
 *
 * @param game struct RubikGame const* const
 * @return pointer to the first turn made
 * @note If no turns have been made, returns (void*) 0.
 */
struct RubikTurn* FirstTurnRubikGame(struct RubikGame const* const game);

/**
 * Get the current turn of the game, i.e. the previous turn made.
 *
 * @param game struct RubikGame const* const
 * @return pointer to the current turn
 * @note If no turns have been made, returns (void*) 0.
 */
struct RubikTurn* CurrentTurnRubikGame(struct RubikGame const* const game);

/**
 * Return pointer to the next turn. Only possible if one or more
 * turns have been undone.
 * If no turns have been made or if current turn is the last turn,
 * returns (void*) 0.
 * if parameter turn is NULL, returns void* 0 if no turns are made, otherwise
 * returns the first turn.
 */
/* struct RubikTurn* NextTurnRubikGame(struct RubikGame const* const game); */
struct RubikTurn const* NextTurnRubikGame(struct RubikGame const* const game, struct RubikTurn const* const turn);

#endif

