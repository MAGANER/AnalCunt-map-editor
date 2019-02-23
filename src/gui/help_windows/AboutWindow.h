#ifndef ABOUTWINDOW_H
#define ABOUTHWINDOW_H
#include"stdafx.h"
#include"window/WindoW.h"

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
#endif // ABOUTWINDOW_H
