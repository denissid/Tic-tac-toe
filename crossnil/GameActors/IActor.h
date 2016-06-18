#ifndef IActor_h__
#define IActor_h__

#include "TypeActors.h"
#include <memory>

namespace GameField
{
	class Field;
}

namespace GameActors
{

	class IActor
	{
	public:

		virtual int DoStep( GameField::Field& field ) = 0;
		virtual const GameActors::TypeActor GetTypeActor ()  const = 0;

		virtual ~IActor () = 0 
		{
		}

	};

	typedef std::tr1::shared_ptr <IActor> ActorSharedPtr;

}

#endif // IActors_h__