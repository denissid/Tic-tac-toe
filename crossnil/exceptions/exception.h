
#ifndef exception_h__
#define exception_h__

#include <exception>
#include <string>
#include <memory>

namespace exceptions
{

	class HGEApplicationException : public std::exception
	{

	public:
		HGEApplicationException ( const char* reason ): std::exception ( reason )
		{}

	private:

		HGEApplicationException& operator= ( const HGEApplicationException& );
	};

	class SpriteException: public std::exception
	{
	public:
		SpriteException ( const char* reason ): std::exception ( reason )
		{}

	private:
		SpriteException& operator= ( const SpriteException& );
	};

}

#endif // exception_h__