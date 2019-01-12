#include "Camera.h"

void Camera::move(string direction)
{
	if (direction == "up")
	{
		view.move(0.0f, -1.0f);
	}
	if (direction == "left")
	{
		view.move(-1.0f, 0.0f);
	}
	if (direction == "right")
	{
		view.move(1.0f, 0.0f);
	}
	if (direction == "down")
	{
		view.move(0.0f, 1.0f);
	}
}
void Camera::reset(int width, int height)
{
	view.reset(sf::FloatRect(0, 0, width, height));
}
View Camera::get_view()
{
	return view;
}
Camera::Camera()
{

}
void Camera::move_to_last_object(vector<Entity*>& objects)
{
	float x = objects[objects.size()-1]->get_x();
	float y = objects[objects.size()-1]->get_y();

	view.setCenter(x, y);
}

Camera::~Camera()
{
}
