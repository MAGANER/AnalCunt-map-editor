#ifndef WINDOW_H
#define WINDOW_H
#include<vector>
#include"stdafx.h"
#include"object/Entity.h"

class WindoW
{
private:
	RenderWindow* win;
	VideoMode size;
	string title;
public:
	Vector2u get_size();
	sf::RenderWindow* get_win();

	bool is_open();
	void check_event();
	void check_event(Gui & gui);
	void check_event(Gui* & gui);

	void create();
	void close();

	void clear();
	void clear(sf::Color color);

	void display();
	void resize(int width, int height);
	void set_view(View & view);

	void draw(vector<Entity *> & objects);
	void draw(Entity* object);
	void draw(Entity object);
	void draw(sf::Text text);
	void draw(RectangleShape  rect);

	WindoW(int width, int height, string title);
	WindoW(int width, int height, string title, Gui & gui);
	WindoW(int width, int height, string title, Gui* & gui);
	~WindoW();
};
#endif // WINDOW_H
