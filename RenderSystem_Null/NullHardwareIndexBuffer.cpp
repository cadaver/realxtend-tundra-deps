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
 *	  $Id: NullHardwareIndexBuffer.cpp 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#include "stdafx.h"
#include "NullHardwareIndexBuffer.h"

namespace Ogre {

	NULLHardwareIndexBuffer::NULLHardwareIndexBuffer(HardwareBufferManagerBase* mgr, HardwareIndexBuffer::IndexType idxType, 
        size_t numIndexes, HardwareBuffer::Usage usage, bool useSystemMemory, bool useShadowBuffer)
        : HardwareIndexBuffer(mgr, idxType, numIndexes, usage, useSystemMemory, useShadowBuffer)
    {
		m_pBuffer = (char *)malloc(numIndexes * sizeof(Ogre::uint32));
    }
	//---------------------------------------------------------------------
    NULLHardwareIndexBuffer::~NULLHardwareIndexBuffer()
    {
		free(m_pBuffer);
    }
	//---------------------------------------------------------------------
    void* NULLHardwareIndexBuffer::lockImpl(size_t offset, 
        size_t length, LockOptions options)
    {
        return &m_pBuffer[offset];
    }
	//---------------------------------------------------------------------
	void NULLHardwareIndexBuffer::unlockImpl(void)
    {
    }
	//---------------------------------------------------------------------
    void NULLHardwareIndexBuffer::readData(size_t offset, size_t length, 
        void* pDest)
    {
		memcpy(pDest, &m_pBuffer[offset], length);
    }
	//---------------------------------------------------------------------
    void NULLHardwareIndexBuffer::writeData(size_t offset, size_t length, 
            const void* pSource,
			bool discardWholeBuffer)
    {
		memcpy(&m_pBuffer[offset],pSource, length);
	}

}
