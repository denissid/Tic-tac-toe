#include "GameJournal.h"
#include "WinnerCombination.h"

#include "..\GameActors\IActor.h"
#include "..\GameActors\User.h"
#include "..\GameActors\Computer.h"
#include "..\GameField\FieldDefines.h"

#include <sstream>
#include <algorithm>

using namespace GameField;
using namespace GameActors;

namespace GameLogic
{

	const std::string::size_type gMaxCountWaysForActor = 3;
	

	void GameJournal::Clear()
	{
			mUserMoves.clear();
			mOpponentMoves.clear();
			mNumMove = 0;
			mPreviousActor.reset();
	}

	bool GameJournal::WriteRecord( const int& numCell, GameActors::ActorSharedPtr actor )
	{
		//Check that same actor haven't done 2 moves repeatedly
		if ( mPreviousActor == actor ) 
		{
			return false;
		}

		mPreviousActor = actor;

		//Save info about move
		std::stringstream tmp;
		tmp << numCell;

		if ( mPreviousActor->GetTypeActor() == TA_User )
		{
			mNumMove++;
			mUserMoves += tmp.str() ;
		}
		else
		{
			mNumMove++;
			mOpponentMoves += tmp.str();
		}

		return true;
	}

	GameActors::ActorSharedPtr GameJournal::WhoseMove()
	{

		//First move
		if ( mNumMove == NULL && mPreviousActor == NULL )
		{
			if ( mUserShape ==  cross )
			{
				return mUser;
			}
			else 
			{	
				return mOpponent;
			}
		}

		//1,2,3,4,5 move
		if ( mPreviousActor->GetTypeActor() == TA_User )
		{
			return mOpponent;
		}
		else 
		{
			return mUser;
		}
 
		
		return ActorSharedPtr();
	}

	bool GameJournal::IsGameOver()
	{
		const unsigned int gMaxCountWays = 10;

		if ( gMaxCountWays==mNumMove )
			return true;

		if ( gMaxCountWays>=mNumMove )
		{
			const TypeActor ta = GetWinner();
			if ( ta == TA_Unknoun )
				return false;
			else 
				return true;
		}

		return true;
	}

	const TypeActor GameJournal::GetWinner()
	{
		std::sort( mUserMoves.begin(), mUserMoves.end() );
		std::sort( mOpponentMoves.begin(), mOpponentMoves.end() );

		if ( IsUserWinner ( mUserMoves ) )
			return TA_User;

	    if ( IsUserWinner ( mOpponentMoves ) )			
			return mOpponent->GetTypeActor();

		return TA_Unknoun;
	}

	bool GameJournal::IsUserWinner( std::string &moves )
	{		
		for ( int k = 0; k< countWinnerCombination; k++ )
		{
			std::string line = winnerCombination[k];
			if ( std::includes ( moves.begin(), moves.end(), line.begin(), line.end() ) )
				return true;
		
		}

		return false;
	}
}