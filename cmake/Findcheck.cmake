# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
Findcheck
---------

Find the check library (C language Unit Test library).

Imported Targets
^^^^^^^^^^^^^^^^

This module provides the following imported targets, if found:

``check::check``
  The check library

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``check_FOUND``
  True if the system has the check library.
``check_VERSION``
  The version of the check library which was found.
``check_INCLUDE_DIRS``
  Include directories needed to use check.
``check_LIBRARIES``
  Libraries needed to link to check.

The following obsolete variables will also be defined
to retain compatibility.

``CHECK_FOUND``
``CHECK_INCLUDE_DIR``
``CHECK_LIBRARIES``


Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``check_INCLUDE_DIR``
  The directory containing ``cache.h``.
``check_LIBRARY``
  The path to the check library.

#]=======================================================================]

find_package(PkgConfig)
pkg_check_modules(PC_check QUIET check)

find_path(check_INCLUDE_DIR
  NAMES check.h
  PATHS ${PC_check_INCLUDE_DIRS}
  PATH_SUFFIXES check
)
find_library(check_LIBRARY
  NAMES foo
  PATHS ${PC_check_LIBRARY_DIRS}
)

file(READ "${check_INCLUDE_DIR}/check.h" check_HEADER)
# message(STATUS "check_HEADER:${check_HEADER}")
string(REGEX MATCH "#define[ \t\r\n]+CHECK_MAJOR_VERSION[ \t\r\n]+\\(0\\)" check_MAJOR_VERSION_A ${check_HEADER})
# string(REGEX MATCH ".*^#define CHECK_MAJOR_VERSION \([0-9]+\)$.*" check_MAJOR_VERSION_A ${check_HEADER})
message(STATUS "check_MAJOR_VERSION:${check_MAJOR_VERSION_A}")
set(check_MAJOR_VERSION ${CMAKE_MATCH_1})
# string(REGEX MATCH "#define CHECK_MINOR_VERSION \([0-9]+\)" check_MINOR_VERSION_A ${check_HEADER})
# message(STATUS "check_MINOR_VERSION:${check_MINOR_VERSION_A}")
# string(REGEX MATCH "#define CHECK_MICRO_VERSION \([0-9]+\)" check_MICRO_VERSION_A ${check_HEADER})
set(check_VERSION "${check_MAJOR_VERSION}.${check_MINOR_VERSION}.${check_MICRO_VERSION}")
message(STATUS "check_VERSION:${check_VERSION}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(check
  FOUND_VAR check_FOUND
  REQUIRED_VARS
    check_LIBRARY
    check_INCLUDE_DIR
  VERSION_VAR check_VERSION
)

# Exported variables
if(check_FOUND)
  set(check_LIBRARIES ${check_LIBRARY})
  set(check_INCLUDE_DIRS ${check_INCLUDE_DIR})
  set(check_DEFINITIONS ${PC_check_CFLAGS_OTHER})
endif()



# compatibility variables (more exported variables)
set(CHECK_FOUND ${check_FOUND})
set(CHECK_INCLUDE_DIR ${check_INCLUDE_DIRS})
set(CHECK_LIBRARIES ${check_LIBRARIES})


