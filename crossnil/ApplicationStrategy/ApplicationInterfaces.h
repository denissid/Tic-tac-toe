#ifndef ApplicationInterfaces_h__
#define ApplicationInterfaces_h__

#include "Options.h"

#include <memory>

namespace Strategy 
{
	class IMenu
	{
	private:
		IMenu ( const IMenu& );
		IMenu& operator= ( const IMenu& );
	public:
		IMenu (){}
		virtual std::auto_ptr<Options> GetOptions() const = 0;
		virtual ~IMenu () = 0
		{}
	};

	class IGame 
	{
	private:
		IGame ( const IGame& );
		IGame& operator= ( const IGame& );

	public:
		IGame (){}
		virtual bool GetResult () const = 0;
		virtual ~IGame ()  = 0
		{}

	};

}

#endif // ApplicationInterfaces_h__