cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW) # project() command manages VERSION vars
endif()
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW) # Use <PackageName>_ROOT variables
endif()
project( Rubik
    VERSION 0.0.0.1
    DESCRIPTION "Simulate Rubik's cube"
    HOMEPAGE_URL "https://www.github.com/mikkoi/rubik"
    LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(BuildType)

# Enable dashboard scripting
include(CTest)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# #############################################################################
# CMake enabled static analysis

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Different tests are only executed when the corresponding
    # tools are available. Presence in the system is checked individually.
    #
    # Run analysis only when the build type is Debug,
    # not any of the Release variants.
    # In the future Cppcheck and other tools will improve
    # and find new faults in our code.
    # We do not want to create headache for the future admins and packagers,
    # only for the future programmers.

    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.10")
        # CMAKE_<LANG>_CPPCHECK only supported in 3.10 and upwards.
        # E.g. CMAKE_<LANG>_CPPLINT already since CMake 3.8.
        find_package(Cppcheck)
        if(Cppcheck_FOUND)
            set(CMAKE_C_CPPCHECK
                "${Cppcheck_EXECUTABLE};--quiet;--std=c89;--enable=warning,style,performance,portability")
            set(CMAKE_CXX_CPPCHECK "${CMAKE_C_CPPCHECK}")
        endif(Cppcheck_FOUND)
    endif()

    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.6.3")
        # CMAKE_<LANG>_CLANG_TIDY only supported in 3.6.3 and upwards.
        find_package(ClangTidy 5.0)
        if(ClangTidy_FOUND)
            set(CMAKE_C_CLANG_TIDY "${ClangTidy_EXECUTABLE};-checks='*';-format-style=none")
            set(CMAKE_CXX_CLANG_TIDY "${CMAKE_C_CLANG_TIDY}")
        endif(ClangTidy_FOUND)
    endif()

    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.3.2")
        # CMAKE_<LANG>_INCLUDE_WHAT_YOU_USE only supported in 3.3.2 and upwards.
        find_package(ArtisticStyle 3.1)
        if(ArtisticStyle_FOUND)
            set(CMAKE_C_INCLUDE_WHAT_YOU_USE "${ArtisticStyle_EXECUTABLE};--verbose;--style=gnu")
            set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${CMAKE_C_INCLUDE_WHAT_YOU_USE}")
        endif(ArtisticStyle_FOUND)
    endif()

endif()

# #############################################################################
# Compiler based static analysis
# https://stackoverflow.com/questions/17206568/what-is-the-difference-between-c-c99-ansi-c-and-gnu-c

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(
        CMAKE_C_COMPILER_ID STREQUAL "GNU"
        OR CMAKE_C_COMPILER_ID STREQUAL "Clang"
        OR CMAKE_C_COMPILER_ID STREQUAL "AppleClang")

        string(APPEND WARNING_COMPILER_FLAGS
            " -Wall"
            " -Wextra"
            " -pedantic"
            " -Wconversion"
            " -Wsign-conversion"
            " -Wpedantic"
            # " -Wlogical-op"
            #" -fsanitize=address" # Disable sanitizers to activate libasan for valgrind.
            # " -static-libasan"
            " -fno-omit-frame-pointer"
            " -Wpointer-arith -Wstrict-prototypes"
            " -Wstrict-prototypes -Wpointer-arith"
            " -Wmissing-prototypes -Wmissing-declarations"
            " -Wwrite-strings -Wcast-qual -Wcast-align"
            " -Wbad-function-cast"
            " -Wformat-security  -Wformat-nonliteral"
            " -Wmissing-format-attribute"
            " -Winline"
            )
        # https://dwheeler.com/secure-programs/Secure-Programs-HOWTO.html#C-CPP
        string(APPEND CMAKE_C_FLAGS ${WARNING_COMPILER_FLAGS})
        string(APPEND CMAKE_CXX_FLAGS ${WARNING_COMPILER_FLAGS})

    endif()
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU"
        AND (CMAKE_C_COMPILER_VERSION VERSION_EQUAL 4.3
            OR CMAKE_C_COMPILER_VERSION VERSION_GREATER 4.3))
        # Blasted Clang! Doesn't support everything GNU does!
        # When using _FORTIFY_SOURCE, must set optimize level to at least 1.
        add_compile_definitions("_FORTIFY_SOURCE=2")
        string(APPEND CMAKE_C_FLAGS " -O1")
        string(APPEND CMAKE_CXX_FLAGS " -O1")
    endif()
endif()

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

