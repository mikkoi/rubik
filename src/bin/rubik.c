/* Activate getopt */
#define _POSIX_C_SOURCE 2

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <locale.h>

#include <unistd.h>

#include "../project.h"
#include <rubik.h>
#include "../tui/core.h"

void print_usage(char const*);
void print_usage(char const* program_name) {
    fprintf(stderr, "Usage: %s [-hlw] [file...]\n", program_name);
}

int main(int argc, char* argv[argc+1]) {
    setlocale(LC_ALL, "");
    int opt;

    while ((opt = getopt(argc, argv, "Vh")) != -1) {
        switch (opt) {
        case 'V':
            fprintf(stdout, "%s\n", RUBIK_PROJECT_VERSION);
            exit(EXIT_SUCCESS);
            break;
        case 'h':
            print_usage(argv[0]);
            exit(EXIT_SUCCESS);
            break;
        default:
            print_usage(argv[0]);
            exit(EXIT_FAILURE);
            break;
        }
    }

    // Now optind (declared extern int by <unistd.h>) is the index of the first non-option argument.
    // If it is >= argc, there were no non-option arguments.

    if(ncurses_run() > 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}

