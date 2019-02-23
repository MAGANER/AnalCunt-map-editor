#include "AboutWindow.h"


void AboutWindow::draw(WindoW* & window)
{
	window->draw(name);
	window->draw(creator);
	window->draw(licence);
	window->draw(year);
}
AboutWindow::AboutWindow()
{
	font.loadFromFile("themes/font.ttf");

	name.setString("programm name: Anal Cunt Map Editor");
	name.setCharacterSize(12);
	name.setPosition(10, 40);
	name.setFont(font);

	creator.setString("creator:Yan 'Maganer' Lomakin-Gorbatenko");
	creator.setCharacterSize(12);
	creator.setPosition(10, 80);
	creator.setFont(font);

	licence.setString("licence: Open Source");
	licence.setCharacterSize(12);
	licence.setPosition(10, 120);
	licence.setFont(font);

	year.setString("creation year:2019");
	year.setCharacterSize(12);
	year.setPosition(10, 160);
	year.setFont(font);
}


AboutWindow::~AboutWindow()
{

}
