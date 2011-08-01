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
 *	  $Id: NullTexture.h 1182 2009-04-17 15:56:42Z volca $
 *
 *****************************************************************************/

#include "NullTexture.h"
#include "NULLHardwarePixelBuffer.h"

NULLTexture::NULLTexture(ResourceManager* creator, const String& name, ResourceHandle handle, const String& group, bool isManual, ManualResourceLoader* loader) 
	:	Texture(creator, name, handle, group, isManual, loader) 
{ 
	
}

NULLTexture::~NULLTexture()
{
}

void NULLTexture::loadImpl( void )
{

}

void NULLTexture::createInternalResourcesImpl( void )
{
	if( _pixBuf.isNull() )
	{
		unsigned int bufusage;
		if (mUsage & TU_DYNAMIC )
		{
			bufusage = HardwareBuffer::HBU_DYNAMIC;
		}
		else
		{
			bufusage = HardwareBuffer::HBU_STATIC;
		}
		if (mUsage & TU_RENDERTARGET)
		{
			bufusage |= TU_RENDERTARGET;
		}

    	_pixBuf.bind( new NULLHardwarePixelBuffer( mWidth, mHeight, 1, getFormat(), (HardwareBuffer::Usage)bufusage, false, false ) );
	}
}

void NULLTexture::freeInternalResourcesImpl( void )
{
	_pixBuf.setNull();
}

NULLRenderTexture::NULLRenderTexture( const String &name, NULLHardwarePixelBuffer* buffer )
	: RenderTexture(buffer, 0)
{
	mName = name;
}

NULLRenderTexture::~NULLRenderTexture()
{

}
