#include "WindoW.h"


Vector2u WindoW::get_size()
{
	return win.getSize();
}

void WindoW::set_view(View & view)
{
	win.setView(view);
}
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
void WindoW::clear(sf::Color color)
{
	win.clear(color);
}
void WindoW::display()
{
	win.display();
}

void WindoW::draw(vector<Entity *> & objects)
{
	for (int i = 0; i < objects.size(); i++)
	{
		win.draw(objects[i]->returnSprite());
	}
}
void WindoW::draw(Entity object)
{
	win.draw(object.returnSprite());
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
void WindoW::check_event(Gui & gui)
{
	Event event;
	while (win.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			win.close();
		}
		gui.handleEvent(event);
	}
}

WindoW::WindoW(int width, int height, string title)
{
	size.height = height;
	size.width = width;
	this->title = title;
	win.create(size, title);
}

WindoW::WindoW(int width, int height, string title, Gui & gui)
{
	size.height = height;
	size.width = width;
	this->title = title;
	gui.setTarget(win);
	win.create(size, title);
}


WindoW::~WindoW()
{
}
