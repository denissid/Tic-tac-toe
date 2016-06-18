#include "stdafx.h"

#include "..\..\3dparty\hge181\include\hge.h"

#include "HGEApplication.h"
#include "exceptions\exception.h"
#include "HGEApplicationImpl.h"

namespace Application 
{

	HGEApplicationImpl HGEApplication::hgeApplicationImpl;

	HGEApplication::HGEApplication()
	{
		hgeApplicationImpl.SetFrameFunc ( HGEApplication::FrameFunc );
		hgeApplicationImpl.SetRenderFunc ( HGEApplication::RenderFunc );
        hgeApplicationImpl.SetWindowed ();
	}

	bool HGEApplication::RenderFunc ()
	{

		hgeApplicationImpl.Render();

		return false;
	}

	bool HGEApplication::FrameFunc()
	{

		return hgeApplicationImpl.ProcessingClick();

		// Continue execution
		return false;
	}

	void HGEApplication::Execute()
	{
		hgeApplicationImpl.Execute();
	}

	HGEApplication::~HGEApplication()
	{	
	}

}

