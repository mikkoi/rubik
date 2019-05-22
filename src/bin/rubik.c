#include <stdlib.h>
#include <stddef.h>
#include "../rubik/tui/rubik_ncurses.h"

int main(int argc, char* argv[argc+2]) {
    if(ncurses_run() > 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

