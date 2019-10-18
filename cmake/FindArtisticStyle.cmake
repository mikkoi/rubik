find_program(
    ArtisticStyle_EXECUTABLE
    NAMES astyle
    DOC "Artistic Style static analysis tool (http://astyle.sourceforge.net)"
)

if(ArtisticStyle_EXECUTABLE)
    execute_process(
        COMMAND ${ArtisticStyle_EXECUTABLE} --version
        OUTPUT_VARIABLE astyle_version_out
        RESULT_VARIABLE astyle_version_error
        ERROR_VARIABLE astyle_version_suppress)
    if(NOT astyle_version_error)
        string(REPLACE "\n" "" astyle_version_out "${astyle_version_out}")
        string(REGEX REPLACE "Artistic Style Version (.+)" "\\1" astyle_version "${astyle_version_out}")
    endif()
    if(astyle_version)
        set(ArtisticStyle_FOUND 1 CACHE INTERNAL "ArtisticStyle version ${astyle_version} found")
        set(ArtisticStyle_VERSION "${astyle_version}" CACHE INTERNAL "ArtisticStyle version number")
    else()
        message(AUTHOR_WARNING "Cannot extract version number from executable '${ArtisticStyle_EXECUTABLE}'.")
    endif ()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    ArtisticStyle
    REQUIRED_VARS ArtisticStyle_EXECUTABLE
    VERSION_VAR ArtisticStyle_VERSION
)

# vim: set expandtab:ts=4:

