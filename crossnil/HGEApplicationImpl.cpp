#include "HGEApplicationImpl.h"
#include "ApplicationStrategy\ApplicationStrategy.h"
#include "ApplicationStrategy\GameStrategy.h"
#include "ApplicationStrategy\MenuStrategy.h"

#include "HGEHelpers\GFXWrapper.h"
#include "HGEHelpers\SystemWrapper.h"

#include "exceptions\exception.h"


using namespace exceptions;
using namespace Strategy;

namespace Application
{

	HGEApplicationImpl::HGEApplicationImpl() :  mHgePtr ( new HGEHelpers::HGEWrapper )
	{
	}

	void HGEApplicationImpl::SetFrameFunc ( hgeCallback frameFunc )
	{
		mHgePtr->SetFrameFunc (  frameFunc );
	}

	void HGEApplicationImpl::SetRenderFunc ( hgeCallback frameFunc )
	{
		mHgePtr->SetRenderFunc (  frameFunc );
	}

	void HGEApplicationImpl::SetWindowed ()
	{
		mHgePtr->SetWindowed ();
	}


	void HGEApplicationImpl::Render()
	{

		HGEHelpers::GFXWrapper gfx ( mHgePtr );

		gfx.ClearGFX( 0 );
		
		mApplicationStrategy->Render();
	}

	bool HGEApplicationImpl::ProcessingClick()
	{
		Action  action = mApplicationStrategy->ProccessingClick();

		switch ( action )
		{
		case StartGame:
			{
				
				std::auto_ptr <Options> options = mApplicationStrategy->GetOptions();

				//Create Game Strategy
				mApplicationStrategy = std::auto_ptr<Strategy::ApplicationStrategy> ( new GameStrategy ( mHgePtr, *options.get() ) );
				break;
			}			
		case ExitFromApplication:
			//delete mGameStrategy
			//delete mMenuStrategy
			return true;
			break;
		case ReturnToMenu:
			{
				mApplicationStrategy = std::auto_ptr<Strategy::ApplicationStrategy> ( new MenuStrategy ( mHgePtr ) );
		
				break;
			}
		case Processed:
			return false;
			break;
		case Default:
			//assert
			break;
		}

		return false;
	}


	void HGEApplicationImpl::Execute()
	{

		HGEHelpers::SystemWrapper system ( mHgePtr );
		
			//When we implement menu we should change mApplicationStrategy on MenuStategy
			//After that we can remove creating in ProcessingClick
			mApplicationStrategy = std::auto_ptr<MenuStrategy> ( new MenuStrategy ( mHgePtr) );

		system.Start();
			
	}

	HGEApplicationImpl::~HGEApplicationImpl()
	{

	}

}