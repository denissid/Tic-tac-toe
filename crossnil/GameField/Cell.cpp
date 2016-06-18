#include "Cell.h"

namespace 
{
 const float width = 64; 
 const float height = 64;
}

namespace GameField
{

	using namespace HGEHelpers;

	Cell::Cell( HGESharedPtr hge, TextureSharedPtr emptyCellTexture ) : mHge ( hge ), 
		mSprite  ( new SpriteWrapper ( emptyCellTexture, width, height ) ), 
		mXposition ( 0 ), 
		mYposition ( 0 ),
		mEmptyCellTexture ( emptyCellTexture ),
		mState ( empty )
	{
		
	}

	void Cell::Render( float x, float y )
	{
		mXposition = x;
		mYposition = y;
		mSprite->Render( x, y );	
	}

	bool Cell::HitTestPoint( float x, float y ) const
	{
		return mSprite->HitTestPoint( mXposition, mYposition, x, y );
	}

	const float Cell::GetHeight () const
	{
		return mSprite->GetHeight();
	}

	const float Cell::GetWidth () const
	{
		return mSprite->GetWidth();
	}

	void Cell::ChangeTexture( HGEHelpers::TextureSharedPtr texture )
	{
		mSprite->SetTexture( texture );
	}


	void Cell::SetEmpty()
	{
		mState = empty;
	}

	void Cell::DeleteCurrCell()
	{
		delete this;

	}

	void Cell::SetState ( const CellState& state )
	{
		mState = state;
	}

	CellState Cell::GetState()
	{
		return mState;
	}

	Cell::~Cell()
	{
	}

}