#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <SDL.h>
#include "engine.h"

class CImage
{
	SDL_Texture* Texture;
	SDL_Rect Pos;

public:

	CImage( std::string filename, int x, int y )
	{
		Texture = gEngine->GetImage( filename );
		SDL_QueryTexture( Texture, NULL, NULL, &Pos.w, &Pos.h );
		Pos.x = x;
		Pos.y = y;

	}
	~CImage( void ) {}

	void SetPos( int x, int y )
	{
		Pos.x = x;
		Pos.y = y;
	}

	void Draw( void )
	{
		gEngine->DrawImage( Texture, Pos );
	}

};

#endif