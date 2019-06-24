#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "menu.h"

class CTitle : public CLabel
{
public:

	CTitle( void )
	{
		Text = new CText( "TestGAME", "data/font/framd.ttf", 72, 20, 230 );		
	}

	~CTitle( void )
	{
		delete Text;
	}

	void Pressed( void )
	{
	}

	void Update( void )
	{
	}

};

class CContinue : public CLabel
{
public:

	CContinue( void )
	{
		Text = new CText( "Continue", "data/font/verdana.ttf", 24, 60, 300 );
		Box = { 60, 300, 140, 30 };
		Active = false;
	}

	~CContinue( void )
	{
		delete Text;
	}

	void Pressed( void )
	{
		if( gEngine->GetState() == STATE_GAMEMENU )
			gEngine->SetState( STATE_GAME );
	}

	void Update( void )
	{
		if( gEngine->GetState() == STATE_GAMEMENU )
			Active = true;
		else
			Active = false;
	}
};

class CNewGame : public CLabel
{
public:

	CNewGame( void )
	{
		Text = new CText( "New Game", "data/font/verdana.ttf", 24, 60, 330 );
		Box = { 60, 330, 140, 30 };
	}

	~CNewGame( void )
	{
		delete Text;
	}

	void Pressed( void )
	{
		gEngine->SetState( STATE_NEWGAME );
	}

	void Update( void )
	{
	}
};

class COptions : public CLabel
{
public:

	COptions( void )
	{
		Text = new CText( "Options", "data/font/verdana.ttf", 24, 60, 360 );
		Box = { 60, 360, 100, 30 };
	}

	~COptions( void )
	{
		delete Text;
	}

	void Pressed( void )
	{
		Text->SetColor( rand() % 255, rand() % 255, rand() % 255, 255 );
	}

	void Update( void )
	{
	}
};

class CExit : public CLabel
{
public:

	CExit( void )
	{
		Text = new CText( "Exit", "data/font/verdana.ttf", 24, 60, 390 );
		Box = { 60, 390, 50, 30 };
	}

	~CExit( void )
	{
		delete Text;
	}

	void Pressed( void )
	{
		gEngine->SetState( STATE_QUIT );
	}

	void Update( void )
	{
	}
};

class CMainMenu : public CSubMenu
{
public:

	CMainMenu( void )
	{
		Labels.push_back( new CTitle );
		Labels.push_back( new CContinue );
		Labels.push_back( new CNewGame );
		Labels.push_back( new COptions );
		Labels.push_back( new CExit );
	}

	~CMainMenu( void )
	{
		std::vector<CLabel*>::iterator i = Labels.begin();

		while( i != Labels.end() )
		{
			delete ( *i );
			Labels.erase( i );

			i++;
		}
	}
};


#endif /* __MAINMENU_H__ */