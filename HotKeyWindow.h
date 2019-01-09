#pragma once
#include"stdafx.h"
#include"WindoW.h"

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

