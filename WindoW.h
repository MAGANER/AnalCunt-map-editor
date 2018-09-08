#pragma once
#include"stdafx.h"
#include<vector>
class WindoW
{
private:
	RenderWindow win;
	VideoMode size;
	string title;
	Event event;
public:
	bool is_open();
	void check_event();

	void create();
	void close();

	WindoW(int width, int height, string title);
	~WindoW();
};

