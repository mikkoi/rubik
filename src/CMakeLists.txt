set(CURSES_INCLUDE_PATH STRING ${CONAN_INCLUDE_DIRS_NCURSES})
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

message(STATUS "CURSES_INCLUDE_DIRS:${CURSES_INCLUDE_DIRS}")
# add_executable(testncurses testncurses.c)
# target_include_directories(testncurses PUBLIC ${CURSES_INCLUDE_DIRS})
# target_link_libraries(testncurses ${CURSES_LIBRARIES})

find_package(check 0.12.0 REQUIRED MODULE)
message(STATUS "check_FOUND:${check_FOUND}")
message(STATUS "check_LIBRARIES:${check_LIBRARIES}")
message(STATUS "check_INCLUDE_DIRS:${check_INCLUDE_DIRS}")

add_library(test_suite test_suite.c)
target_link_libraries(test_suite Check::check)


add_executable(check.test check.test.c)
target_link_libraries(check.test test_suite)
add_test(NAME Check COMMAND check.test)


