#pragma once
#include"Object.h"
#include"json.hpp"

using json = nlohmann::json;

class Entity: public Object
{
private:
	json entity;
public:
	void set_data();
	void serialisate_data();

	Entity();
	~Entity();
};

