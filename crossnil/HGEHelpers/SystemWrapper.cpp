#include "SystemWrapper.h"

namespace HGEHelpers
{

	SystemWrapper::SystemWrapper( HGESharedPtr mHge ) : mHgePtr ( mHge )
	{
		if ( ! mHgePtr->GetHGE()->System_Initiate() )
		{
			throw exceptions::HGEApplicationException( mHgePtr->GetHGE()->System_GetErrorMessage() );
		}
	}

	void SystemWrapper::Start()
	{
		mHgePtr->GetHGE()->System_Start();
	}
}