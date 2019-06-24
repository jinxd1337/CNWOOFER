#ifndef __GAME_H__
#define __GAME_H__

#include "player.h"

class CGame
{
public:

	CGame( void );
	~CGame( void );

	void Update( void );
	void StartGame( void );

	CPlayer* Player;

};

#endif /* __GAME_H__ */