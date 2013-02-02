# Tested only on Windows
# Requires that OGRE_HOME (and BOOST_ROOT, if applicable) are passed as a command-line arguments:
# cmake . -G %GENERATOR% -DOGRE_HOME=%OGRE_HOME% -DBOOST_ROOT=%BOOST_ROOT%

cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0003 NEW)

project(Hydrax)
# Build as DLL
add_definitions(-DHYDRAX_LIB)

file(GLOB sourceFiles ./src/*.cpp ./src/Modules/*.cpp ./src/Modules/*.cpp ./src/Modules/ProjectedGrid/*.cpp
    ./src/Modules/RadioGrid/*.cpp ./src/Modules/SimpleGrid/*.cpp ./src/Noise/*.cpp ./src/Noise/FFT/*.cpp
    ./src/Noise/Perlin/*.cpp ./src/Noise/Real/*.cpp)

file(GLOB headerFiles ./include/*.h ./include/Modules/*.h ./include/Modules/*.h ./include/Modules/ProjectedGrid/*.h
    ./include/Modules/RadioGrid/*.h ./include/Modules/SimpleGrid/*.h ./include/Noise/*.h ./include/Noise/FFT/*.h
    ./include/Noise/Perlin/*.h ./include/Noise/Real/*.h)

if (MSVC) # Create debug library with "d" postfix
  set(CMAKE_DEBUG_POSTFIX "d")
endif()

add_library(Hydrax SHARED ${sourceFiles} ${headerFiles})

# Add the main Hydrax include directory root folder to all projects.
include_directories(./include)

include_directories(${OGRE_HOME}/include/OGRE ${BOOST_ROOT})
#TODO link_directories doesn't seem to work, so set the full lib paths in target_link_libraries instead.
#link_directories(${OGRE_HOME}/lib ${OGRE_HOME}/lib/$(Configuration) ${OGRE_HOME}/lib/$(ConfigurationName) ${BOOST_ROOT}/stage/lib)
#target_link_libraries(Hydrax debug OgreMain_d.lib)
#target_link_libraries(Hydrax optimized OgreMain.lib)
target_link_libraries(Hydrax debug ${OGRE_HOME}/lib/$(ConfigurationName)/OgreMain_d.lib)
target_link_libraries(Hydrax optimized ${OGRE_HOME}/lib/$(ConfigurationName)/OgreMain.lib)

set_target_properties(Hydrax PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
