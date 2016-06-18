#include "Field.h"

#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

namespace GameField
{
	using namespace HGEHelpers;

	Field::Field ()
	{
	}

	void Field::Render() const
	{
		float dx = 250;
		float x = dx;
		float dy = 150;
		float width = mCells[0]->GetWidth();
		float height = mCells[0]->GetHeight();
		const unsigned int numRow = 2;
		const unsigned int numCol = 2;
		unsigned int currentPos = 0;

		for ( unsigned int k = 0; k<=numRow; k++ )
		{
			for ( unsigned int i = 0; i<=numCol; i++ )
			{
				mCells[currentPos]->Render( dx, dy );
				dx = dx + width;
				currentPos++;
			}
			dy = dy + height;
			dx = x;
		}

		unsigned int offsetCell = 3;
		dx = dx + width * offsetCell;
		mCells[currentPos]->Render ( dx, dy );
	}

	int Field::GetNumCell( float x, float y ) const
	{	
		for ( unsigned int i = 0; i < mCells.size(); i++ )
		{
			if ( mCells [i]->HitTestPoint( x, y ) )
				return i;
		}

		return -1;
	}


	CellState Field::GetStateCell( int numCell )
	{
		return mCells.at ( numCell )->GetState();
	}


	bool Field::ChangeStateCell( const int& numCell, const CellState& shape )
	{
		CellState currState  = GetStateCell( numCell );
		if ( currState == empty )
		{
			HGEHelpers::TextureSharedPtr texture;
			if ( shape == cross )
			{			
				texture = mCrossTexture;
			}
			else 
			{
				texture = mNilTexture;
			}
			mCells.at ( numCell )->SetState( shape );
			mCells.at ( numCell )->ChangeTexture ( texture );

			return true;
		}
		return false;
	}

	void Field::CreateCells( HGEHelpers::HGESharedPtr hge )
	{
		unsigned int countCells = mCountCells;
		mHge = hge;

		mEmtyCellTexture = std::tr1::shared_ptr<TextureWrapper> ( new TextureWrapper( hge, std::string("cell.png" ) ) );
		mCrossTexture = std::tr1::shared_ptr<TextureWrapper> ( new TextureWrapper (hge, std::string("cross.png") ) );
		mNilTexture = std::tr1::shared_ptr<TextureWrapper> ( new TextureWrapper ( hge, std::string("nill.png") ) );

		while (  countCells-- )
		{
			mCells.push_back( std::tr1::shared_ptr<Cell> ( new Cell ( hge, mEmtyCellTexture ) ) );
		}
	}

	bool Field::IsFieldFiled()
	{
		Cells::iterator i = std::find_if ( mCells.begin(), mCells.end(), GameField::IsCellEmpty() );

		if ( i == mCells.end() )
			return true;
		else 
			return false;

	}

	void Field::Clear()
	{
		std::for_each( mCells.begin(), mCells.end(), std::tr1::mem_fn( &Cell::SetEmpty ) );		
	}

	void Field::GetShadowField( std::string& steps )
	{
		steps = std::accumulate ( mCells.begin(), 
			mCells.end(), std::string(), binary_sumator<std::string, std::string, std::tr1::shared_ptr<Cell> > () );
	}

	Field::~Field()
	{
	}

}