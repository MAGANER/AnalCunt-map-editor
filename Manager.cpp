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

	bool user_doesnt_click = escape && z && x;
	if (user_doesnt_click)
	{
		clicked = false;
	}
}
void Manager::get_action()
{
	if (!clicked)
	{
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

		clicked = true;
	}
}
void Manager::check_action(WindoW & window)
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
	action = "-1";
}


Manager::~Manager()
{
}
