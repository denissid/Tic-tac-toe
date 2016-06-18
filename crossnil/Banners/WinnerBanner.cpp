#include "WinnerBanner.h"
#include "..\Service\Font.h"

namespace Banners
{

	WinnerBanner::WinnerBanner( HGEHelpers::HGESharedPtr hge ) : mHge ( hge ), 
											 mIsShowBanner ( false ),
									         mFixedTime ( 0 )
	{			
	}

	void WinnerBanner::SetWinnerName( const std::string& winnerName )
	{
		mWinnerName = winnerName;
		SetShowMode();
	}

	void WinnerBanner::Render()
	{
		if ( mIsShowBanner )
		{
			GetFontInstance().printf ( 50, 50, HGETEXT_LEFT, "Winner %s", mWinnerName.c_str() );			
		}
	}

	void WinnerBanner::SetShowMode()
	{		
		mIsShowBanner = true;
	}

	bool WinnerBanner::IsShow()
	{
		const float timeWaiting  = 3;
		if ( mFixedTime == 0 )
			 mFixedTime = mHge->GetTime(); 

		float currentTime = mHge->GetTime(); 
		if ( currentTime - mFixedTime > timeWaiting )
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	
}