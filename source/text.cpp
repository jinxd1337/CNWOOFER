#include "engine.h"
#include "text.h"

CText::CText( std::string str, std::string font, int size, int x, int y, int r, int g, int b, int a )
{
	Font = gEngine->GetFont( font, size );
	Pos.x = x;
	Pos.y = y;
	Color.r = r;
	Color.g = g;
	Color.b = b;
	Color.a = a;
	Value = str;

	RenderText();
}

CText::~CText( void )
{
}

void CText::Draw( void )
{
	gEngine->DrawText( Texture, Pos );
}

void CText::SetFont( std::string font, int size )
{
	Font = gEngine->GetFont( font, size );
}

void CText::SetValue( std::string str )
{
	Value = str;

	RenderText();
}

void CText::SetPos( int x, int y )
{
	Pos.x = x;
	Pos.y = y;
}

void CText::SetColor( int r, int g, int b, int a )
{
	Color.r = r;
	Color.g = g;
	Color.b = b;
	Color.a = a;

	RenderText();
}

void CText::RenderText( void )
{
	Texture = gEngine->RenderText( Value, Font, Color );
}