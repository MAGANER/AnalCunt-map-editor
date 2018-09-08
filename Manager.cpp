#include "Manager.h"



Manager::Manager()
{
	action = "-1";
}
void Manager::get_action()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		action = "close";
	}
}
void Manager::check_action(WindoW & window)
{
	if (action == "close")
	{
		window.close();
	}
}

Manager::~Manager()
{
}
