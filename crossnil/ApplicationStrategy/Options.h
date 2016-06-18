#ifndef Options_h__
#define Options_h__

#include "..\GameField\FieldDefines.h"
#include "..\GameActors\CreatorActors.h"

namespace Strategy
{

	class Options 
	{
		//Which figure move user 
		GameField::CellState mUserShape;

		//Who will opponent computer or remote user 
		GameActors::TypeActor mTypeActor;

	public:

		Options ( GameField::CellState userShape, GameActors::TypeActor typeActor ): 
		  mUserShape ( userShape ),
			  mTypeActor ( typeActor )
		  {}

		  GameActors::TypeActor GetTypeActor() const 
		  {
			  return mTypeActor;
		  }

		  GameField::CellState GetUserShape () const
		  {
			  return mUserShape;
		  }

	};

}

#endif // Options_h__