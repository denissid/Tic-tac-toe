#ifndef Font_h__
#define Font_h__

#include "..\..\..\3dparty\hge181\include\hgefont.h"

class Font
{

	hgeFont mFont;

public:
	
	friend hgeFont& GetFontInstance();

private:

	hgeFont& Get ();

	Font (): mFont ( "font1.fnt" )
	{
	}

};

hgeFont& GetFontInstance();

#endif // Font_h__