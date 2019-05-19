#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ncurses.h>

int main() {
    char mesg[]="Just a string";        /* message to be appeared on the screen */
    char str[80] = { 0 };
    int row,col;                        /* to store the number of rows and *
                                         * the number of colums of the screen */
    initscr();                          /* start the curses mode */
    getmaxyx(stdscr,row,col);           /* get the number of rows and columns */
    mvprintw(row/2,(col - (int)strlen(mesg))/2,"%s",mesg);
                                        /* print the message at the center of the screen */
    mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
    printw("Try resizing your window(if possible) and then run this program again\n");
    printw("One more line\n");
    printw("Enter something: ");
    refresh();
    getstr(str);
    mvprintw(LINES - 2, 0, "You entered: %s\n", str);
    /* getch(); */
    endwin();

    return EXIT_SUCCESS;
}


