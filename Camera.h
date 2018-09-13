#pragma once
#include"stdafx.h"
class Camera
{
private:
	View view;
public:

	void reset(int width, int height);
	View get_view();
	Camera();
	~Camera();
};

