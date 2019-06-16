add_executable(rubik rubik.c)
target_sources(rubik PRIVATE ${CMAKE_BINARY_DIR}/src/rubik.h)
target_link_libraries(rubik PRIVATE tui_core)
install(TARGETS rubik RUNTIME DESTINATION bin)

