#ifndef SERIALISATOR_H
#define SERIALISATOR_H
#include <stdlib.h>
#include<string>
#include"stdafx.h"
#include"json/json.hpp"
#include"object/Entity.h"
#include"window/WindoW.h"
#include"gui/file_windows/SerialisatorWindow.h"

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
#endif // SERIALISATOR_H
