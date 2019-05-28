#include <stdlib.h>
#include <stddef.h>
#include <locale.h>
#include "../tui/core.h"

int main(int argc, char* argv[argc+1]) {
    setlocale(LC_ALL, "");
    if(ncurses_run() > 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

