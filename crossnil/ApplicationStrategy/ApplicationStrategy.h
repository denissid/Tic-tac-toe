#ifndef ApplicationStrategy_h__
#define ApplicationStrategy_h__

#include "..\HGEHelpers\HGEWrapper.h"
#include "..\ApplicationStrategy\Options.h"

#include <memory>

namespace Strategy
{
	enum Action
	{
		StartGame,
		ExitFromApplication,
		ReturnToMenu,
		Option,
		Processed,
		Default
	};

	class ApplicationStrategy 
	{
		HGEHelpers::HGESharedPtr mHge;

	private:

		ApplicationStrategy ( const ApplicationStrategy& );
		ApplicationStrategy& operator= ( const ApplicationStrategy& );

	public:
		ApplicationStrategy ( HGEHelpers::HGESharedPtr hge ) : mHge ( hge )
		{
		}

		virtual void Render ()  = 0;
		virtual Action ProccessingClick ();
		virtual std::auto_ptr<Options> GetOptions() const = 0;
		
		//HGE* GetHGE () const;

		virtual ~ApplicationStrategy () {}
	};

}


#endif // ApplicationStrategy_h__