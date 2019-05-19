set(CURSES_INCLUDE_PATH STRING ${CONAN_INCLUDE_DIRS_NCURSES})
set(CURSES_NEED_NCURSES BOOL TRUE)
set(CURSES_NEED_WIDE BOOL TRUE)
include(FindCurses REQUIRED)

# message(STATUS "CURSES_INCLUDE_DIRS:${CURSES_INCLUDE_DIRS}")
# add_executable(testncurses testncurses.c)
# target_include_directories(testncurses PUBLIC ${CURSES_INCLUDE_DIRS})
# target_link_libraries(testncurses ${CURSES_LIBRARIES})

find_package(Check 0.12.0 REQUIRED MODULE)
# find_package(Check 0.9.0 REQUIRED MODULE)

add_library(test_suite test_suite.c)
# target_link_libraries(test_suite PUBLIC ${Check_LIBRARIES})
target_link_libraries(test_suite PUBLIC Check::check)
# target_include_directories(test_suite PUBLIC ${Check_INCLUDE_DIRS})
# target_compile_definitions(test_suite PUBLIC ${Check_DEFINITIONS})
# target_compile_options(test_suite PUBLIC ${Check_OPTIONS})


add_executable(check.test check.test.c)
target_link_libraries(check.test PUBLIC test_suite)
add_test(NAME Check COMMAND check.test)

# include_directories(${CMAKE_CURRENT_SOURCE_DIRECTORY})

add_subdirectory(rubik)
add_subdirectory(bin)

