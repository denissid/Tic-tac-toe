#ifndef MenuStrategy_h__
#define MenuStrategy_h__

#include "ApplicationStrategy.h"
#include "Options.h"
#include "..\HGEHelpers\HGEWrapper.h"

#include <memory>

namespace Strategy
{

	class MenuStrategy : public ApplicationStrategy
	{

		HGEHelpers::HGESharedPtr mHge;

	private:

		MenuStrategy ( const MenuStrategy& );
		MenuStrategy& operator= ( const MenuStrategy& );

	public:

		MenuStrategy ( HGEHelpers::HGESharedPtr hge );

		virtual void Render ();
		virtual std::auto_ptr<Options> GetOptions() const;
		virtual Action ProccessingClick () ;

		~MenuStrategy () {}
	};

}

#endif // MenuStrategy_h__