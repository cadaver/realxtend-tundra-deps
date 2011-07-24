/******************************************************************************
 *
 *    This file is based on a work of 
 *      * Aliaksandr Ivaniuk aka Rride (c) 2011
 *      * openDarkEngine team (C) 2009: http://opde.svn.sourceforge.net/viewvc/opde/trunk/thirdparty/NullRenderer/
 *      * xyzzy @ ogre3d.org forum.
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 *	  $Id: NullRenderSystem.h 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreHardwareBufferManager.h>
#include <OgreTextureManager.h>
#include <OgreTexture.h>
#include <OgreHardwarePixelBuffer.h>
#include <OgreHighLevelGpuProgramManager.h>
#include <OgreGpuProgram.h>
#include <OgreStringConverter.h>
#include <OgreString.h>
#include <OgreResourceManager.h>
#include <OgreRenderSystemCapabilities.h>
#include "OgreGpuProgramManager.h"


#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32) && !defined(OGRE_STATIC_LIB)
#	ifdef OGRENULLRSDLL_EXPORTS
#		define _OgreNULLRSExport __declspec(dllexport)
#	else
#       if defined( __MINGW32__ )
#           define _OgreNULLRSExport
#       else
#    		define _OgreNULLRSExport __declspec(dllimport)
#       endif
#	endif
#else
#	define _OgreNULLRSExport 
#endif	// OGRE_WIN32
