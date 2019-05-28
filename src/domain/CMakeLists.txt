add_library(domain_core core.c)

if(BUILD_TESTING)
    add_executable(domain_core.test core.test.c)
    target_link_libraries(domain_core.test domain_core test_suite)
    add_test(NAME DomainCore COMMAND domain_core.test)
endif()

