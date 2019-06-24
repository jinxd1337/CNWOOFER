#ifndef __MENU_H__
#define __MENU_H__

#include <vector>

#include "text.h"
#include "image.h"

class CLabel
{
public:

	bool Static = false;
	bool Active = true;

	SDL_Rect Box;
	CText* Text;

	CLabel( void ) {};
	~CLabel( void ) {};

	virtual void Pressed( void ) = 0;
	virtual void Update( void ) = 0;

	void SetPos( int x, int y )
	{
		Text->SetPos( x, y );
		Box.x = x;
		Box.y = y;
	}

};

class CSubMenu
{
public:

	CSubMenu( void ) {};
	~CSubMenu( void ) {};

	std::vector<CLabel*> Labels;
	void Update( void );

};

class CMenu
{
public:

	std::map<std::string, CSubMenu*> SubMenus;
	CSubMenu* ActiveMenu;

	CMenu( void );
	~CMenu( void );

	void Update( void );

};

#endif /* __MENU_H__ */