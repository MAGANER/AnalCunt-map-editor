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
void Object::set_image(string img)
{
	img_file = img;
	gobject_img.loadFromFile(img_file);
	gobject_img.createMaskFromColor(Color(255, 255, 255));
	gobject_textr.loadFromImage(gobject_img);
	gobject_spr.setTexture(gobject_textr);
}

Object::Object()
{

}

Object::~Object()
{
}
