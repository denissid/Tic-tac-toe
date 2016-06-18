#ifndef Cell_h__
#define Cell_h__

#include "..\exceptions\exception.h"
#include "FieldDefines.h"

#include "..\HGEHelpers\HGEWrapper.h"
#include "..\HGEHelpers\TextureWrapper.h"
#include "..\HGEHelpers\SpriteWrapper.h"

#include <iostream>
#include <functional>
#include <sstream>
#include <memory>

namespace GameField
{
	class Cell
	{
		HGEHelpers::SpriteAutoPtr mSprite;
		HGEHelpers::HGESharedPtr mHge;

		float mXposition;
		float mYposition;

		HGEHelpers::TextureSharedPtr mEmptyCellTexture;

		CellState mState;
		
	public:

		Cell( HGEHelpers::HGESharedPtr hge, HGEHelpers::TextureSharedPtr mEmptyCellTexture );

		void Render ( float x, float y ) ;
		void DeleteCurrCell ();

		const float GetHeight () const;
		const float GetWidth () const;
		bool HitTestPoint ( float x, float y ) const;
		void ChangeTexture ( HGEHelpers::TextureSharedPtr texture );
		CellState GetState();
		void SetState ( const CellState& state );
		void SetEmpty ();
		
		~Cell ();

	private:

		Cell ( const Cell& );
		Cell& operator= ( const Cell& );
	};

	struct IsCellEmpty 
	{
		IsCellEmpty (  )
		{
		}

		bool operator () ( std::tr1::shared_ptr <Cell> cell )
		{
			return cell->GetState()==empty;
		} 
	};

	template < class Ret, class left, class right > 
	struct binary_sumator : public std::binary_function <Ret, left, right > 
	{
		unsigned int indx;
		binary_sumator (): indx (0)
		{
		}

		Ret operator () ( left l, right r )
		{
			std::stringstream tmp;
			std::string state;
			switch ( r->GetState() )
			{
				case empty:
					tmp<<indx;
					state = tmp.str();
					break;
				case cross:
					state = shadowCellState[cross];
					break;
				case nill:
					state = shadowCellState[nill];
					break;
			}
			indx++;
			return l+=state;
		}
	};

}

#endif // Cell_h__