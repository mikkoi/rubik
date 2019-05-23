#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "../domain/core.h"

#define RUBIK_NCURSES_EXIT_SUCCESS 1
#define RUBIK_NCURSES_NO_COLOR -1

static void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	/* float temp; */

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = (int) strlen(string);
	/* temp = (width - length)/ 2; */
	/* x = startx + (int)temp; */
    /* x = startx + (int) lroundf((width - length) / 2); */
    x = startx + (width - length) / 2;
	mvwprintw(win, y, x, "%s", string);
    mvwvline(win, y+3, x, 0, 10);
	refresh();
}

static void DrawRubikSide(WINDOW* win) {
    /* int start_y = 0, start_x = 0; */
    /* int size_y = 3, size_x = 5; */
    /* int nr_y = 3, nr_x = 3; */
    /* addch(ACS_ULCORNER); */
    /* for(int i = 0; i < nr_y - 1; ++i) { */
    /*     for(int j = 0; j < size_x - 1; ++j) { */
    /*         addch(ACS_HLINE); */
    /*     } */
    /*     if(i < nr_y - 2) { */
    /*         addch(ACS_TTEE); */
    /*     } else { */
    /*         addch(ACS_URCORNER); printw("\n"); */
    /*     } */
    /* } */
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
    init_pair(1, COLOR_RED, COLOR_BLACK);
}
static void ColorRubikSide(WINDOW* win, R_colour(*side)[]) {
    /* wprintw(win, "┌───┬───┬───┐" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "├───┼───┼───┤" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "├───┼───┼───┤" "\n"); */
    /* wprintw(win, "│   │   │   │" "\n"); */
    /* wprintw(win, "└───┴───┴───┘" "\n"); */


	mvwprintw(win, y, x, "%s", string);
    mvwvline(win, y+3, x, 0, 10);
	refresh();
}

int ncurses_run(void) {
    initscr();            /* Start curses mode         */
    if(has_colors() == FALSE) {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        return RUBIK_NCURSES_NO_COLOR;
    }
    start_color();
    /* init_pair(1, COLOR_RED, COLOR_BLACK); */
    cbreak();
    noecho();
    curs_set(0); /* Invisible cursor */

	mvwprintw(stdscr, 0, 0, "%s", "RUBIK");
    /* attron(COLOR_PAIR(1)); */
    /* print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ..."); */
    /* attroff(COLOR_PAIR(1)); */
    refresh();
    int pos_line = 2;
    int pos_col = -13;
    WINDOW* wins[6] = { (void*) 0 };
    wins[0] = newwin(7, 13, pos_line, 13);
    for(size_t i = 1; i < 5; ++i)
        wins[i] = newwin(7, 13, pos_line + 7, pos_col += 13);
    wins[5] = newwin(7, 13, pos_line + 14, 13);
    for(size_t i = 0; i < 6; ++i) {
        DrawRubikSide(wins[i]);
        wrefresh(wins[i]);
    }
    getch();
    endwin();
    return RUBIK_NCURSES_EXIT_SUCCESS;
}

