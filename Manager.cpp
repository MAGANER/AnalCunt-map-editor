#include "Manager.h"



Manager::Manager()
{
	action = "-1";
	clicked = false;
}
void Manager::is_user_clicking()
{
	bool escape = !Keyboard::isKeyPressed(Keyboard::Escape);
	bool z = !Keyboard::isKeyPressed(Keyboard::Z);
	bool x = !Keyboard::isKeyPressed(Keyboard::X);
	bool num1 = !Keyboard::isKeyPressed(Keyboard::Num1);
	bool num2 = !Keyboard::isKeyPressed(Keyboard::Num2);

	bool user_doesnt_click = escape && z && x && num1 && num2;
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

		clicked = true;
	}
}
void Manager::check_action(WindoW & window, int & object_counter, vector<Entity *> & objects)
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
		object->set_type(type);
		object->set_id(object_counter);

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
	action = "-1";
}


Manager::~Manager()
{
}
