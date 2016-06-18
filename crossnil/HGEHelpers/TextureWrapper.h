#ifndef TextureWrapper_h__
#define TextureWrapper_h__

#include "HGEWrapper.h"
#include <string>

namespace HGEHelpers
{

	class TextureWrapper 
	{
		HGESharedPtr mHge;
		HTEXTURE mTexture;

		friend class SpriteWrapper;

	public:
		TextureWrapper ( HGESharedPtr hge, const std::string& fileName ) : mHge ( hge ), mTexture ( NULL )
		{
			LoadTexture ( fileName );
		}

		~TextureWrapper ()
		{
			mHge->GetHGE()->Texture_Free( mTexture );
		}
		
	private:

		HTEXTURE GetTexture ()const
		{
			return mTexture;
		}

		void LoadTexture( const std::string& fileName )
		{
			mTexture = mHge->GetHGE()->Texture_Load( fileName.c_str() );

			std::string errorMessage = std::string ("Sprite texture doesn't load Field::CreateCells " )+ fileName;
			if ( mTexture == NULL )
				throw exceptions::SpriteException  ( errorMessage.c_str() );

		}


	};

	typedef std::tr1::shared_ptr <TextureWrapper> TextureSharedPtr;

}

#endif // TextureWrapper_h__