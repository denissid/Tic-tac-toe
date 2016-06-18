#include "CreatorActors.h"

#include "Computer.h"
#include "RemoteUser.h"
#include "User.h"

#include <assert.h>

using namespace GameField;

namespace GameActors
{

	ActorSharedPtr CreateActor( const TypeActor& typeActor, HGEHelpers::HGESharedPtr hge, const CellState& userShape )
	{

		switch ( typeActor )
		{
		case TA_Computer:
			{
				return std::tr1::shared_ptr<IActor> ( new Computer ( userShape ) );
			}
		case TA_User:
			{
				return std::tr1::shared_ptr<IActor> ( new User ( hge, userShape ) );
			}
		case TA_RemoteUser:
			{
				return std::tr1::shared_ptr<IActor> ( new RemoteUser ( userShape ));
			}
		default:
			{
				assert( !"Unknown actor" );
				//return NULL;
			}
		}

		return std::tr1::shared_ptr<IActor> (NULL);
	}

}