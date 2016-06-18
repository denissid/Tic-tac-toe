#ifndef SpriteWrapper_h__
#define SpriteWrapper_h__

#include "..\HGEHelpers\TextureWrapper.h"

#include "..\..\..\3dparty\hge181\include\hgesprite.h"
#include <memory>

namespace HGEHelpers
{

	class SpriteWrapper
	{
		hgeSprite*	mSprite;
	public:

		SpriteWrapper ( HGEHelpers::TextureSharedPtr emptyCellTexture, float width, float height );

		void Render ( float x, float y );
		bool HitTestPoint ( float cellXPosition, float cellYPosition, float x, float y );
		float GetHeight () const;
		const float GetWidth () const;
		void SetTexture( HGEHelpers::TextureSharedPtr texture );


		~SpriteWrapper ();
	};

	typedef std::auto_ptr <SpriteWrapper> SpriteAutoPtr;

}


#endif // SpriteWrapper_h__