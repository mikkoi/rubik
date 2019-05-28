add_executable(rubik rubik.c)
target_link_libraries(rubik PRIVATE tui_core)
install(TARGETS rubik RUNTIME DESTINATION bin)

