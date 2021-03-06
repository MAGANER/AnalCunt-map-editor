// this is common class of every game object like player, enemy etc
#ifndef OBJECT_H
#define OBJECT_H
#include"stdafx.h"

class Object
{
protected:
    float x_pos, y_pos;
	string img_file;

	Image gobject_img;
	sf::Texture gobject_textr;
	sf::Sprite gobject_spr;

	bool drawable;

	int width, height;

	IntRect physical_body;
public:
	float get_x();
	float get_y();

    IntRect get_texture_rect();
    IntRect get_physical_body();

	void set_drawable_state(bool flag);
	bool is_drawable();

	int get_width();
	int get_height();

    void set_width(int width);
    void set_height(int height);

	void set_texture_rect(IntRect & rect);
	void set_physical_body(IntRect& rect);
	void set_image(string img);
	void set_pos(float x, float y);
	sf::Sprite returnSprite();
	Object();
	virtual ~Object();
};
#endif // OBJECT_H
