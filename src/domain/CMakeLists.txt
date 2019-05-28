add_library(core core.c)

if(BUILD_TESTING)
    add_executable(core.test core.test.c)
    target_link_libraries(core.test core test_suite)
    add_test(NAME DomainCore COMMAND core.test)
endif()

