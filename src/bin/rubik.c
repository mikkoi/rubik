/* Activate getopt */
#define _POSIX_C_SOURCE 2

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <locale.h>

#include <unistd.h>

#include "config.h"
#include "../project.h"
#include "../tui/core.h"

#define RUBIK_COMMAND_LINE_OPTIONS "?hV"

void print_usage(char const* const);
void print_usage(char const* const program_name) {
    fprintf(stderr, "Usage: %s [-%s]\n", program_name, RUBIK_COMMAND_LINE_OPTIONS);
}

int main(int argc, char* argv[argc+1]) {
    setlocale(LC_ALL, "");
    int opt;

    while ((opt = getopt(argc, argv, RUBIK_COMMAND_LINE_OPTIONS)) != -1) {
        switch (opt) {
        case '?':
        case 'h':
            print_usage(argv[0]);
            exit(EXIT_SUCCESS);
            break;
        case 'V':
            fprintf(stdout, "%s\n", RUBIK_PROJECT_VERSION);
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

