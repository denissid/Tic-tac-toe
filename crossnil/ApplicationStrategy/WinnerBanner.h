#ifndef WinnerBanner_h__
#define WinnerBanner_h__

#include <string>

#include "..\..\..\3dparty\hge181\include\hge.h"
#include "..\..\..\3dparty\hge181\include\hgefont.h"

namespace
{

	class WinnnerBanner
	{
		hgeFont mFnt;
		std::string mWinnerName;
		HGE* mHge;
		bool mIsShowBanner;

	public:

		WinnnerBanner ( HGE* hge ): mHge( hge ), mFnt ( "font1.fnt" ), mIsShowBanner ( false )
		{			

		}

		void SetWinnerName ( const std::string& winnerName );
		void Render ();

		~WinnnerBanner () 
		{
		}

	private:

		WinnnerBanner ( const WinnnerBanner& );
		WinnnerBanner& operator= ( const WinnnerBanner& );

	};

}

#endif // WinnerBanner_h__