#include "Manager.h"



Manager::Manager()
{
	action = "-1";
	clicked = false;
}
void Manager::is_user_clicking()
{
	bool escape = !Keyboard::isKeyPressed(Keyboard::Escape);
	
	bool user_doesnt_click = escape;
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

		clicked = true;
	}
}
void Manager::check_action(WindoW & window)
{
	if (action == "close")
	{
		window.close();
	}

	action = "-1";
}

Manager::~Manager()
{
}
