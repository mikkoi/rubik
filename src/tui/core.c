#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#include <ncurses.h>

#include "../domain/core.h"

#define RUBIK_NCURSES_EXIT_SUCCESS 1
#define RUBIK_NCURSES_NO_COLOR -1

static void DrawMoveWindow(WINDOW* win) {
    mvwprintw(win, 0, 0, "Turn: dir + col/row");
    mvwprintw(win, 1, 0, "    ^       7 8 9");
    mvwprintw(win, 2, 0, "    |            ");
    mvwprintw(win, 3, 0, "<--   -->   4 5 6");
    mvwprintw(win, 4, 0, "    |            ");
    mvwprintw(win, 5, 0, "    v       1 2 3");
    wrefresh(win);
}
static void UpdateMoveWindow(WINDOW* win, R_dir dir) {
    assert(Left == dir || Right == dir || Up == dir || Down == dir);
    mvwprintw(win, 0, 0, "Turn: dir + col/row");
    mvwprintw(win, 1, 0, "    ^       7 8 9");
    mvwprintw(win, 2, 0, "    |            ");
    mvwprintw(win, 3, 0, "<--   -->   4 5 6");
    mvwprintw(win, 4, 0, "    |            ");
    mvwprintw(win, 5, 0, "    v       1 2 3");
    if(Left == dir)
        mvwaddch(win, 3, 0, '<' | A_REVERSE);
    else if(Right == dir)
        mvwaddch(win, 3, 8, '>' | A_REVERSE);
    else if(Up == dir)
        mvwaddch(win, 1, 4, '^' | A_REVERSE);
    else if(Down == dir)
        mvwaddch(win, 5, 4, 'v' | A_REVERSE);
    else {
        assert(0);
    }
    wrefresh(win);
}
static void ResetMoveWindow(WINDOW* win) {
    DrawMoveWindow(win);
}
static void DrawRubikSide(WINDOW* win) {
    /* wprintw(win, "┌───┬───┬───┐" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "├───┼───┼───┤" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "├───┼───┼───┤" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "└───┴───┴───┘" "\n"); */
    /* Printing simply like above won't work because this file is UTF-8. */
    waddch(win, ACS_ULCORNER);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_TTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_TTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_URCORNER);

    waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE);

    waddch(win, ACS_LTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_PLUS);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_PLUS);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_RTEE);

    waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE);

    waddch(win, ACS_LTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_PLUS);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_PLUS);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_RTEE);

    waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE); waddch(win, ' '); waddch(win, ' '); waddch(win, ' '); waddch(win, ACS_VLINE);

    waddch(win, ACS_LLCORNER);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_BTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_BTEE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_HLINE);waddch(win, ACS_LRCORNER);
}

static void RubikCreateColorPairs() {
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_YELLOW);
}
static void RubikDeleteColorPairs() {
    /* reset_color_pairs(); */
}
static void ColorRubikSide(WINDOW* win, size_t m, size_t n, R_colour side[m][n]) {
    /* ┌───┬───┬───┐ */
    /* │   │   │   │ */
    /* ├───┼───┼───┤ */
    /* │   │   │   │ */
    /* ├───┼───┼───┤ */
    /* │   │   │   │ */
    /* └───┴───┴───┘ */
#if !defined(NDEBUG)
    int debug_y = 30;
    mvwprintw(stdscr, debug_y++, 0, "DEBUG: print colors:");
#endif
    int y = 1;
    for(size_t i = 0; i < m; ++i) {
        int x = 1;
        for(size_t j = 0; j < n; ++j) {
            int color_pair = (int) side[i][j] + 1;
            wattron(win, COLOR_PAIR(color_pair));
#ifdef NDEBUG
            mvwprintw(win, y, x, "   ");
#else
            mvwprintw(stdscr, debug_y++, 0, "y:%d,x:%d,color_pair:%d",
                    y, x, color_pair);
            mvwprintw(win, y, x, "###");
#endif
            wattroff(win, COLOR_PAIR(color_pair));
            x += 4;
        }
        y += 2;
    }
    wrefresh(win);
    /* wrefresh(stdscr); */
    /* refresh(); */
}

int ncurses_run(void) {
    initscr();            /* Start curses mode         */
    if(has_colors() == FALSE) {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        return RUBIK_NCURSES_NO_COLOR;
    }
    start_color();
    cbreak();
    noecho();
    curs_set(0); /* Invisible cursor */

    wrefresh(stdscr); /* Must refresh main screen once */

    /* Init other parts of the TUI */
    WINDOW* header_win = newwin(1, 79, 0, 0);
#ifdef NDEBUG
	mvwprintw(header_win, 0, 0, "%s", "RUBIK");
#else
	mvwprintw(header_win, 0, 0, "%s", "RUBIK --- THIS IS DEVELOPMENT BUILD!");
#endif
    wrefresh(header_win);

#if !defined(NDEBUG)
    /* For debugging purposes, draw a border around 24x80 area. */
    mvhline(24, 0, '-', 80);
    mvvline(0, 80, '|', 24);
    mvprintw(23, 75, "24x80");
#endif
    /* Init rubik */
    RubikCreateColorPairs();
    struct Rubik* r = CreateRubik(3);

    /* Create windows them for all six squares of the Rubik's cube. */
    int pos_line = 2;
    int pos_col = -13;
    WINDOW* sqr_wins[6] = { (void*) 0 };
    sqr_wins[0] = newwin(7, 13, pos_line, 13);
    for(size_t i = 1; i < 5; ++i)
        sqr_wins[i] = newwin(7, 13, pos_line + 7, pos_col += 13);
    sqr_wins[5] = newwin(7, 13, pos_line + 14, 13);
    /* Color Rubik */
    for(size_t i = 0; i < 6; ++i) {
        DrawRubikSide(sqr_wins[i]);
        ColorRubikSide(sqr_wins[i], 3, 3, r->con[i]);
        wrefresh(sqr_wins[i]);
    }

    /* +----------+ */
    /* |q Quit    | */
    /* |n New     | */
    /* |s Save    | */
    /* |r Restore | */
    /* |          | */
    /* +----------+ */
    WINDOW* keys_win = newwin(10, 10, 2, 70);
    mvwprintw(keys_win, 0, 0, "q Quit");
    mvwprintw(keys_win, 1, 0, "n New");
    /* mvwprintw(keys_win, 2, 0, "s Save"); */
    /* mvwprintw(keys_win, 3, 0, "r Restore"); */
    wrefresh(keys_win);

    WINDOW* inst_win = newwin(7, 35, 2, 30);
    mvwprintw(inst_win, 0, 0, "To turn, first use arrow keys\nor number keys 2/4/6/8,\nthen other numpad keys.");
    wrefresh(inst_win);

    /* +-----------------+ */
    /* |    ^       7 8 9| */
    /* |    |            | */
    /* |<--   -->   4 5 6| */
    /* |    |            | */
    /* |    v       1 2 3| */
    /* +-----------------+ */
    WINDOW* move_win = newwin(6, 19, pos_line + 14, 2 * 13 + 2);
    DrawMoveWindow(move_win);

    /* Main loop */
    raw();
    keypad(stdscr, TRUE);
    /* typedef enum { TurnLeft, TurnRight, TurnUp, TurnDown } Turn_dir;  */
    R_dir prev_input = NoDir;
    bool request_stop = false;
    while(!request_stop) {
        assert(Left == prev_input || Right == prev_input
                || Up == prev_input || Down == prev_input
                || NoDir == prev_input);
        assert(AssertRubik(r));
#if !defined(NDEBUG)
        mvwprintw(stdscr, 27, 0, "DEBUG: prev_input: %5s.", R_dir_as_string(prev_input));
#endif
        int ch = getch();
#if !defined(NDEBUG)
        mvwprintw(stdscr, 25, 0, "Character pressed is = '%3d'."
                " Hopefully it can be printed as '%c'.", ch, ch);
        mvwprintw(stdscr, 26, 0, "                     ");
#endif
        /* In C and C++, the cases of a switch statement are in fact labels,
         * and the switch is essentially a go-to that jumps to the desired label.
         * https://dzone.com/articles/implicit-fallthrough-in-gcc-7
         * Attn. Can't actually do `goto <switch label>`!
         * */
        switch(ch) {
            case 'q':
                request_stop = true;
                break;
            case 'n':
                SeedRandomRubikColour((int unsigned) time(NULL));
                ShuffleRubik(r);
                for(size_t i = 0; i < 6; ++i) {
                    ColorRubikSide(sqr_wins[i], 3, 3, r->con[i]);
                }
                break;
            case KEY_LEFT:
                /* Light up wanted direction arrows. */
                prev_input = Left;
                ResetMoveWindow(move_win);
                UpdateMoveWindow(move_win, prev_input);
                break;
            case KEY_RIGHT:
                /* Light up wanted direction arrows. */
                prev_input = Right;
                ResetMoveWindow(move_win);
                UpdateMoveWindow(move_win, prev_input);
                break;
            case KEY_UP:
                /* Light up wanted direction arrows. */
                prev_input = Up;
                ResetMoveWindow(move_win);
                UpdateMoveWindow(move_win, prev_input);
                break;
            case KEY_DOWN:
                /* Light up wanted direction arrows. */
                prev_input = Down;
                ResetMoveWindow(move_win);
                UpdateMoveWindow(move_win, prev_input);
                break;
            case '1':
                if(NoDir == prev_input) {
                    break;
                }
                __attribute__ ((fallthrough));
            case '2':
                if(NoDir == prev_input) {
                    prev_input = Down;
                    ResetMoveWindow(move_win);
                    UpdateMoveWindow(move_win, prev_input);
                    break;
                }
                __attribute__ ((fallthrough));
            case '3':
                if(NoDir == prev_input) {
                    break;
                }
                __attribute__ ((fallthrough));
            case '4':
                if(NoDir == prev_input) {
                    prev_input = Left;
                    ResetMoveWindow(move_win);
                    UpdateMoveWindow(move_win, prev_input);
                    break;
                }
                __attribute__ ((fallthrough));
            case '5':
                if(NoDir == prev_input) {
                    break;
                }
                __attribute__ ((fallthrough));
            case '6':
                if(NoDir == prev_input) {
                    prev_input = Right;
                    ResetMoveWindow(move_win);
                    UpdateMoveWindow(move_win, prev_input);
                    break;
                }
                __attribute__ ((fallthrough));
            case '7':
                if(NoDir == prev_input) {
                    break;
                }
                __attribute__ ((fallthrough));
            case '8':
                if(NoDir == prev_input) {
                    prev_input = Up;
                    ResetMoveWindow(move_win);
                    UpdateMoveWindow(move_win, prev_input);
                    break;
                }
                __attribute__ ((fallthrough));
            case '9':
                if(NoDir != prev_input) {
                    assert(Left == prev_input || Right == prev_input
                            || Up == prev_input || Down == prev_input);
                    R_turn turn;
                    if(Up == prev_input || Down == prev_input) {
                        if('1' == ch || '4' == ch || '7' == ch)
                             turn = Turn_Col_1;
                        else if('2' == ch || '5' == ch || '8' == ch)
                             turn = Turn_Col_2;
                        else /* ('3' == ch || '6' == ch || '9' == ch) */
                             turn = Turn_Col_3;
                    } else {
                        /* (Left == prev_input || Right == prev_input) */ 
                        if('7' == ch || '8' == ch || '9' == ch)
                             turn = Turn_Row_1;
                        else if('4' == ch || '5' == ch || '6' == ch)
                             turn = Turn_Row_2;
                        else /* ('1' == ch || '2' == ch || '3' == ch) */
                             turn = Turn_Row_3;
                    }
                    ResetMoveWindow(move_win);
                    TurnRubik(r, turn, prev_input);
                    for(size_t i = 0; i < 6; ++i) {
                        ColorRubikSide(sqr_wins[i], 3, 3, r->con[i]);
                    }
                    prev_input = NoDir;
                }
                break;
            default:
#if !defined(NDEBUG)
                mvwprintw(stdscr, 26, 0, "DEBUG: Unknown input!");
#endif
                ResetMoveWindow(move_win);
                prev_input = NoDir;
                break;
        }
        
    }

    /* Clean up */
    RubikDeleteColorPairs();
    DiscardRubik(r);
    endwin();
    return RUBIK_NCURSES_EXIT_SUCCESS;
}

