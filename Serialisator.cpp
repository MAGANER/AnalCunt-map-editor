#include "Serialisator.h"



void Serialisator::serialisate(vector<Entity *> & objects)
{
	ofstream file;
	file.open("world.json", ios::app);

	for (int i = 0; i < objects.size(); ++i)
	{
		//int id = objects[i]->get_id();
		//float x = objects[i]->get_x();
		//float y = objects[i]->get_y();
		//string type = objects[i]->get_type();
		objects[i]->set_data();
		json data = objects[i]->get_data();
		file << data;
		
			//world[to_string(id)]["x"] = x;
			//world[to_string(id)]["y"] = y;
			//world[to_string(id)]["type"] = type;

		//world[to_string(id)] = { x, y,type };
			 
			//file << world;
	}
	file.close();
}
Serialisator::Serialisator()
{
}


Serialisator::~Serialisator()
{
}
