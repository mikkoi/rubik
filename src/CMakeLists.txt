if(BUILD_TESTING)
    find_package(Check 0.12.0 REQUIRED MODULE)
    add_library(test_suite test_suite.c)
    target_link_libraries(test_suite PUBLIC Check::check)
endif()

add_subdirectory(rubik)
add_subdirectory(bin)

