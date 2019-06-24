#ifndef __TEXT_H__
#define __TEXT_H__

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class CText
{
	std::string Value;
	SDL_Color Color;
	SDL_Rect Pos;
	SDL_Texture* Texture;
	TTF_Font* Font;
	int Size;

	void RenderText( void );

public:

	CText( std::string str, std::string font, int size, int x, int y, int r = 255, int g = 255, int b = 255, int a = 255 );
	~CText( void );

	void Draw( void );

	void SetFont( std::string font, int size );
	void SetPos( int x, int y );
	void SetColor( int r, int g, int b, int a );
	void SetValue( std::string str );
};

#endif __TEXT_H__