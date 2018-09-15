#pragma once
#include"stdafx.h"
class Camera
{
private:
	View view;
public:
	void move(string direction);
	void reset(int width, int height);
	View get_view();
	Camera();
	~Camera();
};

