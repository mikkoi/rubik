# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
FindCheck
---------

Find the Check library (C language Unit Test library).

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``Check::check``
  The Check library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``Check_FOUND``
  True if the system has the Check library.
``Check_VERSION``
  The version of the Check library which was found.
``Check_INCLUDE_DIRS``
  Include directories needed to use Check.
``Check_LIBRARIES``
  Libraries needed to link to Check.
``Check_DEFINITIONS``
  Definitions to use when compiling code that uses Check.
``Check_OPTIONS``
  Options to use when compiling code that uses Check.

The following obsolete variables will also be defined
to retain compatibility.

``CHECK_FOUND``
``CHECK_INCLUDE_DIR``
``CHECK_LIBRARIES``


Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``Check_ROOT``
  The directory containing Check installation, i.e.
  containing dirs ``include`` and ``lib``.
``Check_INCLUDE_DIR``
  The directory containing ``cache.h``.
``Check_LIBRARY``
  The path to the Check library.

#]=======================================================================]

if(Check_ROOT)
    set(Check_INCLUDE_DIR ${Check_ROOT}/include)
    set(Check_LIBRARY ${Check_ROOT}/lib/libcheck.so)
else()
    find_package(PkgConfig)
    pkg_check_modules(PC_check QUIET check)

    find_path(Check_INCLUDE_DIR
      NAMES check.h
      PATHS ${PC_Check_INCLUDE_DIRS}
      PATH_SUFFIXES check
    )
    find_library(Check_LIBRARY
      NAMES check
      PATHS ${PC_Check_LIBRARY_DIRS}
    )
endif()

if(NOT "${Check_INCLUDE_DIR}" STREQUAL "Check_INCLUDE_DIR-NOTFOUND")
    set(RX_WS "[ \t\r\n]")
    file(READ "${Check_INCLUDE_DIR}/check.h" Check_HEADER)
    string(REGEX MATCH "#define${RX_WS}+CHECK_MAJOR_VERSION${RX_WS}+\\(([0-9]+)\\)" Check_MAJOR_VERSION_A ${Check_HEADER})
    set(Check_MAJOR_VERSION ${CMAKE_MATCH_1})
    string(REGEX MATCH "#define${RX_WS}+CHECK_MINOR_VERSION${RX_WS}+\\(([0-9]+)\\)" Check_MINOR_VERSION_A ${Check_HEADER})
    set(Check_MINOR_VERSION ${CMAKE_MATCH_1})
    string(REGEX MATCH "#define${RX_WS}+CHECK_MICRO_VERSION${RX_WS}+\\(([0-9]+)\\)" Check_MICRO_VERSION_A ${Check_HEADER})
    set(Check_MICRO_VERSION ${CMAKE_MATCH_1})
    set(Check_VERSION "${check_MAJOR_VERSION}.${Check_MINOR_VERSION}.${Check_MICRO_VERSION}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Check
  FOUND_VAR Check_FOUND
  REQUIRED_VARS
    Check_LIBRARY
    Check_INCLUDE_DIR
  VERSION_VAR Check_VERSION
)

# Exported variables
if(Check_FOUND)
  set(Check_LIBRARIES ${Check_LIBRARY})
  set(Check_INCLUDE_DIRS ${Check_INCLUDE_DIR})
  set(Check_DEFINITIONS "")
  set(Check_OPTIONS ${PC_Check_CFLAGS_OTHER})
endif()

# Provide imported target
if(Check_FOUND AND NOT TARGET Check::check)
  add_library(Check::check UNKNOWN IMPORTED)
  set_target_properties(Check::check PROPERTIES
    IMPORTED_LOCATION "${Check_LIBRARY}"
    INTERFACE_COMPILE_OPTIONS "${PC_Check_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${Check_INCLUDE_DIR}"
  )
endif()

# compatibility variables (more exported variables)
set(CHECK_FOUND ${Check_FOUND})
set(CHECK_INCLUDE_DIR ${Check_INCLUDE_DIRS})
set(CHECK_LIBRARIES ${Check_LIBRARIES})


