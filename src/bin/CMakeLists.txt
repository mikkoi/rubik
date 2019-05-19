set(CURSES_INCLUDE_PATH STRING ${CONAN_INCLUDE_DIRS_NCURSES})
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

add_executable(ncurses ncurses.c)
target_include_directories(ncurses PUBLIC ${CURSES_INCLUDE_DIRS})
target_link_libraries(ncurses ${CURSES_LIBRARIES})

