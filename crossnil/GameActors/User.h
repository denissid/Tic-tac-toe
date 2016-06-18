#ifndef User_h__
#define User_h__

#include "IActor.h"
#include "../HGEHelpers/HGEWrapper.h"

namespace GameField
{
	enum CellState;
}

class HGE;

namespace GameActors
{
	class User: public IActor
	{
		GameField::CellState mUserShape;
		HGEHelpers::HGESharedPtr mHge;

	private:

		User ( const User& );
		User& operator= ( const User& );

	public:

		User ( HGEHelpers::HGESharedPtr  hge, const GameField::CellState userShape ) : mUserShape ( userShape ),
			mHge ( hge )
		{}	

		virtual int DoStep( GameField::Field& field );
		virtual const TypeActor GetTypeActor () const;

		bool GetClickedPos( float& x, float& y );

		virtual ~User () 
		{
		}

	
	};

}

#endif // User_h__