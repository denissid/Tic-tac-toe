#include "Font.h"

hgeFont& GetFontInstance()
{
	static Font font;
	return font.Get();
}

hgeFont& Font::Get()
{
	return mFont;
}