#include "WindoW.h"


void WindoW::resize(int width, int height)
{
	Vector2u win_size;
	win_size.x = width;
	win_size.y = height;
	win.setSize(win_size);
}
void WindoW::clear()
{
	win.clear();
}
void WindoW::display()
{
	win.display();
}
void WindoW::draw()
{
	//draw nothing
	win.clear();

	win.display();
}
void WindoW::close()
{
	win.close();
}
void WindoW::create()
{
	win.setActive(1);
	win.setVisible(1);
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
	Event event;
	while (win.pollEvent(event))
	{
		if (event.type == Event::Closed)
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
	win.create(size, title);
}


WindoW::~WindoW()
{
}
