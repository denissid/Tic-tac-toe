#ifndef HGEWrapper_h__
#define HGEWrapper_h__

#include "..\..\..\3dparty\hge181\include\hge.h"
#include <memory>

#include "..\exceptions\exception.h"

namespace HGEHelpers
{

	class HGEWrapper 
	{

		HGE* mHge;

	private:
		HGE*  GetHGE ()
		{
			return mHge;
		}

	public:

		friend class GFXWrapper;
		friend class SystemWrapper;
		friend class TextureWrapper;

		HGEWrapper ();

		void System_Log ( const std::string& message );

		bool GetKeyState ( int key );
		void GetMousePos ( float *x, float* y );
	
		void SetFrameFunc ( hgeCallback frameFunc );
		void SetRenderFunc ( hgeCallback frameFunc );
		void SetWindowed ();

		float GetTime ()
		{
			return mHge->Timer_GetTime();
		}
		

		~HGEWrapper();
		
	};

	typedef std::tr1::shared_ptr <HGEWrapper> HGESharedPtr;

}

#endif // HGEWrapper_h__