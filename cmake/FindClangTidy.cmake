find_program(
    ClangTidy_EXECUTABLE
    NAMES clang-tidy
    DOC "Clang-Tidy code formatter tool (https://clang.llvm.org/extra/clang-tidy/)"
)

if(ClangTidy_EXECUTABLE)
    execute_process(
        COMMAND ${ClangTidy_EXECUTABLE} --version
        OUTPUT_VARIABLE clang_tidy_version_out
        RESULT_VARIABLE clang_tidy_version_error
        ERROR_VARIABLE clang_tidy_version_suppress)
    if(NOT clang_tidy_version_error)
        set(RX_WS "[ \t\r\n]")
        string(REPLACE "\r" "" clang_tidy_version_out "${clang_tidy_version_out}")
        string(REGEX REPLACE ".*LLVM${RX_WS}version${RX_WS}([A-Za-z0-9_\.-]+).*" "\\1" clang_tidy_version "${clang_tidy_version_out}")
    endif()
    if(clang_tidy_version)
        set(ClangTidy_FOUND 1 CACHE INTERNAL "ClangTidy version ${clang_tidy_version} found")
        set(ClangTidy_VERSION "${clang_tidy_version}" CACHE INTERNAL "ClangTidy version number")
    else()
        message(AUTHOR_WARNING "Cannot extract version number from executable '${ClangTidy_EXECUTABLE}'.")
    endif ()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    ClangTidy
    REQUIRED_VARS ClangTidy_EXECUTABLE
    VERSION_VAR ClangTidy_VERSION
)

# vim: set expandtab:ts=4:

