#pragma once
#include"Object.h"
#include"json.hpp"

using json = nlohmann::json;


class Entity: public Object
{
protected:
	int id; // number of object
	string type;
	string image_path;
	json entity;
public:
	string get_image_path();
	void set_image_path(string path);
	json get_data();
	void set_data();
	int get_id();
	string get_type();
	void set_id(int id);
	void set_type(string type);
	void set_rotation(float angle);
	float get_rotation();
	

	Entity();
	virtual ~Entity();
};

