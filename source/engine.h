#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <map>
#include <vector>

#include "config.h"
#include "logger.h"
#include "entity.h"
#include "text.h"


enum
{
	STATE_RUN = 0,
	STATE_MENU,
	STATE_NEWGAME,
	STATE_GAME,
	STATE_GAMEMENU,
	STATE_QUIT
};

enum
{
	KEY_UP = 0,
	KEY_DOWN,
	KEY_HELD
};

class CEngine
{
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	CConfig* Config;
	CLogger* Elog;

	std::map<std::string, TTF_Font*> Fonts;
	std::map<std::string, SDL_Texture*> Images;
	std::map<int, int> KeyState;

	std::vector<CEntity*> Entities;

	int State;

	int Time, Delta, LastFrame;

	int EntCount;

	int FPS, FPSCounter, FPSTime;

	CText* FPSText;
	bool ShowFPS;

public:

	CEngine(void);
	~CEngine(void);

	int GetTime( void ) { return Time; }
	int GetDelta( void ) { return Delta;  }
	int GetLastFrame( void ) { return LastFrame; }

	int GetState( void ) { return State; }
	void SetState( int s ) { State = s; }

	bool Initialize(void);
	bool Shutdown( void );

	void PollEvents( void );
	int GetKeyState( int k );
	void GetMousePos( int* x, int* y );

	void PreFrame( void );
	void PostFrame( void );

	SDL_Texture* GetImage( std::string filename );
	void DrawImage( SDL_Texture* texture, SDL_Rect pos );
	TTF_Font* GetFont( std::string filename, int size );
	SDL_Texture* RenderText( std::string text, TTF_Font* font, SDL_Color color );
	void DrawText( SDL_Texture* text, SDL_Rect rect );

	void AddEntity( CEntity* ent );
	void UpdateEntities( void );

	// debug render shit

	void DrawLineBox( SDL_Rect r );
	
};

extern CEngine* gEngine;

#endif /* __ENGINE_H__ */