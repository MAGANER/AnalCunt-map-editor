#pragma once
#include"stdafx.h"
#include<vector>
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

	void draw();

	WindoW(int width, int height, string title);
	~WindoW();
};

