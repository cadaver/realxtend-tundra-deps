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
 *	  $Id: NullHardwareVertexBuffer.cpp 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#include "stdafx.h"
#include "NullHardwareVertexBuffer.h"

namespace Ogre {

	//---------------------------------------------------------------------
    NULLHardwareVertexBuffer::NULLHardwareVertexBuffer(HardwareBufferManagerBase* mgr, size_t vertexSize, 
        size_t numVertices, HardwareBuffer::Usage usage, 
        bool useSystemMemory, bool useShadowBuffer)
        : HardwareVertexBuffer(mgr, vertexSize, numVertices, usage, useSystemMemory, useShadowBuffer)
    {
        // Create the vertex buffer
		m_pBuffer = (char *)malloc(vertexSize * numVertices);

    }
	//---------------------------------------------------------------------
    NULLHardwareVertexBuffer::~NULLHardwareVertexBuffer()
    {
		free(m_pBuffer);
    }
	//---------------------------------------------------------------------

//---------------------------------------------------------------------
    void* NULLHardwareVertexBuffer::lockImpl(size_t offset, 
        size_t length, LockOptions options)
    {
        return &m_pBuffer[offset];
    }
	//---------------------------------------------------------------------
	void NULLHardwareVertexBuffer::unlockImpl(void)
    {
    }
	//---------------------------------------------------------------------
    void NULLHardwareVertexBuffer::readData(size_t offset, size_t length, 
        void* pDest)
    {
		memcpy(pDest, &m_pBuffer[offset], length);
    }
	//---------------------------------------------------------------------
    void NULLHardwareVertexBuffer::writeData(size_t offset, size_t length, 
            const void* pSource,
			bool discardWholeBuffer)
    {
		memcpy(&m_pBuffer[offset], pSource, length);
    }
	//---------------------------------------------------------------------

}
