set(CURSES_INCLUDE_PATH STRING ${CONAN_INCLUDE_DIRS_NCURSES})
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

# add_executable(testncurses testncurses.c)
# target_include_directories(testncurses PUBLIC ${CURSES_INCLUDE_DIRS})
# target_link_libraries(testncurses ${CURSES_LIBRARIES})


