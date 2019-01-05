#pragma once
#include"stdafx.h"
#include"WindoW.h"

class AboutWindow
{
private:
	sf::Font font;

	sf::Text name;
	sf::Text creator;
	sf::Text licence;
	sf::Text year;

public:
	void draw(WindoW* & window);
	AboutWindow();
	~AboutWindow();
};

