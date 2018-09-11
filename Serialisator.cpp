#include "Serialisator.h"



void Serialisator::deserialisate(vector<Entity *> & objects)
{
	ifstream file;
	Entity * object = new Entity();

	
	file.open("world.json");
	file >> world;

	//atoi(S.c_str());
	int object_counter = 0;
	//cout << world["world"][to_string(object_counter)];
	/*while (true)
	{
		if (world["world"][to_string(object_counter)])
		{
			float x = world["world"][to_string(object_counter)]["x"];
			float y = world["world"][to_string(object_counter)]["y"];
			
			//float x =  world[to_string(object_counter)]["x"];
			//float y =  world[to_string(object_counter)]["y"];
			int id = object_counter;
			string image_path = world["world"][to_string(object_counter)]["image_path"];
			string type = world["world"][to_string(object_counter)]["type"];
			//string image_path = world[to_string(object_counter)]["image_path"];
			//string type = world[to_string(object_counter)]["type"];
			cout << x<<endl;
			cout << y << endl;
			cout << image_path;
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
	} */ 

	while (true)
	{
		if (!world["world"][to_string(object_counter)].empty())
		{
			Entity * object = new Entity();

			cout << "good"<<endl;
			int id = object_counter;
			float x = world["world"][to_string(object_counter)].at(0);
			float y = world["world"][to_string(object_counter)].at(1);
			string image = world["world"][to_string(object_counter)].at(2);


			object->set_pos(x, y);
			object->set_id(id);
			object->set_image(image);
			object->set_image_path(image);
			//objects[object_counter]->set_id(id);
			//objects[object_counter]->set_pos(x, y);
			//objects[object_counter]->set_image(image);
			//objects[object_counter]->set_image_path(image);

			objects.push_back(object);
			++object_counter;
		}
		else {
			cout << "fuck";
			break;
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

		//world["world"][to_string(objects[i]->get_id())]["type"] = objects[i]->get_type();
		//world["world"][to_string(objects[i]->get_id())]["x"] = objects[i]->get_x();
		//world["world"][to_string(objects[i]->get_id())]["y"] = objects[i]->get_y();
		//world["world"][to_string(objects[i]->get_id())]["image_path"] = objects[i]->get_image_path();
		//world["world"][to_string(objects[i]->get_id())]["id"] = objects[i]->get_id();
		world["world"][to_string(objects[i]->get_id())] = { objects[i]->get_x(),objects[i]->get_y(),objects[i]->get_image_path() };


			//world[to_string(id)]["x"] = x;
			//world[to_string(id)]["y"] = y;
			//world[to_string(id)]["type"] = type;

		//world[to_string(id)] = { x, y,type };
			 
			//file << world
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
