# $Id: CMakeLists.txt 1181 2009-04-14 03:35:32Z patryn $

add_definitions(-D_USRDLL)

set (SOURCE_FILES
	NullGpuProgram.h
	NullGpuProgramManager.cpp
	NullGpuProgramManager.h
	NullHardwareBufferManager.cpp
	NullHardwareBufferManager.h
	NullHardwareIndexBuffer.cpp
	NullHardwareIndexBuffer.h
	NullHardwareVertexBuffer.cpp
	NullHardwareVertexBuffer.h
	NullHardwarePixelBuffer.cpp
	NullHardwarePixelBuffer.h
	NullHlslProgramFactory.cpp	
	NullHlslProgramFactory.h
	NullRendererDll.cpp
	NullRenderSystem.cpp
	NullRenderSystem.h
	NullRenderWindow.cpp
	NullRenderWindow.h
    NullTexture.cpp
	NullTexture.h
	NullTextureManager.cpp
	NullTextureManager.h
	stdafx.h
)

file (GLOB HEADER_FILES *.h)

add_library(RenderSystem_NULL ${OGRE_LIB_TYPE} ${SOURCE_FILES})

target_link_libraries(RenderSystem_NULL
  OgreMain
)

if (NOT OGRE_STATIC)
  set_target_properties(RenderSystem_NULL PROPERTIES
      COMPILE_DEFINITIONS OGRENULLRSDLL_EXPORTS
  )
endif ()

ogre_config_plugin(RenderSystem_NULL)
install(FILES ${HEADER_FILES} DESTINATION include/OGRE/RenderSystems/Null)