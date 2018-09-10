#pragma once
#include"json.hpp"
#include"stdafx.h"
#include"Entity.h"

using json = nlohmann::json;

class Serialisator
{
private:
	json world;
public:
	void serialisate(vector<Entity *> & objects);
	Serialisator();
	~Serialisator();
};

