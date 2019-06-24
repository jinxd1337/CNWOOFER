#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "entity.h"

class CPlayer : public CEntity
{
public:

	CPlayer( void );
	~CPlayer( void );

	void Spawn( void );
	void Think( void );
	void Death( void );
	void Collided( CEntity* e );
	void TakeDamage( int amount, int type );

};

#endif /* __PLAYER_H__ */