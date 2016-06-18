#ifndef GameStrategy_h__
#define GameStrategy_h__

#include "ApplicationStrategy.h"
#include "..\Banners\WinnerBanner.h"
#include "..\HGEHelpers\HGEWrapper.h"

#include <sstream>
#include <memory>

namespace GameLogic
{
	class GameJournal;
}

namespace GameField
{
	class Field;
}

namespace GameActors
{
	class IActor;
}

namespace Strategy
{

	class Options;
	
	class GameStrategy: public ApplicationStrategy
	{
		std::tr1::shared_ptr <GameField::Field> mField;

		std::tr1::shared_ptr <GameLogic::GameJournal> mGameJournal;
		GameActors::ActorSharedPtr mOpponent;
		GameActors::ActorSharedPtr mUser;

		std::stringstream mProcessed;
		Banners::WinnerBanner mWinnerBanner;

	private:

		GameStrategy ( const GameStrategy& );
		GameStrategy& operator= ( const GameStrategy& );

	public:

		GameStrategy ( HGEHelpers::HGESharedPtr hge, const Options& options );

		virtual std::auto_ptr<Options> GetOptions() const;

		virtual void Render ();
		virtual Action ProccessingClick () ;

		virtual bool GetResult () const
		{
			return true;
		}

		virtual ~GameStrategy ();

	};

}

#endif // GameStrategy_h__