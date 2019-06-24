#include "spawner.h"
#include "testent.h"

CTestEnt::CTestEnt( void )
{

}

CTestEnt::~CTestEnt( void )
{

}

void CTestEnt::Spawn( void )
{
	Box.w = 32;
	Box.h = 32;
	Box.x = rand() % 800;
	Box.y = rand() % 600;
}

void CTestEnt::Think( void )
{
	NextThink += 100;
}

void CTestEnt::Death( void )
{

}

void CTestEnt::Collided( CEntity* e )
{

}

void CTestEnt::TakeDamage( int amount, int type )
{

}