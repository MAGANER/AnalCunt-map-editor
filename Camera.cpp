#include "Camera.h"


void Camera::reset(int width, int height)
{
	view.reset(FloatRect(0, 0, width, height));
}
View Camera::get_view()
{
	return view;
}
Camera::Camera()
{

}


Camera::~Camera()
{
}
