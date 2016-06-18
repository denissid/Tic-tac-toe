#ifndef SystemWrapper_h__
#define SystemWrapper_h__

#include "HGEWrapper.h"

namespace HGEHelpers
{
	class SystemWrapper
	{
		HGESharedPtr mHgePtr;

	public:

		SystemWrapper ( HGESharedPtr mHge );

		void Start ();
		
	};
}

#endif // SystemWrapper_h__