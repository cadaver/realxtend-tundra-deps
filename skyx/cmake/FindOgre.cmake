# Find OGRE (by Blasius Czink)
#
# Defines:
#   OGRE_LIBRARIES = OgreMain lib
#   OGRE_INCLUDE_DIR

FIND_PATH (OGRE_INCLUDE_DIR Ogre.h
  PATHS
  $ENV{OGRE_HOME}/include
  $ENV{OGRE_HOME}/include/OGRE
  $ENV{EXTERNLIBS}/ogresdk/include
  $ENV{EXTERNLIBS}/OgreSDK/include
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local/include
  /urs/local/include/OGRE
  /usr/include
  /urs/include/OGRE
  PATH_SUFFIXES
  OGRE
  DOC "Ogre3D - Headers"
  NO_DEFAULT_PATH
)

SET (OGRE_LIB_SEARCH_PATHS
  "$ENV{OGRE_HOME}/lib"
  "$ENV{OGRE_HOME}/lib/Debug"
  "$ENV{OGRE_HOME}/lib/Release"
  "$ENV{EXTERNLIBS}/ogresdk/lib"
  "$ENV{EXTERNLIBS}/OgreSDK/lib/debug"
  "$ENV{EXTERNLIBS}/OgreSDK/lib/release"
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/lib/include
  /urs/lib/include/OGRE
  /usr/lib
  /urs/lib/OGRE
)

FIND_LIBRARY(OGRE_LIBRARY
  NAMES OgreMain OgreMain.dll.a OgreMainStatic Ogre
  PATHS ${OGRE_LIB_SEARCH_PATHS}
  PATH_SUFFIXES Release
  DOC "Ogre3D - Library (release)"
  NO_SYSTEM_ENVIRONMENT_PATH
)

FIND_LIBRARY(OGRE_LIBRARY_DEBUG
  NAMES OgreMain_d OgreMainStatic_d Ogre_d
  PATHS ${OGRE_LIB_SEARCH_PATHS}
  PATH_SUFFIXES Debug
  DOC "Ogre3D - Library (debug)"
  NO_SYSTEM_ENVIRONMENT_PATH
)

set (OGRE_LIBRARIES optimized ${OGRE_LIBRARY} debug ${OGRE_LIBRARY_DEBUG})
set (OGRE_INCLUDE_DIR ${OGRE_INCLUDE_DIR})

set (OGRE_FOUND 1)
if (NOT OGRE_INCLUDE_DIR)
    set (OGRE_FOUND 0)
endif ()