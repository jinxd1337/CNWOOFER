#include "menu.h"
#include "engine.h"
#include "util.h"

#include "mainmenu.h"

CMenu::CMenu( void )
{
	SubMenus[ "mainmenu" ] = new CMainMenu;

	ActiveMenu = SubMenus[ "mainmenu" ];
}

CMenu::~CMenu( void )
{
	std::map<std::string, CSubMenu*>::iterator i = SubMenus.begin();

	while( i != SubMenus.end() )
	{
		delete i->second;

		i++;
	}
}

void CMenu::Update( void )
{
	std::vector<CLabel*>::iterator i = ActiveMenu->Labels.begin();
	int x, y;

	while( i != ActiveMenu->Labels.end() )
	{
		( *i )->Update();

		if( ( *i )->Active )
			( *i )->Text->Draw();

//		gEngine->DrawLineBox( ( *i )->Box );

		if( gEngine->GetKeyState( SDL_BUTTON_LEFT ) == KEY_DOWN )
		{
			gEngine->GetMousePos( &x, &y );

			if( ContainsPoint( ( *i )->Box, x, y ) )
				( *i )->Pressed();
		}

		i++;
	}
}