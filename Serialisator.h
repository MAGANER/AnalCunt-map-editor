#pragma once
#include"json.hpp"
#include"stdafx.h"
#include"Entity.h"
#include <stdlib.h>
#include<string>
#include"WindoW.h"
#include"SerialisatorWindow.h"

using json = nlohmann::json;

class Serialisator
{
private:
	json world;
public:
    void deserialisate(vector<Entity *> & objects);
	void serialisate(vector<Entity *> & objects);
	Serialisator();
	virtual ~Serialisator();
};

