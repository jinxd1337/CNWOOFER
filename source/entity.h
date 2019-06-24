#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SDL.h>

enum {
	REL_NONE = 0,
	REL_PLAYER,
	REL_ENEMY,
	REL_BULLET,
	REL_EXPLOSION
};

enum {
	DMG_NORMAL = 0
};

class CEntity
{
public:

	CEntity( void ) 
	{
		NextThink = UID = Health = 0;
		Relation = REL_NONE;
		Remove = false;
	}
	~CEntity( void ) {}

	bool Remove;

	int UID;
	int Relation;
	int Health;

	SDL_Rect Box;
	int OrgX, OrgY;

	int NextThink;

	virtual void Spawn( void ) = 0;
	virtual void Think( void ) = 0;
	virtual void Death( void ) = 0;
	virtual void Collided( CEntity* e ) = 0;
	virtual void TakeDamage( int amount, int type ) = 0;

};

#endif /* __ENTITY_H__ */