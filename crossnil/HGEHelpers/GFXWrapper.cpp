#include "GFXWrapper.h"

namespace HGEHelpers
{
	GFXWrapper::GFXWrapper( HGESharedPtr hge ) : mHge ( hge )
	{
		mHge->mHge->Gfx_BeginScene();
	}

	void GFXWrapper::ClearGFX( int colour )
	{
		mHge->mHge->Gfx_Clear ( colour );
	}

	GFXWrapper::~GFXWrapper()
	{
		mHge->mHge->Gfx_EndScene ();
	}
}