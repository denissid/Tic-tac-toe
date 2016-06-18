#ifndef WinnerBanner_h__
#define WinnerBanner_h__

#include "../HGEHelpers/HGEWrapper.h"

#include <string>

namespace Banners
{

	class WinnerBanner
	{
		std::string mWinnerName;
		
		bool mIsShowBanner;
		float mFixedTime;
		HGEHelpers::HGESharedPtr mHge;

	public:

		WinnerBanner ( HGEHelpers::HGESharedPtr hge );

		void SetWinnerName ( const std::string& winnerName );		
		void Render ();

		bool IsShow ();

		~WinnerBanner () 
		{
		}

	private:

		WinnerBanner ( const WinnerBanner& );
		WinnerBanner& operator= ( const WinnerBanner& );

		void SetShowMode();

	};

}

#endif // WinnerBanner_h__