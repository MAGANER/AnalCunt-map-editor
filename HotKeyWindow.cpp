#include "HotKeyWindow.h"


void HotKeyWindow::draw(WindoW* & window)
{
	window->draw(serialisate);
	window->draw(deserialisate);
	window->draw(create_obj);
	window->draw(change_obj);
	window->draw(move_camera);
	window->draw(move_obj);
}
HotKeyWindow::HotKeyWindow()
{
	font.loadFromFile("themes/font.ttf");

	serialisate.setString("press Q to serialisate");
	serialisate.setCharacterSize(12);
	serialisate.setPosition(10, 40);
	serialisate.setFont(font);

	deserialisate.setString("press E to deserialisate");
	deserialisate.setCharacterSize(12);
	deserialisate.setPosition(10, 80);
	deserialisate.setFont(font);

	create_obj.setString("press 1 to create object");
	create_obj.setCharacterSize(12);
	create_obj.setPosition(10, 120);
	create_obj.setFont(font);

	change_obj.setString("press left mouse button to change object");
	change_obj.setCharacterSize(12);
	change_obj.setPosition(10, 160);
	change_obj.setFont(font);

	move_obj.setString("press UP, DOWN, LEFT,RIGHT to move object");
	move_obj.setCharacterSize(12);
	move_obj.setPosition(10, 200);
	move_obj.setFont(font);

	move_camera.setString("press W, S, A,D to move object");
	move_camera.setCharacterSize(12);
	move_camera.setPosition(10, 240);
	move_camera.setFont(font);
}


HotKeyWindow::~HotKeyWindow()
{
}
