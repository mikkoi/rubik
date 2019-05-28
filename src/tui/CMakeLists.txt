set(CURSES_INCLUDE_PATH STRING /usr/lib/x86_64-linux-gnu)
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)
include_directories(BEFORE ${CURSES_INCLUDE_DIRS})

add_library(tui_core core.c)
target_link_libraries(tui_core PRIVATE domain_core ${CURSES_LIBRARIES})

