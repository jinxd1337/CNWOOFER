#ifndef __TESTENT_H__
#define __TESTENT_H__

#include "entity.h"

class CTestEnt : public CEntity
{
public:

	CTestEnt( void );
	~CTestEnt( void );

	void Spawn( void );
	void Think( void );
	void Death( void );
	void Collided( CEntity* e );
	void TakeDamage( int amount, int type );

};

#endif /* __TESTENT_H__ */