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
 *	  $Id: NullHardwareBufferManager.h 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#ifndef __NULLGPUPROGRAM_H
#define __NULLGPUPROGRAM_H

#include "stdafx.h"

namespace Ogre {

	class NULLHardwareBufferManagerBase: public HardwareBufferManagerBase {
	public:
		HardwareVertexBufferSharedPtr createVertexBuffer(size_t vertexSize,
				size_t numVerts, HardwareBuffer::Usage usage, bool useShadowBuffer =
						false);
		HardwareIndexBufferSharedPtr createIndexBuffer(
				HardwareIndexBuffer::IndexType itype, size_t numIndexes,
				HardwareBuffer::Usage usage, bool useShadowBuffer = false);
	
		RenderToVertexBufferSharedPtr createRenderToVertexBuffer();
	};
	
		/// D3D9HardwareBufferManagerBase as a Singleton
	class NULLHardwareBufferManager : public HardwareBufferManager
	{
	public:
		NULLHardwareBufferManager()
			: HardwareBufferManager(OGRE_NEW NULLHardwareBufferManagerBase()) 
		{

		}
		~NULLHardwareBufferManager ()
		{
			OGRE_DELETE mImpl;
		}
	};
	
}

#endif
