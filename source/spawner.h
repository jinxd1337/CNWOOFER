#ifndef __SPAWNER_H__
#define __SPAWNER_H__

#include <map>

#include "entity.h"
#include "player.h"
#include "testent.h"

class CMaker
{
public:

	std::string EntName;

	CMaker( void ) {};
	~CMaker( void ) {};

	virtual CEntity* CreateEntity( void ) = 0;

};

class CSpawner
{
public:

	CSpawner( void );
	~CSpawner( void );

	std::map<std::string, CMaker*> Makers;

	void RegisterMaker( CMaker* mkr );
	CEntity* CreateEntity( std::string name );

};

class CPlayerMaker : public CMaker
{
public:

	CPlayerMaker( void ) { EntName = "player"; };
	~CPlayerMaker( void ) {};

	CEntity* CreateEntity( void )
	{
		return new CPlayer;
	}

};

class CTestEntMaker : public CMaker
{
public:

	CTestEntMaker( void ) { EntName = "testent"; };
	~CTestEntMaker( void ) {};

	CEntity* CreateEntity( void )
	{
		return new CTestEnt;
	}

};

extern CSpawner* gSpawner;

#endif /* __SPAWNER_H__ */