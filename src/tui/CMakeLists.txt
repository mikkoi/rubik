set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

add_library(tui_core core.c)
target_link_libraries(tui_core PRIVATE domain_core ${CURSES_LIBRARIES})
target_include_directories(tui_core PRIVATE BEFORE ${CURSES_INCLUDE_DIRS})

