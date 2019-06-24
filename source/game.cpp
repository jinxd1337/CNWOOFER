#include "engine.h"
#include "game.h"
#include "spawner.h"

CGame::CGame( void )
{

}

CGame::~CGame( void )
{

}

void CGame::Update( void )
{
	if( gEngine->GetKeyState( SDLK_ESCAPE ) )
	{
		gEngine->SetState( STATE_GAMEMENU );
	}

	gEngine->UpdateEntities();
}

void CGame::StartGame( void )
{
	Player = (CPlayer*)gSpawner->CreateEntity( "player" );
	Player->Box.x = 200;
	Player->Box.y = 200;

	for( int i = 0; i < 5; i++ )
	{
		gSpawner->CreateEntity( "testent" );
	}

	gEngine->SetState( STATE_GAME );
}