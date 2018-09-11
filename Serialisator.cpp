#include "Serialisator.h"



void Serialisator::deserialisate(vector<Entity *> & objects)
{
	ifstream file;
	Entity * object = new Entity();

	string _file_lvl;
	cout << "enter file with level path:";
	cin >> _file_lvl;

	file.open(_file_lvl);
	file >> world;


	int object_counter = 0;
	while (true)
	{
		if (!world[to_string(object_counter)].is_null())
		{
			float x =  world[to_string(object_counter)]["x"];
			float y =  world[to_string(object_counter)]["y"];
			int id = object_counter;
			string image_path = world[to_string(object_counter)]["image_path"];
			string type = world[to_string(object_counter)]["type"];

			object->set_id(id);
			object->set_pos(x, y);
			object->set_image_path(image_path);
			object->set_type(type);

			objects.push_back(object);
			++object_counter;
		}
		else {
			break;
			cout << "brea";
		}
	}
}
void Serialisator::serialisate(vector<Entity *> & objects)
{
	json world;
	ofstream file;
	file.open("world.json", ios::app);

	for (int i = 0; i < objects.size(); ++i)
	{
		//int id = objects[i]->get_id();
		//float x = objects[i]->get_x();
		//float y = objects[i]->get_y();
		//string type = objects[i]->get_type();
		//objects[i]->set_data();
		//json data = objects[i]->get_data();
		//file << data;
		world["world"][to_string(objects[i]->get_id())]["type"] = objects[i]->get_type();
		world["world"][to_string(objects[i]->get_id())]["x"] = objects[i]->get_x();
		world["world"][to_string(objects[i]->get_id())]["y"] = objects[i]->get_y();
		world["world"][to_string(objects[i]->get_id())]["image_path"] = objects[i]->get_image_path();

			//world[to_string(id)]["x"] = x;
			//world[to_string(id)]["y"] = y;
			//world[to_string(id)]["type"] = type;

		//world[to_string(id)] = { x, y,type };
			 
			//file << world;
	}
	file << world;
	file.close();
}
Serialisator::Serialisator()
{
}


Serialisator::~Serialisator()
{
}
