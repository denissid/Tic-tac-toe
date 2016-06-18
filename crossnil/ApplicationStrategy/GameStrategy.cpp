#include "..\ApplicationStrategy\GameStrategy.h"
#include "..\GameActors\CreatorActors.h"
#include "..\GameActors\TypeActors.h"
#include "..\GameField\Field.h"
#include "..\ApplicationStrategy\Options.h"
#include "..\GameActors\TypeActors.h"
#include "..\GameLogic\GameJournal.h"

using namespace GameField;
using namespace Strategy;
using namespace GameActors;
using namespace GameLogic;

namespace Strategy
{

	GameStrategy::GameStrategy( HGEHelpers::HGESharedPtr hge, const Options& options ) : ApplicationStrategy ( hge ),
																	 mField ( new Field () ), 																		
																	 mWinnerBanner ( hge )
	{
		mField->CreateCells( hge );
		
		CellState userShape = options.GetUserShape();
		TypeActor opponent = options.GetTypeActor();

		CellState opponentShape = empty;
		if ( opponent != TA_User )
			opponentShape = ( userShape == cross ? nill : cross ) ;

		mOpponent = CreateActor ( opponent, hge, opponentShape );
		mUser = CreateActor ( TA_User,  hge, userShape );

		mGameJournal = std::tr1::shared_ptr<GameJournal> ( new GameJournal ( userShape, mOpponent, mUser ) );
	}

	void GameStrategy::Render()
	{	
		mField->Render();
		mWinnerBanner.Render();
	}

	Action GameStrategy::ProccessingClick()
	{
		//If Exit pressed
		Action action = ApplicationStrategy::ProccessingClick();
		if ( action == ExitFromApplication ) 
			return ExitFromApplication;

		if ( !mGameJournal->IsGameOver() )
		{
			ActorSharedPtr actor = mGameJournal->WhoseMove();
			int numCell = actor->DoStep ( *mField );

			if ( numCell != -1 )
			{
				mGameJournal->WriteRecord( numCell, actor );
			}
		}
		else
		{
			const TypeActor ta = mGameJournal->GetWinner ();
			std::string nameWinnerActor = NamesTypeActor [ ta ];
			mWinnerBanner.SetWinnerName( nameWinnerActor );

			if ( mWinnerBanner.IsShow () )
			{
				return Processed;
				
			}
			return ReturnToMenu;
			
		}
		
		return Processed;
	}

	GameStrategy::~GameStrategy()
	{
		
	}

	std::auto_ptr<Options> GameStrategy::GetOptions() const
	{
		std::auto_ptr <Options> tmp ( new Options ( cross, TA_Computer ) );
		return tmp;
	}
}