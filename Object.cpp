#include "Object.h"

float Object::get_x()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.x;
}
float Object::get_y()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.y;
}
void Object::set_pos(float x, float y)
{
	gobject_spr.setPosition(x, y);
}
Sprite Object::returnSprite()
{
	return gobject_spr;
}
Object::Object()
{

}

Object::~Object()
{
}
