#ifndef GameJournal_h__
#define GameJournal_h__

#include "..\GameActors\TypeActors.h"
#include "..\GameField\FieldDefines.h"
#include "..\GameActors\IActor.h"

#include <string>


namespace GameLogic
{
	
	class GameJournal
	{

		GameField::CellState mUserShape;
		int mNumMove;
		GameActors::ActorSharedPtr mOpponent;
		GameActors::ActorSharedPtr mUser;

		//who is last move
		GameActors::ActorSharedPtr mPreviousActor;

		std::string mUserMoves;
		std::string mOpponentMoves;

	private:

		GameJournal ( const GameJournal& );
		GameJournal& operator= ( const GameJournal& );

	public:

		GameJournal ( GameField::CellState userShape, GameActors::ActorSharedPtr opponent, GameActors::ActorSharedPtr user ): mUserShape  ( userShape ),
			mNumMove ( 0 ),
			mOpponent ( opponent ),
			mUser ( user )
		{
		}

		bool WriteRecord ( const int& numCell, GameActors::ActorSharedPtr actor );
		GameActors::ActorSharedPtr WhoseMove () ;		
		const GameActors::TypeActor GetWinner ();

		bool IsGameOver () ;

		void Clear ();

		~GameJournal()
		{
		}

private:
		bool IsUserWinner( std::string &moves );
	
	};

}

#endif // GameJournal_h__