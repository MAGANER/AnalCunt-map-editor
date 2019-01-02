#pragma once
#include"stdafx.h"
#include<vector>
#include"Entity.h"
#include"TGUI\TGUI.hpp"

using namespace tgui;

class WindoW
{
private:
	RenderWindow win;
	VideoMode size;
	string title;
public:
	Vector2u get_size();


	bool is_open();
	void check_event();
	void check_event(Gui & gui);

	void create();
	void close();
	void clear();
	void display();
	void resize(int width, int height);
	void set_view(View & view);

	void draw(vector<Entity *> & objects);
	void draw(Entity object);

	WindoW(int width, int height, string title);
	WindoW(int width, int height, string title, Gui & gui);
	~WindoW();
};

