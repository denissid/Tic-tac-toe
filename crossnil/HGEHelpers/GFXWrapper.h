#ifndef GFXWrapper_h__
#define GFXWrapper_h__

#include "HGEWrapper.h"

namespace HGEHelpers
{
	class GFXWrapper
	{
		HGESharedPtr mHge;

	public:

		GFXWrapper( HGESharedPtr hge );

		void ClearGFX( int colour );

		~GFXWrapper ();
	};

}

#endif // GFXWrapper_h__