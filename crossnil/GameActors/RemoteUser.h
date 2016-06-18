#ifndef RemoteUser_h__
#define RemoteUser_h__

#include "..\GameField\Field.h"
#include "..\GameLogic\GameJournal.h"
#include "IActor.h"

namespace GameActors
{

	class RemoteUser : public IActor 
	{

		GameField::CellState mOpponentShape; 

	private:

		RemoteUser ( const RemoteUser& );
		RemoteUser& operator= ( const RemoteUser& );

	public:

		RemoteUser ( const GameField::CellState& opponentShape  ) : mOpponentShape (opponentShape )
		{}

		virtual const TypeActor GetTypeActor () const
		{
			return TA_RemoteUser;
		}
		virtual int DoStep( GameField::Field& field )
		{
			return 0;
		}

		virtual bool GetClickedPos( float& x, float& y )
		{
			return false;
		}

		virtual ~RemoteUser () 
		{
		}
	};

}

#endif // RemoteUser_h__