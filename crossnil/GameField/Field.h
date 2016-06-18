#ifndef Field_h__
#define Field_h__

#include "Cell.h"
#include "../HGEHelpers/HGEWrapper.h"
#include "../HGEHelpers/TextureWrapper.h"

#include <algorithm>
#include <vector>
#include <memory>
#include <functional>

namespace GameField
{

	typedef std::vector < std::tr1::shared_ptr <Cell> > Cells;

	class Field
	{
		static const unsigned int mCountCells = 10;
		Cells mCells;
		HGEHelpers::HGESharedPtr mHge;
		HGEHelpers::TextureSharedPtr mEmtyCellTexture;
		HGEHelpers::TextureSharedPtr mNilTexture;
		HGEHelpers::TextureSharedPtr mCrossTexture;

	public:
		Field ( );
		~Field ();

		void Render (  ) const;

		int GetNumCell ( float x, float y ) const;
		bool ChangeStateCell ( const int& numCell, const CellState& shape );
		CellState GetStateCell( int numCell );
		bool IsFieldFiled ();
		void CreateCells ( HGEHelpers::HGESharedPtr hge );
		void Clear ();

		void GetShadowField (  std::string& steps );

	private:

		Field ( const Field& );
		Field& operator= ( const Field& );
	};

}

#endif // Field_h__