#include "HotKeyProcessor.h"



HotKeyProcessor::HotKeyProcessor()
{
	action = "-1";
	clicked = false;
	moving_length = 32;

	usabling_object_id = 0;
}
void HotKeyProcessor::is_user_clicking()
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
	bool E = !Keyboard::isKeyPressed(Keyboard::E);
	bool R = !Keyboard::isKeyPressed(Keyboard::R);

	bool user_doesnt_click = escape && z && x && num1 && num2 && num3
		&& up && down && left && right && Q && num4 && E && R;
	if (user_doesnt_click)
	{
		clicked = false;
	}
}
void HotKeyProcessor::get_action()
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
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			action = "up";
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			action = "down";
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			action = "left";
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			action = "right";
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
		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			action = "set rotation";
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
		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			action = "deserialisate";
		}

		clicked = true;
	}
}
void HotKeyProcessor::check_action(WindoW & window,  vector<Entity *> & objects,  Camera & camera)
{
	if (action == "up")
	{
		camera.move(action);
	}
	if (action == "down")
	{
		camera.move(action);
	}
	if (action == "left")
	{
		camera.move(action);
	}
	if (action == "right")
	{
		camera.move(action);
	}
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
		camera.reset(width, height);

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
		if (objects.size() == 0)
		{
			object->set_id(0);
		}
		else {
			cout << "new obj" << endl;
			object->set_id(objects.size());
		}


		usabling_object_id = object->get_id();

		objects.push_back(object);
		
		cout << usabling_object_id << endl;
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
		if (id == 1488)
		{
			// use last added object
			usabling_object_id = objects.size();
		}
	}
	if (action == "move up")
	{
		int object_number = NULL;
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
		int object_number = NULL;
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
		int object_number = NULL;
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
		int object_number = NULL;
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
		int length = 0;
		cout << "enter moving length:";
		cin >> length;
		moving_length = length;
	}
	if (action == "deserialisate")
	{
		serialisator.deserialisate(objects);
	}
	if (action == "set rotation")
	{
		float angle = 0.0f;
		cout << "enter rotation angle:";
		cin >> angle;
		objects[usabling_object_id]->set_rotation(angle);
	}
	action = "-1";
}


HotKeyProcessor::~HotKeyProcessor()
{
}