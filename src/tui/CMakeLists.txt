set(CURSES_INCLUDE_PATH STRING /usr/lib/x86_64-linux-gnu)
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)
include_directories(BEFORE ${CURSES_INCLUDE_DIRS})

add_library(rubik_ncurses rubik_ncurses.c)
target_link_libraries(rubik_ncurses PRIVATE core ${CURSES_LIBRARIES})

