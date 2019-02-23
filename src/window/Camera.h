#ifndef CAMERA_H
#define CAMERA_H
#include"stdafx.h"
#include"object/Entity.h"

class Camera
{
private:
	View view;
public:
	void move(string direction);
	void reset(int width, int height);
	View& get_view();

	void move_to_last_object(vector<Entity*>& objects);
	Camera();
	~Camera();
};
#endif // CAMERA_H
