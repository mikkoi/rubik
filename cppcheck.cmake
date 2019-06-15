# additional target to perform cppcheck run, requires cppcheck

# get all project files
# HACK this workaround is required to avoid qml files checking ^_^
file(GLOB_RECURSE ALL_SOURCE_FILES src/*.c)
# foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
#     string(FIND ${SOURCE_FILE} ${PROJECT_TRDPARTY_DIR} PROJECT_TRDPARTY_DIR_FOUND)
#     if (NOT ${PROJECT_TRDPARTY_DIR_FOUND} EQUAL -1)
#         list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
#     endif ()
# endforeach ()

add_custom_target(
        cppcheck
        # ALL
        COMMENT "Running Cppcheck on all files."
        COMMAND cppcheck
            # --enable=all
            # --enable=warning,performance,portability,information,missingInclude
            --enable=warning,performance,portability,information
            --suppress=missingIncludeSystem
            --language=c --std=c11
            #--library=qt.cfg
            --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
            # --platform=unix64
            --verbose --quiet --inline-suppr
            --check-config
            # -I ${CMAKE_C_STANDARD_INCLUDE_DIRECTORIES}
            ${ALL_SOURCE_FILES}
            # -i ${CMAKE_CURRENT_SOURCE_DIR}/otaDATA
)
# message(STATUS "include_dirs:${CMAKE_C_STANDARD_INCLUDE_DIRECTORIES}")
# add_custom_command    COMMAND cppcheck --enable all --
