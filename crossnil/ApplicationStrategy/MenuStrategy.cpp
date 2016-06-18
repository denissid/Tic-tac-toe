#include "MenuStrategy.h"
#include "Options.h"

#include "..\Service\Font.h"
#include "..\GameActors\TypeActors.h"

#include <memory>

using namespace GameField;
using namespace GameActors;

namespace Strategy
{

	MenuStrategy::MenuStrategy( HGEHelpers::HGESharedPtr hge ) : ApplicationStrategy ( hge ), mHge ( hge )
	{

	}

	void MenuStrategy::Render()
	{
		const float xPosition = 80;
		const float yPosistion = 80;
		GetFontInstance().printf(  xPosition, yPosistion, HGETEXT_LEFT, "press space to Start game" );
		
	}

	std::auto_ptr<Options> MenuStrategy::GetOptions() const
	{
		std::auto_ptr <Options> tmp ( new Options ( cross, TA_Computer ) );
		return tmp;
	}

	Action MenuStrategy::ProccessingClick()
	{
		//Process click on Exit 
		//If Exit pressed
		Action action = ApplicationStrategy::ProccessingClick();
		if ( action == ExitFromApplication ) 
			return ExitFromApplication;

		//Process click on Start
		//return 	StartGame
		if ( mHge->GetKeyState ( HGEK_SPACE ) )
		{
			return StartGame;
		}

		//Process click on option
		//return Option,

		// Choose another item menu
		return Processed;
	}

}