#ifndef Computer_h__
#define Computer_h__

#include "..\GameActors\IActor.h"

#include <map>

namespace GameField
{
	enum CellState;
}

namespace GameActors
{
	typedef std::multimap < int, std::string, std::greater<int> > ResultTree;

	class Computer: public IActor
	{

		GameField::CellState mOpponentShape; 

	private:

		Computer ( const Computer& );
		Computer& operator= ( const Computer& );

	public:
		Computer ( const GameField::CellState& opponentShape ) : mOpponentShape ( opponentShape )
		{}

		virtual const TypeActor GetTypeActor () const;
		virtual int DoStep( GameField::Field& field );	

		virtual ~Computer ();

	private:

		int GetBestCellPosition ( GameField::Field& field );
		void LookLines ( const std::string& shadowField, ResultTree& resultTree );
	
		int GetWeight( const std::string& analyzedLine );

		int GetCountSym( const std::string &analyzedLine, char sym );
		void ChangeWeight( int& weight );
		void LookColumns ( const std::string& shadowField, ResultTree& resultTree );
		void LookDiagonals ( const std::string& shadowField, ResultTree& resultTree );
	};

}

#endif // Computer_h__