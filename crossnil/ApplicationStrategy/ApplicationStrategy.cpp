#include "ApplicationStrategy.h"

namespace Strategy 
{


	Action ApplicationStrategy::ProccessingClick()
	{
	
		if ( mHge->GetKeyState ( HGEK_ESCAPE ) ) 
			return ExitFromApplication;

		return Default;
	}

}

