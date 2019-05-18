add_library(core core.c)

add_executable(core.test core.test.c)
target_link_libraries(core.test core test_suite)
# target_include_directories(core.test PRIVATE ${CMAKE_SOURCE_DIRECTORY}/src)
add_test(NAME DomainCore COMMAND core.test)

