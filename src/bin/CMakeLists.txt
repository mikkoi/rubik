add_executable(bin_rubik rubik.c)
target_link_libraries(bin_rubik PRIVATE tui_core PRIVATE config)
set_target_properties(bin_rubik PROPERTIES
  OUTPUT_NAME rubik
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)
if(BUILD_TESTING)
    add_test(NAME OutputVersionIsProjectVersion COMMAND "bin_rubik" "-V")
    set_tests_properties(OutputVersionIsProjectVersion PROPERTIES
        PASS_REGULAR_EXPRESSION "^${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK}")
endif()
install(TARGETS bin_rubik RUNTIME DESTINATION bin)

