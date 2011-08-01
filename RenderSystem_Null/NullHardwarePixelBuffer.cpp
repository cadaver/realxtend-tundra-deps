#include "NULLHardwarePixelBuffer.h"
#include "NULLTexture.h"
NULLHardwarePixelBuffer::NULLHardwarePixelBuffer( size_t mWidth, size_t mHeight, size_t mDepth, PixelFormat mFormat, 
													HardwareBuffer::Usage usage, bool useSystemMemory, bool useShadowBuffer )
	:	HardwarePixelBuffer( mWidth, mHeight, mDepth, mFormat, usage, useSystemMemory, useShadowBuffer ),
		mRenderTexture(0)
{
	_data.resize(PixelUtil::getMemorySize(mWidth, mHeight, mDepth, mFormat) );
	if (usage & TU_RENDERTARGET)
	{
		_updateRenderTexture(true);
	}
}

NULLHardwarePixelBuffer::~NULLHardwarePixelBuffer()
{
	_data.clear();

	if (mUsage & TU_RENDERTARGET)
	{
		_updateRenderTexture(false);
	}
}

void NULLHardwarePixelBuffer::_updateRenderTexture( bool enable )
{
	if(enable)
	{
    	if (mRenderTexture == NULL)
    	{
    		String name = "rtt/" +Ogre::StringConverter::toString((size_t)this);
    
    		mRenderTexture = new NULLRenderTexture(name, this);		
    		Root::getSingleton().getRenderSystem()->attachRenderTarget(*mRenderTexture);
    	}
	}
	else
	{
		if (mRenderTexture)
		{
    		Root::getSingleton().getRenderSystem()->detachRenderTarget(mRenderTexture->getName());
			mRenderTexture = 0;
		}
	}
}

Ogre::PixelBox NULLHardwarePixelBuffer::lockImpl( const Image::Box lockBox, LockOptions options )
{
	Ogre::PixelBox box(mWidth, mHeight, mDepth, getFormat(), &_data[0] );

	box.rowPitch	= box.getWidth();
	box.slicePitch	= box.rowPitch * box.getHeight();

	unsigned bitsPerByte = 8;
	unsigned byteOffset = (lockBox.top * box.getWidth() + lockBox.left ) * PixelUtil::getNumElemBits(getFormat()) / bitsPerByte;
	box.data = &_data[byteOffset];

	return box;
}

void NULLHardwarePixelBuffer::unlockImpl( void )
{

}

void NULLHardwarePixelBuffer::blitFromMemory( const PixelBox &src, const Image::Box &dstBox )
{

}

void NULLHardwarePixelBuffer::blitToMemory( const Image::Box &srcBox, const PixelBox &dst )
{

}
