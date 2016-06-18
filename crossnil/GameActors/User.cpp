#include "User.h"

#include "..\GameField\Field.h"

using namespace GameField;

namespace GameActors
{

	int User::DoStep( Field& field )
	{
		float x = 0; 
		float y = 0;
		if ( !GetClickedPos ( x, y ) )
			return -1;

		int numCell = field.GetNumCell ( x, y );

		if ( numCell != -1 && field.GetStateCell( numCell ) == empty )
		{		
			field.ChangeStateCell( numCell, mUserShape );
			return numCell;		
		}
		return -1;
	}

	bool User::GetClickedPos( float& x, float& y )
	{
		if ( mHge->GetKeyState ( HGEK_LBUTTON ) )
		{	
			mHge->GetMousePos ( &x, &y );
			return true;
		}
		return false;	
	}

	const TypeActor User::GetTypeActor() const
	{
		return TA_User;
	}

}