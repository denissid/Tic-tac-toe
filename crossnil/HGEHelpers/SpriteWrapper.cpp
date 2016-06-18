#include "SpriteWrapper.h"

namespace HGEHelpers
{

	void SpriteWrapper::Render( float x, float y )
	{
		mSprite->Render( x, y );
	}

	bool SpriteWrapper::HitTestPoint( float cellXPosition, float cellYPosition, float x, float y )
	{
		hgeRect rectCell ( 0, 0, 0, 0 );
		mSprite->GetBoundingBox ( cellXPosition, cellYPosition, &rectCell );
		return rectCell.TestPoint( x, y );
	}

	float SpriteWrapper::GetHeight() const
	{
		return mSprite->GetHeight();
	}

	const float SpriteWrapper::GetWidth() const
	{
		return mSprite->GetWidth();
	}

	void SpriteWrapper::SetTexture( HGEHelpers::TextureSharedPtr texture )
	{
		mSprite->SetTexture( texture->GetTexture() );
	}

	SpriteWrapper::SpriteWrapper( HGEHelpers::TextureSharedPtr emptyCellTexture, float width, float height )
	{
		mSprite = new hgeSprite ( emptyCellTexture->GetTexture(), 0, 0, width, height ) ;
		mSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	}

	SpriteWrapper::~SpriteWrapper()
	{
		delete mSprite;
	}
}