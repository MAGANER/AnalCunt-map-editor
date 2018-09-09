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

	bool user_doesnt_click = escape && z && x && num1;
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

	action = "-1";
}


Manager::~Manager()
{
}
