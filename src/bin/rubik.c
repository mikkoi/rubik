#include <stdlib.h>
#include <stddef.h>
#include <locale.h>
#include "../rubik/tui/rubik_ncurses.h"

int main(int argc, char* argv[argc+1]) {
    setlocale(LC_ALL, "");
    if(ncurses_run() > 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

