#ifndef HOTKEYWINDOW_H
#define HOTKEYWINDOW_H
#include"stdafx.h"
#include"window/WindoW.h"

class HotKeyWindow
{
private:
	sf::Font font;

	sf::Text serialisate;
	sf::Text deserialisate;
	sf::Text create_obj;
	sf::Text move_obj;
	sf::Text move_camera;

public:
	void draw(WindoW* & window);
	HotKeyWindow();
	~HotKeyWindow();
};
#endif // HOTKEYWINDOW_H
