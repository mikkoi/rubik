cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)
project( "Rubik"
    VERSION 0.0.0.1
    # DESCRIPTION "C (and some C++) exercises from C-Ohjelmointikieli (OtaData), Modern C and other sources."
    LANGUAGES C CXX)
include(CTest)
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Cppcheck)
if(CPPCHECK_FOUND)
    include(cppcheck.cmake)
endif(CPPCHECK_FOUND)

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
    )
string(APPEND CMAKE_C_FLAGS ${C_AND_CXX_COMPILER_FLAGS})
string(APPEND CMAKE_CXX_FLAGS ${C_AND_CXX_COMPILER_FLAGS})


# Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION
    "Create and install the HTML based API documentation (requires Doxygen)"
    ${DOXYGEN_FOUND}
    )

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    message("Doxygen build started.")
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src)

