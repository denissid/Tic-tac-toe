#ifndef FieldDefines_h__
#define FieldDefines_h__

#include <string>

namespace 	GameField
{
	enum CellState 
	{
		empty,
		cross,
		nill
	};

	static const char shadowCellState[] = 
	{
		'e',
		'+',
		'o'
	};

	static const std::string gShadowStates = "+o";

}

#endif // CellState_h__