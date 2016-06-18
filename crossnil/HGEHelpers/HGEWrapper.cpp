#include "HGEWrapper.h"


namespace HGEHelpers
{

	HGEWrapper::HGEWrapper() : mHge(NULL)
	{
		mHge = hgeCreate ( HGE_VERSION );
		if (  mHge == NULL )
			throw exceptions::HGEApplicationException( "Can't hgeCreate create" );

		mHge->System_SetState ( HGE_LOGFILE, "crossnil.log" );
		mHge->System_SetState ( HGE_TITLE, "Cross & nil " );
		mHge->System_SetState ( HGE_WINDOWED, true );
		mHge->System_SetState ( HGE_HIDEMOUSE, false );
		mHge->System_SetState ( HGE_USESOUND, false );
	}

	void HGEWrapper::System_Log( const std::string& message )
	{
		mHge->System_Log ( message.c_str() );
	}

	bool HGEWrapper::GetKeyState( int key )
	{
		return mHge->Input_GetKeyState ( key  );
	}

	void HGEWrapper::GetMousePos ( float *x, float* y )
	{
		mHge->Input_GetMousePos ( x, y );
	}

	HGEWrapper::~HGEWrapper()
	{
		mHge->System_Shutdown();
		mHge->Release();
		mHge = NULL;
	}

	void HGEWrapper::SetFrameFunc( hgeCallback frameFunc )
	{
		mHge->System_SetState ( HGE_FRAMEFUNC, frameFunc );
	}

	void HGEWrapper::SetRenderFunc( hgeCallback frameFunc )
	{
		mHge->System_SetState ( HGE_RENDERFUNC, frameFunc );
	}

	void HGEWrapper::SetWindowed()
	{
		mHge->System_SetState ( HGE_WINDOWED, true );
	}

}