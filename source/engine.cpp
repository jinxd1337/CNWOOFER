#include "config.h"
#include "engine.h"

CEngine::CEngine(void)
{

}

CEngine::~CEngine(void)
{

}

bool CEngine::Initialize(void)
{
	Config = new CConfig( "cfg/config.xml" );
	Elog = new CLogger( "engine.log" );

	State = STATE_MENU;

	Time = LastFrame = SDL_GetTicks();
	Delta = 0;

	EntCount = 0;

	if( SDL_Init( SDL_INIT_EVERYTHING ) )
		return false;

	if( TTF_Init() )
		return false;

	if( !IMG_Init( IMG_INIT_PNG ) )
		return false;

	Window = SDL_CreateWindow( "GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							   Config->GetParamI( "screenwidth" ), Config->GetParamI( "screenheight" ), 
							   SDL_WINDOW_OPENGL );

	if( !Window )
		return false;

	Renderer = SDL_CreateRenderer( Window, -1, 0 );

	if( !Renderer )
		return false;

	FPSText = new CText( "FPS: 0", "data/font/verdana.ttf", 18, 5, 5, 255, 0, 0, 255 );
	FPSCounter = FPSTime = 0;
	ShowFPS = false;

	return true;
}

bool CEngine::Shutdown( void )
{
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();

	delete Config, Elog, FPSText;

	return true;
}

void CEngine::PollEvents( void )
{
	SDL_Event e;

	for( std::map<int, int>::iterator i = KeyState.begin(); i != KeyState.end(); i++ )
	{
		if( i->second == KEY_DOWN )
			i->second = KEY_HELD;
	}

	while( SDL_PollEvent( &e ) )
	{
		if( e.type == SDL_QUIT )
		{
			State = STATE_QUIT;
		}
		else if( e.type == SDL_KEYDOWN )
		{
			if( KeyState[ e.key.keysym.sym ] == KEY_UP )
				KeyState[ e.key.keysym.sym ] = KEY_DOWN;
		}
		else if( e.type == SDL_KEYUP )
		{
			KeyState[ e.key.keysym.sym ] = KEY_UP;
		}
		else if( e.type == SDL_MOUSEBUTTONDOWN )
		{
			KeyState[ e.button.button ] = KEY_DOWN;
		}
	}
}

int CEngine::GetKeyState( int k )
{
	return KeyState[ k ];
}

void CEngine::GetMousePos( int* x, int* y )
{
	SDL_GetMouseState( x, y );
}

void CEngine::PreFrame( void )
{
	PollEvents();
	SDL_SetRenderDrawColor( Renderer, 0, 128, 255, 255 );
	SDL_RenderClear( Renderer );

	LastFrame = Time;
	Time = SDL_GetTicks();
	Delta = Time - LastFrame;

	if( Time >= FPSTime )
	{
		FPS = FPSCounter * 2;
		FPSCounter = 0;

		FPSTime = Time + 500;

		FPSText->SetValue( std::string( "FPS: " + std::to_string( FPS ) ) );
	}

	FPSCounter++;
}

void CEngine::PostFrame( void )
{
	if( GetKeyState( SDLK_F12 ) == KEY_DOWN )
		ShowFPS = !ShowFPS;

	if( ShowFPS )
		FPSText->Draw();


	SDL_RenderPresent( Renderer );
}

SDL_Texture* CEngine::GetImage( std::string filename )
{
	if( Images[ filename ] )
		return Images[ filename ];

	SDL_Surface* surface = IMG_Load( filename.c_str() );
	
	Images[ filename ] = SDL_CreateTextureFromSurface( Renderer, surface );

	SDL_FreeSurface( surface );

	return Images[ filename ];
}

void CEngine::DrawImage( SDL_Texture* texture, SDL_Rect pos )
{
	SDL_RenderCopy( Renderer, texture, NULL, &pos );
}

TTF_Font* CEngine::GetFont( std::string filename, int size )
{
	std::string fontname = filename + std::to_string( size );

	if( Fonts[ fontname ] )
		return Fonts[ fontname ];

	Fonts[ fontname ] = TTF_OpenFont( filename.c_str(), size );

	return Fonts[ fontname ];
}

SDL_Texture* CEngine::RenderText( std::string text, TTF_Font* font, SDL_Color color )
{
	SDL_Surface* surface = TTF_RenderText_Solid( font, text.c_str(), color );
	SDL_Texture* texture = SDL_CreateTextureFromSurface( Renderer, surface );
	SDL_FreeSurface( surface );

	return texture;
}

void CEngine::DrawText( SDL_Texture* text, SDL_Rect rect )
{
	SDL_QueryTexture( text, NULL, NULL, &rect.w, &rect.h );

	SDL_RenderCopy( Renderer, text, NULL, &rect );
}

void CEngine::DrawLineBox( SDL_Rect r )
{
	SDL_Point points[5] = 
	{
		{ r.x, r.y },
		{ r.x + r.w, r.y },
		{ r.x + r.w, r.y + r.h },
		{ r.x, r.y + r.h },
		{ r.x, r.y }
	};

	SDL_SetRenderDrawColor( Renderer, 255, 0, 0, 255 );
	SDL_RenderDrawLines( Renderer, points, 5 );
}

void CEngine::AddEntity( CEntity* ent )
{
	if( ent )
	{
		ent->UID = ++EntCount;

		Entities.push_back( ent );
	}
}

void CEngine::UpdateEntities( void )
{
	std::vector<CEntity*>::iterator i = Entities.begin();

	while( i != Entities.end() )
	{
		if( ( *i )->Remove )
		{
			delete ( *i );
			Entities.erase( i );
		}
		else if( ( *i )->NextThink <= Time )
		{
			( *i )->Think();
		}

		DrawLineBox( ( *i  )->Box );

		i++;
	}
}



CEngine* gEngine;