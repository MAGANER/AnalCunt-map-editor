#include "GameObject.h"

float GameObject::get_x()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.x;
}
float GameObject::get_y()
{
	Vector2f pos = gobject_spr.getPosition();
	return pos.y;
}
void GameObject::set_pos(float x, float y)
{
	gobject_spr.setPosition(x, y);
}
Sprite GameObject::returnSprite()
{
	return gobject_spr;
}
GameObject::GameObject()
{

}



GameObject::~GameObject()
{
}
