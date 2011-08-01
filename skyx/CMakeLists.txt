# Top-Level CMakeLists.txt
# TODO: Fix find-modules for debug only found mode
# TODO: Copy media folder to installed
# TODO: configure scripts for resource.cfg and plugins.cfg
PROJECT(SkyX)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

# default to debug-builds
IF (NOT CMAKE_BUILD_TYPE)
  SET (CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
ENDIF (NOT CMAKE_BUILD_TYPE)

# use dwarf-2 debugging format on APPLE
# TODO: TEST ON MAC
IF (CMAKE_BUILD_TYPE STREQUAL Debug)
  IF (APPLE)
    add_definitions("-gdwarf-2")
  ENDIF (APPLE)

  IF(CMAKE_SYSTEM_NAME STREQUAL "SunOS")
      ADD_DEFINITIONS(-D_DEBUG)
  ENDIF(CMAKE_SYSTEM_NAME STREQUAL "SunOS")

  IF(MINGW)
    ADD_DEFINITIONS(-D_DEBUG)
    ADD_DEFINITIONS(-DWIN32)
  ENDIF(MINGW)
ENDIF (CMAKE_BUILD_TYPE STREQUAL Debug)

# avoid some warnings on windows 
IF(WIN32)
  ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
ENDIF(WIN32)

# lib-postfix for 32/64
IF(UNIX AND NOT WIN32 AND NOT APPLE)
  IF(CMAKE_SIZEOF_VOID_P MATCHES "8")
    SET(LIB_POSTFIX "64" CACHE STRING "suffix for 32/64 dir placement")
    MARK_AS_ADVANCED(LIB_POSTFIX)
  ENDIF(CMAKE_SIZEOF_VOID_P MATCHES "8")
ENDIF(UNIX AND NOT WIN32 AND NOT APPLE)
IF(NOT DEFINED LIB_POSTFIX)
  SET(LIB_POSTFIX "")
ENDIF(NOT DEFINED LIB_POSTFIX) 

# preset install dir
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "CMAKE_INSTALL_PREFIX" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# some dependencies on MacOS
# TODO: TEST ON MAC
IF(APPLE)
  FIND_PATH(CARBON_INCLUDE_DIR Carbon/Carbon.h)
  FIND_LIBRARY(CARBON_LIBRARY Carbon)
  FIND_LIBRARY(IOKIT_LIBRARY IOKit)
  MARK_AS_ADVANCED(CARBON_INCLUDE_DIR CARBON_LIBRARY IOKIT_LIBRARY)
  SET(EXTRALIBS_APPLE ${CARBON_LIBRARY} ${IOKIT_LIBRARY})
ENDIF (APPLE)

# find dependencies
FIND_PACKAGE (Ogre)

if (OGRE_FOUND)
    message (STATUS)
    message ("Ogre")
    message (STATUS "-- Include: " ${OGRE_INCLUDE_DIR})
    message (STATUS "-- Lib: " ${OGRE_LIBRARIES})
    message (STATUS)
else ()
    message(FATAL_ERROR "Could not find Ogre, try setting OGRE_HOME!")
endif ()

if (MSVC)
    set(Boost_USE_MULTITHREADED TRUE)
    set(Boost_USE_STATIC_LIBS TRUE)
else ()
    set(Boost_USE_STATIC_LIBS FALSE)
endif ()
    
FIND_PACKAGE (Boost 1.40 COMPONENTS date_time thread)

if (Boost_FOUND)
    message (STATUS)
    message ("Boost")
    message (STATUS "-- Include: " ${Boost_INCLUDE_DIRS})
    message (STATUS "-- Lib: " ${Boost_LIBRARIES})
    message (STATUS)
else ()
    message(FATAL_ERROR "Could not find Boost, try setting BOOST_ROOT!")
endif ()

# Skyx projct
file (GLOB SKYX_HEADERS include/*.h include/VClouds/*.h)
file (GLOB SKYX_SOURCES src/*.cpp src/VClouds/*.cpp)

add_library (SkyX SHARED ${SKYX_SOURCES} ${SKYX_HEADERS})
add_definitions (-DSKYX_LIB) # for windows dll export/import

include_directories (./include)
include_directories (${OGRE_INCLUDE_DIR})
include_directories (${Boost_INCLUDE_DIRS})

target_link_libraries (SkyX ${OGRE_LIBRARIES})
target_link_libraries (SkyX ${Boost_LIBRARIES})

set_target_properties (SkyX PROPERTIES DEBUG_POSTFIX d)
set_target_properties (SkyX PROPERTIES PREFIX "")
set_target_properties (SkyX PROPERTIES LINK_INTERFACE_LIBRARIES "")
set_target_properties (SkyX PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set_target_properties (SkyX PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set_target_properties (SkyX PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)


# Install: If CMAKE_INSTALL_PREFIX is not defined then goes to /install
# define with cmake -DCMAKE_INSTALL_PREFIX=<path>
install (TARGETS SkyX 
         RUNTIME DESTINATION bin
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib)

install (DIRECTORY include DESTINATION .)

install (DIRECTORY media DESTINATION .)
