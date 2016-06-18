#ifndef CreatorActors_h__
#define CreatorActors_h__

#include "IActor.h"
#include "..\GameField\FieldDefines.h"
#include "..\HGEHelpers\HGEWrapper.h"


namespace GameActors
{

	ActorSharedPtr CreateActor ( const GameActors::TypeActor& typeActor, HGEHelpers::HGESharedPtr hge, const GameField::CellState& userShape );

}

#endif // CreatorActors_h__