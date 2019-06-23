add_executable(bin_rubik rubik.c)
target_sources(bin_rubik PRIVATE ${CMAKE_BINARY_DIR}/src/rubik.h)
target_link_libraries(bin_rubik PRIVATE tui_core)
set_target_properties(bin_rubik PROPERTIES
  OUTPUT_NAME rubik
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)
install(TARGETS bin_rubik RUNTIME DESTINATION bin)

