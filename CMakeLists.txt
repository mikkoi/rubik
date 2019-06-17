cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW) # project() command manages VERSION vars
cmake_policy(SET CMP0074 NEW) # Use <PackageName>_ROOT variables
project( Rubik
    VERSION 0.0.0.1
    DESCRIPTION "Simulate Rubik's cube"
    HOMEPAGE_URL "https://www.github.com/mikkoi/rubik"
    LANGUAGES C)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(BuildType)

option(BUILD_TESTING "Build tests" OFF)
include(CTest)
enable_testing()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_custom_target(qa)
find_package(Cppcheck)
if(CPPCHECK_FOUND)
    include(cppcheck.cmake)
    add_dependencies(qa cppcheck)
endif(CPPCHECK_FOUND)


# if(Cppcheck_FOUND)
#     function(add_executable bin src)
#         message(STATUS "add executable '${src}' for checking with Cppcheck.")
#         _add_executable(${bin} ${src})
#         get_property(THESE_INCLUDES TARGET ${bin} PROPERTY INCLUDE_DIRECTORIES)
#         # message(STATUS "${THESE_INCLUDES}")
#         add_custom_command(
#             TARGET ${bin}
#             PRE_BUILD
#             COMMAND
#                 cppcheck --enable=all --language=c
#                 --std=c89
#                 --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
#                 --verbose --quiet --inline-suppr
#                 # --check-config
#                 ${src}
#             WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#             COMMENT "Running Cppcheck on ${src}."
#             # VERBATIM
#             USES_TERMINAL
#         )
#     endfunction()
# endif(Cppcheck_FOUND)

string(APPEND C_AND_CXX_COMPILER_FLAGS
    " -Wall"
    " -Wextra"
    " -pedantic"
    " -Wconversion"
    " -Wsign-conversion"
    # " -Wpedantic"
    #" -fsanitize=address" # Disable sanitizers to activate libasan for valgrind.
    " -fno-omit-frame-pointer"
    # " -fsanitize=address"
    # " -static-libasan"
    " -fno-omit-frame-pointer"
    # " -Wl"
    # " -std=c89"
    # Some of these are already part of -Wextra
    " -Wpointer-arith -Wstrict-prototypes -O2"
    " -pedantic"
    " -Wmissing-prototypes -Wmissing-declarations"
    " -Wstrict-prototypes -Wpointer-arith"
    " -Wwrite-strings -Wcast-qual -Wcast-align"
    " -Wbad-function-cast"
    " -Wformat-security  -Wformat-nonliteral"
    " -Wmissing-format-attribute"
    " -Winline"
    " -Wincompatible-pointer-types"
    # https://dwheeler.com/secure-programs/Secure-Programs-HOWTO.html#C-CPP
    " -funsigned-char" # forces unspecified "char"s to be unsigned
    )
string(APPEND CMAKE_C_FLAGS ${C_AND_CXX_COMPILER_FLAGS})
string(APPEND CMAKE_CXX_FLAGS ${C_AND_CXX_COMPILER_FLAGS})

include_directories(${CMAKE_BINARY_DIR}/src)


# Doxygen
# find_package(Doxygen)
# option(BUILD_DOCUMENTATION
#     "Create and install the HTML based API documentation (requires Doxygen)"
#     ${DOXYGEN_FOUND}
#     )
#
# if(BUILD_DOCUMENTATION)
#     if(NOT DOXYGEN_FOUND)
#         message(FATAL_ERROR "Doxygen is needed to build the documentation.")
#     endif()
#
#     set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
#     set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#     configure_file(${doxyfile_in} ${doxyfile} @ONLY)
#
#     message("Doxygen build started.")
#     add_custom_target(doc
#         COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM)
#
#     #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
# endif()

# add_subdirectory(external)
add_subdirectory(src)

