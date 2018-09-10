#pragma once
#include"Object.h"
#include"json.hpp"

using json = nlohmann::json;


class Entity: public Object
{
private:
	int id; // number of object
	string type;
	json entity;
public:
	json get_data();
	void set_data();
	int get_id();
	string get_type();
	void set_id(int id);
	void set_type(string type);
	

	Entity();
	~Entity();
};

