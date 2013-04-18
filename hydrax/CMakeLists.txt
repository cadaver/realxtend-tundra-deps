# TODO/NOTE Tested only on Windows
# Requires that OGRE_HOME (and BOOST_ROOT or TBB_HOME, if applicable) environment variables are set in advance.

cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0003 NEW)

project(Hydrax)
# Build as DLL
add_definitions(-DHYDRAX_LIB)

option(USE_BOOST "Specifies whether to use Boost" TRUE)

IF(APPLE AND NOT USE_BOOST)
   set(CMAKE_CXX_FLAGS "-stdlib=libc++")
ENDIF()

IF (APPLE)
   INCLUDE_DIRECTORIES(${HOME}/workspace/tundra/deps/osx-64/ogre-safe-nocrashes/lib)
   FIND_LIBRARY(OGRE_FRAMEWORK Ogre)
   MARK_AS_ADVANCED (OGRE_FRAMEWORK)
   SET(EXTRA_LIBS ${OGRE_FRAMEWORK})
ENDIF (APPLE)

file(GLOB sourceFiles ./src/*.cpp ./src/Modules/*.cpp ./src/Modules/*.cpp ./src/Modules/ProjectedGrid/*.cpp
    ./src/Modules/RadioGrid/*.cpp ./src/Modules/SimpleGrid/*.cpp ./src/Noise/*.cpp ./src/Noise/FFT/*.cpp
    ./src/Noise/Perlin/*.cpp ./src/Noise/Real/*.cpp)

file(GLOB headerFiles ./include/*.h ./include/Modules/*.h ./include/Modules/*.h ./include/Modules/ProjectedGrid/*.h
    ./include/Modules/RadioGrid/*.h ./include/Modules/SimpleGrid/*.h ./include/Noise/*.h ./include/Noise/FFT/*.h
    ./include/Noise/Perlin/*.h ./include/Noise/Real/*.h)

if (MSVC) # Create debug library with "d" postfix
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

if ("${OGRE_HOME}" STREQUAL "")
    file(TO_CMAKE_PATH "$ENV{OGRE_HOME}" OGRE_HOME)
    set(OGRE_HOME ${OGRE_HOME} CACHE PATH "OGRE_HOME dependency path" FORCE)
endif()
if ("${TBB_HOME}" STREQUAL "")
    file(TO_CMAKE_PATH "$ENV{TBB_HOME}" TBB_HOME)
    set(TBB_HOME ${TBB_HOME} CACHE PATH "TBB_HOME dependency path" FORCE)
endif()
if ("${BOOST_ROOT}" STREQUAL "")
    file(TO_CMAKE_PATH "$ENV{BOOST_ROOT}" BOOST_ROOT)
    set(BOOST_ROOT ${BOOST_ROOT} CACHE PATH "BOOST_ROOT dependency path" FORCE)
endif()

if (CMAKE_CL_64)
    SET(TBB_ARCH "intel64")
else()
    SET(TBB_ARCH "ia32")
endif()
if (MSVC90)
    set(TBB_VC_VER "vc9")
elseif (MSVC10)
    set(TBB_VC_VER "vc10")
elseif (MSVC11)
    set(TBB_LIB_VER "vc11")
endif()
set(TBB_LIB_VER ${TBB_ARCH}/${TBB_VC_VER})

link_directories(${OGRE_HOME}/lib/$(ConfigurationName) ${BOOST_ROOT}/stage/lib ${TBB_HOME}/lib/${TBB_LIB_VER})

add_library(Hydrax SHARED ${sourceFiles} ${headerFiles})

# Add the main Hydrax include directory root folder to all projects.
include_directories(./include)

message("Hydrax OGRE_GOME   = " ${OGRE_HOME})
message("Hydrax TBB_HOME    = " ${TBB_HOME})
message("Hydrax BOOST_ROOT  = " ${BOOST_ROOT})
#message("Hydrax TBB lib path    = " ${TBB_HOME}/lib/${TBB_LIB_VER})

IF (APPLE)
    include_directories(${OGRE_HOME}/lib/relwithdebinfo/Ogre.framework/Headers)
    target_link_libraries(Hydrax ${EXTRA_LIBS})
ELSE ()
    include_directories(${OGRE_HOME}/include/OGRE ${BOOST_ROOT} ${TBB_HOME}/include)
    target_link_libraries(Hydrax optimized OgreMain.lib debug OgreMain_d.lib)
ENDIF ()
target_link_libraries(Hydrax ${EXTRA_LIBS})
set_target_properties(Hydrax PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
