#include "WindoW.h"

void WindoW::close()
{
	win.close();
}
void WindoW::create()
{
	win.create(size, title);
}
bool WindoW::is_open()
{
	if (win.isOpen())
	{
		return 1;
	}
	else {
		return 0;
	}
}
void WindoW::check_event()
{
	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{

			win.close();
		}
	}
}
WindoW::WindoW(int width, int height, string title)
{
	size.height = height;
	size.width = width;
	this->title = title;
}


WindoW::~WindoW()
{
}
