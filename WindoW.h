#pragma once
#include"stdafx.h"
#include<vector>
#include"Entity.h"
class WindoW
{
private:
	RenderWindow win;
	VideoMode size;
	string title;
public:
	
	bool is_open();
	void check_event();

	void create();
	void close();
	void clear();
	void display();
	void resize(int width, int height);

	void draw(vector<Entity *> & objects);
	void draw(Entity object);

	WindoW(int width, int height, string title);
	~WindoW();
};

