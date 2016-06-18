#ifndef HGEApplicationImpl_h__
#define HGEApplicationImpl_h__

#include "HGEHelpers\HGEWrapper.h"

class HGE;

namespace Strategy
{
	class ApplicationStrategy;
	class GameStrategy;
	class MenuStrategy;
}

namespace Application 
{


	class HGEApplicationImpl 
	{
		HGEHelpers::HGESharedPtr mHgePtr;
	
		std::auto_ptr <Strategy::ApplicationStrategy> mApplicationStrategy;
		//std::auto_ptr <Strategy::GameStrategy> mGameStrategy;
		//std::auto_ptr <Strategy::MenuStrategy> mMenuStrategy;
		
	public:

		HGEApplicationImpl ();

		void SetFrameFunc ( hgeCallback frameFunc );
		void SetRenderFunc ( hgeCallback frameFunc );
		void SetWindowed ();

		void Render ( );	
		void Execute();
		bool ProcessingClick () ;

		~HGEApplicationImpl ();

	private:

		HGEApplicationImpl ( const HGEApplicationImpl& );
		HGEApplicationImpl& operator= ( const HGEApplicationImpl& );

	};

}


#endif // HGEApplicationImpl_h__