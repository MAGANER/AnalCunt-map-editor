// this is common class of every game object like player, enemy etc
#pragma once
#include"stdafx.h"

class GameObject
{
protected:
    float x_pos, y_pos;
	string img_file;

	Image gobject_img;
	Texture gobject_textr;
	Sprite gobject_spr;
public:
	float get_x();
	float get_y();
	void set_pos(float x, float y);
	Sprite returnSprite();
	GameObject();
	virtual ~GameObject();
};

