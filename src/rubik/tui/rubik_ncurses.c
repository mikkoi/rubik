#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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
    /* int win_lines = 3; */
    /* int win_cols = 5; */
    /* int pos_line = 0; */
    /* int pos_col = 0; */
    /* WINDOW* wins[9] = { (void*) 0 }; */
    /* wins[0] = newwin(win_lines, win_cols, pos_line, pos_col); */
    /* wins[1] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[2] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[3] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[4] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[5] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[6] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[7] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* wins[8] = newwin(win_lines, win_cols, pos_line += 5, pos_col += 3); */
    /* for(int i = 0; i < 9; ) { */
    /*     for(int j = 0; j < 3; ++i, ++j) { */
    /*         wins[i] = newwin(win_lines, win_cols, pos_line, pos_col += 4); */
    /*         box(wins[i], 0, 0); */
    /*         wrefresh(wins[i]); */
    /*     } */
    /*     pos_line += 3; */
    /* } */
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

int ncurses_run(void) {
    initscr();            /* Start curses mode         */
    if(has_colors() == FALSE) {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        return RUBIK_NCURSES_NO_COLOR;
    }
    start_color();            /* Start color             */
    init_pair(1, COLOR_RED, COLOR_BLACK);
    cbreak();
    noecho();
    curs_set(0); /* Invisible cursor */

    attron(COLOR_PAIR(1));
    print_in_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
    attroff(COLOR_PAIR(1));
    int pos_line = 5;
    int pos_col = 0;
    WINDOW* wins[6] = { (void*) 0 };
    wins[0] = newwin(7, 13, pos_line, pos_col);
    DrawRubikSide(wins[0]);
    wrefresh(wins[0]);
    getch();
    endwin();
    return RUBIK_NCURSES_EXIT_SUCCESS;
}

