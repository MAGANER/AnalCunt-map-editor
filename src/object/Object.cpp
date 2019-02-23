#include "Object.h"

float Object::get_x()
{
	sf::Vector2f pos = gobject_spr.getPosition();
	return pos.x;
}
float Object::get_y()
{
	sf::Vector2f pos = gobject_spr.getPosition();
	return pos.y;
}

void Object::set_drawable_state(bool flag)
{
	drawable = flag;
}
bool Object::is_drawable()
{
	return drawable;
}

int Object::get_height()
{
	return gobject_spr.getTextureRect().height;
}
int Object::get_width()
{
	return gobject_spr.getTextureRect().width;
}

void Object::set_texture_rect(IntRect & rect)
{
    gobject_spr.setTextureRect(rect);
}
void Object::set_pos(float x, float y)
{
	gobject_spr.setPosition(x, y);
}
sf::Sprite Object::returnSprite()
{
	return gobject_spr;
}
void Object::set_image(string img)
{
	img_file = img;
	gobject_img.loadFromFile(img_file);
	gobject_img.createMaskFromColor(sf::Color(255, 255, 255));
	gobject_textr.loadFromImage(gobject_img);
	gobject_spr.setTexture(gobject_textr);
}

Object::Object()
{

}

Object::~Object()
{
}
