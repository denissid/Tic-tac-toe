#include "Computer.h"

#include "..\GameField\FieldDefines.h"
#include "..\GameField\Field.h"

using namespace GameField;

namespace GameActors
{
	Computer::~Computer()
	{
	}

	int Computer::GetBestCellPosition( Field& field )
	{
	
		std::string shadowField;
		field.GetShadowField ( shadowField );

		//weight and line
		ResultTree resultTree;

		LookLines ( shadowField, resultTree );
		LookColumns ( shadowField, resultTree );
		LookDiagonals ( shadowField, resultTree );

		const unsigned maxCellNum = 10;

		if ( resultTree.empty() )
			return rand ()%maxCellNum;

		//Get string with max priority
		std::pair <int,std::string> stringMaxWeight;
		if ( mOpponentShape == cross )
			stringMaxWeight = *(--resultTree.end());			
		else 
			stringMaxWeight = *(resultTree.begin());
			

		std::string shapes = gShadowStates;
		std::string::size_type i = stringMaxWeight.second.find_first_not_of( shapes, 0 );

		if ( i == std::string::npos )
		{
			return rand ()%maxCellNum;
		}
		else
		{
			std::stringstream tmp; 
			tmp << stringMaxWeight.second [i];
			int cellPosition = 0;
			tmp >> cellPosition;
			return cellPosition;
		}
	}

	void Computer::LookLines( const std::string& shadowField, ResultTree& resultTree )
	{
		const int numLines = 9;
		const int lenLine = 3;
		for ( unsigned int i = 0; i<numLines; i=i+lenLine )
		{
			std::string line = shadowField.substr ( i, lenLine );
			int weight = GetWeight ( line ) ;
			resultTree.insert ( std::make_pair ( weight, line ) );
		}
	}

	void Computer::LookColumns ( const std::string& shadowField, ResultTree& resultTree )
	{
		const int offsetNextCell  = 3;
		const int numColumns = 3;
		for ( unsigned int i = 0; i<numColumns; i++ )
		{
			std::stringstream tmp;
			tmp << shadowField[i]
				<<shadowField[i+offsetNextCell]
				<<shadowField [i+offsetNextCell*2];
			std::string column = tmp.str();
			int weight = GetWeight ( column ) ;
			resultTree.insert ( std::make_pair ( weight, column ) );
		}	
	}

	void Computer::LookDiagonals( const std::string& shadowField, ResultTree& resultTree )
	{
		int diagonalCell []  = { 0, 4, 8, 
								 2, 4, 6, 
								 4, 8, 9 }; 

		const int numDiagonalCell = 9;
		const int lenDiagonal = 3;
		for ( int i = 0; i<numDiagonalCell; i = i+lenDiagonal )
		{
			std::stringstream tmp;
			tmp << shadowField[ diagonalCell[i] ]
				<<shadowField[ diagonalCell[i+1] ]
				<<shadowField[ diagonalCell[i+2] ];

			std::string diagonal = tmp.str();
			int weight = GetWeight ( diagonal ) ;
			resultTree.insert ( std::make_pair ( weight, diagonal ) );
		}	
	}

	int Computer::GetWeight( const std::string& analyzedLine )
	{
		int weight = 0;

		//If in analyzedLine +o absent weight = 0
		std::string states = gShadowStates;
		std::string::size_type i = analyzedLine.find_first_not_of( states, 0 );
		if ( i == std::string::npos )
			return weight;

		//if in analyzedLine exist +o change weight
		for ( unsigned int i = 0; i<analyzedLine.size(); i++ )
		{
			if ( analyzedLine [i] == shadowCellState[cross] || 
				 analyzedLine [i] == shadowCellState[nill] )
			{
				ChangeWeight( weight );
			}		    
		}

		//if in analyzedLine exist ++ oo change weight again
		if ( GetCountSym( analyzedLine, shadowCellState[cross] ) == 2 || 
			 GetCountSym( analyzedLine, shadowCellState[nill] ) == 2 )
		{
			ChangeWeight( weight );
		}

		
		return weight;
	}

	void Computer::ChangeWeight( int& weight )
	{
		if ( mOpponentShape == cross )
		{
			weight --;
		}
		else 
		{
			weight ++;
		}
	}

	int Computer::DoStep( Field& field )
	{
		//Change state
		if ( field.IsFieldFiled() )
			return -1;

		int numCell = 0;
		while ( field.GetStateCell( numCell ) != empty )
		{
			numCell = GetBestCellPosition( field ) ;
		}

		field.ChangeStateCell( numCell, mOpponentShape );
		return numCell ;

		return -1;
	}

	const TypeActor Computer::GetTypeActor() const
	{
		return TA_Computer;
	}

	int Computer::GetCountSym( const std::string &analyzedLine, char sym )
	{
		return count_if( analyzedLine.begin(), 
			analyzedLine.end(), 
			std::bind2nd ( std::equal_to<char>(), sym ) );
	}
	
}