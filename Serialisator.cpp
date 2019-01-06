#include "Serialisator.h"


void Serialisator::deserialisate(vector<Entity *> & objects)
{

	bool ok = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "load level...",gui);
	SerialisatorWindow* serialisator = new SerialisatorWindow(gui, ok);


	while (window->is_open())
	{
		window->check_event(gui);

		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ok = true;
		}

		String path = serialisator->get_path();
		if (ok)
		{
			string file_path = path.toAnsiString();
			ifstream file;
			Entity * object = new Entity();

			if (file_path != "n")
			{
				file.open(file_path);
				if (file.fail())
				{
					cout << "fuck you";
				}
				file >> world;

				int object_counter = 0;
				while (true)
				{
					if (!world["world"][to_string(object_counter)].empty())
					{
						Entity * object = new Entity();

						cout << "good" << endl;
						int id = object_counter;
						float x = world["world"][to_string(object_counter)].at(0);
						float y = world["world"][to_string(object_counter)].at(1);
						string image = world["world"][to_string(object_counter)].at(2);
						string type = world["world"][to_string(object_counter)].at(3);
						float rotation = world["world"][to_string(object_counter)].at(4);

						object->set_pos(x, y);
						object->set_id(id);
						object->set_image(image);
						object->set_image_path(image);
						object->set_type(type);
						object->set_rotation(rotation);

						objects.push_back(object);
						++object_counter;
					}
					else {
						cout << "fuck";
						break;
					}
				}
			}

			window->close();
			ok = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}
	delete gui;
	delete window;
	delete serialisator;

}
void Serialisator::serialisate(vector<Entity *> & objects)
{
	bool ok = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "save level...", gui);
	SerialisatorWindow* serialisator = new SerialisatorWindow(gui, ok);

	while (window->is_open())
	{
		window->check_event(gui);

		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ok = true;
		}


		String path = serialisator->get_path();
		if (ok)
		{
			string file_path = path.toAnsiString();
			json world;
			ofstream file;

			if (file_path != "n")
			{
				file.open(file_path, ios::app);

				for (int i = 0; i < objects.size(); ++i)
				{
					world["world"][to_string(objects[i]->get_id())] = { objects[i]->get_x(),
						objects[i]->get_y(),
						objects[i]->get_image_path(),
						objects[i]->get_type(),
						objects[i]->get_rotation() };
				}
				file << world;
				file.close();

			}

			window->close();
			ok = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}
	delete gui;
	delete window;
	delete serialisator;

	/*
	string file_path;
	json world;
	ofstream file;

	cout << "enter file path:";
	cin >> file_path;
	if (file_path != "n")
	{
		file.open(file_path, ios::app);

		for (int i = 0; i < objects.size(); ++i)
		{
			world["world"][to_string(objects[i]->get_id())] = { objects[i]->get_x(),
																objects[i]->get_y(),
																objects[i]->get_image_path(),
																objects[i]->get_type(),
																objects[i]->get_rotation() };
		}
		file << world;
		file.close();

	}
	*/
}
Serialisator::Serialisator()
{
}


Serialisator::~Serialisator()
{
}
