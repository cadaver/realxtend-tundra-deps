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
 *	  $Id: NullRendererDll.cpp 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#include "stdafx.h"
#include "NullRenderSystem.h"
#include "NullHlslProgramFactory.h"

#ifndef OGRE_STATIC_LIB

namespace Ogre {

	NULLRenderSystem* nullRendPlugin;
	NULLHLSLProgramFactory* hlslProgramFactory;

	extern "C" void _OgreNULLRSExport dllStartPlugin(void) throw()
	{
		nullRendPlugin = new NULLRenderSystem();
		Ogre::Root::getSingleton().addRenderSystem( (Ogre::RenderSystem *)nullRendPlugin );

        // create & register HLSL factory
        hlslProgramFactory = new NULLHLSLProgramFactory();
		Ogre::HighLevelGpuProgramManager::getSingleton().addFactory(hlslProgramFactory);

	}

	extern "C" void _OgreNULLRSExport dllStopPlugin(void)
	{
		delete nullRendPlugin;
		delete hlslProgramFactory;
	}

}

#endif

