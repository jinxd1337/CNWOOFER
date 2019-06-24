#include "engine.h"
#include "spawner.h"
#include "player.h"

CPlayer::CPlayer( void )
{

}

CPlayer::~CPlayer( void )
{

}

void CPlayer::Spawn( void )
{
	Box.w = 16;
	Box.h = 48;
	Box.x = 0;
	Box.y = 0;
}
void CPlayer::Think( void )
{
	NextThink += 100;

	Box.x = rand() % 800;
	Box.y = rand() % 600;
}
void CPlayer::Death( void )
{

}
void CPlayer::Collided( CEntity* e )
{

}
void CPlayer::TakeDamage( int amount, int type )
{

}