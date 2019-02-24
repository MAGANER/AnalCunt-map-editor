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
	height = gobject_spr.getTextureRect().height;
	return height;
}
int Object::get_width()
{
	width =  gobject_spr.getTextureRect().width;
	return width;
}

IntRect& Object::get_texture_rect()
{
    gobject_spr.getTextureRect();
}

void Object::set_width(int width)
{
    this->width = width;
}
void Object::set_height(int height)
{
    this->height = height;
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
    height = gobject_spr.getTextureRect().height;
    width  = gobject_spr.getTextureRect().width;
}

Object::~Object()
{
}
