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
	int get_id();
	void set_id(int id);
	void set_type(string type);
	void set_data();
	void serialisate_data();

	Entity();
	~Entity();
};

