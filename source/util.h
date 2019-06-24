#ifndef __UTIL_H__
#define __UTIL_H__

#include <SDL.h>

bool ContainsPoint( SDL_Rect r, int x, int y )
{
	if( x > r.x && x < r.x + r.w && y > r.y && y < r.y + r.h )
		return true;

	return false;
}

#endif /* __UTIL_H__ */