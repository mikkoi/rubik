add_executable(rubik rubik.c)
target_link_libraries(rubik PRIVATE rubik_ncurses)
install(TARGETS rubik RUNTIME DESTINATION bin)

