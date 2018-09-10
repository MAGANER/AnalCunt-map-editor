#include "Manager.h"



Manager::Manager()
{
	action = "-1";
	clicked = false;
	moving_length = 32;
}
void Manager::is_user_clicking()
{
	bool escape = !Keyboard::isKeyPressed(Keyboard::Escape);
	bool z = !Keyboard::isKeyPressed(Keyboard::Z);
	bool x = !Keyboard::isKeyPressed(Keyboard::X);
	bool num1 = !Keyboard::isKeyPressed(Keyboard::Num1);
	bool num2 = !Keyboard::isKeyPressed(Keyboard::Num2);
	bool num3 = !Keyboard::isKeyPressed(Keyboard::Num3);
	bool num4 = !Keyboard::isKeyPressed(Keyboard::Num4);
	bool up = !Keyboard::isKeyPressed(Keyboard::Up);
	bool down = !Keyboard::isKeyPressed(Keyboard::Down);
	bool left = !Keyboard::isKeyPressed(Keyboard::Left);
	bool right = !Keyboard::isKeyPressed(Keyboard::Right);
	bool Q = !Keyboard::isKeyPressed(Keyboard::Q);

	bool user_doesnt_click = escape && z && x && num1 && num2 && num3
		&& up && down && left && right && Q && num4;
	if (user_doesnt_click)
	{
		clicked = false;
	}
}
void Manager::get_action()
{
	if (!clicked)
	{
		// window manipulation
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			action = "close";
		}
		if (Keyboard::isKeyPressed(Keyboard::Z))
		{
			action = "clear";
		}
		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			action = "resize";
		}

		// object manipulation
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			action = "create object";
		}
		if (Keyboard::isKeyPressed(Keyboard::Num2))
		{
			action = "reset object settings";
		}
		if (Keyboard::isKeyPressed(Keyboard::Num3))
		{
			action = "choose object to manipulate";
		}
		if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
			action = "set length";
		}

		// object moving
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			action = "move up";
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			action = "move down";
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			action = "move left";
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			action = "move right";
		}

		//saving project into json file
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			action = "serialise";
		}

		clicked = true;
	}
}
void Manager::check_action(WindoW & window, int & object_counter, vector<Entity *> & objects, int & usabling_object_id)
{
	if (action == "close")
	{
		window.close();
	}
	if (action == "clear")
	{
		window.clear();
	}
	if (action == "resize")
	{
		int width, height;
		cout << "enter width:";
		cin >> width;
		cout << endl;
		
		cout << "enter height:";
		cin >> height;
		window.resize(width, height);

	}
	if (action == "create object")
	{
		Entity * object = new Entity();
		string type;
		string path;

		cout << "enter path to object image:";
		cin >> path;
		cout << "enter object type:";
		cin >> type;

		object->set_image(path);
		object->set_image_path(path);
		object->set_type(type);
		object->set_id(object_counter);
		usabling_object_id = object_counter;

		objects.push_back(object);

		++object_counter;
	}
	if (action == "reset object settings")
	{
		int what_to_do;
		int id;
		cout << "enter object id:";
		cin >> id;
		cout << "1)reset positon /n 2) reset image /n :";
		cin >> what_to_do;
		if (what_to_do == 1)
		{
			int x, y;
			cout << "enter x:";
			cin >> x;
			cout << "enter y:";
			cin >> y;

			for (int i = 0; i < objects.size(); ++i)
			{
				if (objects[i]->get_id() == id)
				{
					objects[i]->set_pos((float)x, (float)y);
				}
			}
		}
		if (what_to_do == 2)
		{
			string img;
			cout << "enter path to new image:";
			cin >> img;
			for (int i = 0; i < objects.size(); ++i)
			{
				if (objects[i]->get_id() == id)
				{
					objects[i]->set_image(img);
				}
			}
		}

	}
	if (action == "choose object to manipulate")
	{
		int id;
		cout << "enter object id which you want to manipulate:";
		cin >> id;
		usabling_object_id = id;
	}
	if (action == "move up")
	{
		int object_number;
		for (int i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->get_id() == usabling_object_id)
			{
				object_number = i;
				break;
			}
		}

		float old_x_pos = objects[object_number]->get_x();
		float old_y_pos = objects[object_number]->get_y();

		objects[object_number]->set_pos(old_x_pos, old_y_pos - moving_length);
	}
	if (action == "move down")
	{
		int object_number;
		for (int i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->get_id() == usabling_object_id)
			{
				object_number = i;
				break;
			}
		}

		float old_x_pos = objects[object_number]->get_x();
		float old_y_pos = objects[object_number]->get_y();

		objects[object_number]->set_pos(old_x_pos, old_y_pos + moving_length);

	}
	if (action == "move left")
	{
		int object_number;
		for (int i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->get_id() == usabling_object_id)
			{
				object_number = i;
				break;
			}
		}

		float old_x_pos = objects[object_number]->get_x();
		float old_y_pos = objects[object_number]->get_y();

		objects[object_number]->set_pos(old_x_pos - moving_length, old_y_pos);
	}
	if (action == "move right")
	{
		int object_number;
		for (int i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->get_id() == usabling_object_id)
			{
				object_number = i;
				break;
			}
		}

		float old_x_pos = objects[object_number]->get_x();
		float old_y_pos = objects[object_number]->get_y();

		objects[object_number]->set_pos(old_x_pos + moving_length, old_y_pos);
	}
	if (action == "serialise")
	{
		serialisator.serialisate(objects);
	}
	if (action == "set length")
	{
		cout << "enter moving length:";
		cin >> moving_length;
	}
	action = "-1";
}


Manager::~Manager()
{
}
