#include "engine.h"
#include "text.h"
#include "menu.h"
#include "game.h"
#include "spawner.h"


int main( int argc, char* argv[] )
{
	gEngine = new CEngine;

	if( !gEngine->Initialize() )
		return -1;

	CMenu* Menu = new CMenu;
	CGame* Game = new CGame;
	gSpawner = new CSpawner;

	while( gEngine->GetState() != STATE_QUIT )
	{
		gEngine->PreFrame();

		if( gEngine->GetState() == STATE_MENU || gEngine->GetState() == STATE_GAMEMENU )
		{
			Menu->Update();
		}
		else if( gEngine->GetState() == STATE_GAME )
		{
			Game->Update();
		}
		else if( gEngine->GetState() == STATE_NEWGAME )
		{
			Game->StartGame();
		}
		
		gEngine->PostFrame();
	}

	gEngine->Shutdown();

	delete Menu, gEngine;

	return 0;
}