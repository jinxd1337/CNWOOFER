#include "engine.h"
#include "spawner.h"

#include "player.h"

CSpawner::CSpawner( void )
{	
	RegisterMaker( new CPlayerMaker );
	RegisterMaker( new CTestEntMaker );
}

CSpawner::~CSpawner( void )
{

}

void CSpawner::RegisterMaker( CMaker* mkr )
{
	if( mkr )
		Makers[ mkr->EntName ] = mkr;
}

CEntity* CSpawner::CreateEntity( std::string name )
{
	CEntity* ent;

	if( Makers[ name ] )
	{
		ent = Makers[ name ]->CreateEntity();
		
		if( ent )
		{
			ent->Spawn();
			gEngine->AddEntity( ent );

			return ent;
		}
	
	}

	return NULL;
}


CSpawner* gSpawner;

