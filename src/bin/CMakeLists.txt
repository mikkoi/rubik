# set(CURSES_INCLUDE_PATH STRING ${CONAN_INCLUDE_DIRS_NCURSES})
set(CURSES_INCLUDE_PATH STRING /usr/lib/x86_64-linux-gnu)
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

add_executable(rubik rubik.c)
target_link_libraries(rubik PRIVATE rubik_ncurses)

add_executable(ncurses ncurses.c)
target_include_directories(ncurses PUBLIC ${CURSES_INCLUDE_DIRS})
target_link_libraries(ncurses ${CURSES_LIBRARIES})

include_directories(BEFORE ${CURSES_INCLUDE_DIRS})

add_executable(ncurses2 ncurses2.c)
# target_include_directories(ncurses2 PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(ncurses2 PRIVATE ${CURSES_LIBRARIES})

add_executable(ncurses3 ncurses3.c)
target_link_libraries(ncurses3 PRIVATE ${CURSES_LIBRARIES})

add_executable(ncurses_example7 ncurses_example7.c)
target_link_libraries(ncurses_example7 PRIVATE ${CURSES_LIBRARIES})

add_executable(ncurses_example9 ncurses_example9.c)
target_link_libraries(ncurses_example9 PRIVATE ${CURSES_LIBRARIES})

add_executable(ncurses_example13 ncurses_example13.c)
target_link_libraries(ncurses_example13 PRIVATE ${CURSES_LIBRARIES})


