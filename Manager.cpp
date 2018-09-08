#include "Manager.h"



Manager::Manager()
{

}
void Manager::get_action()
{
	cout << ">>";
	cin >> action;
}
void Manager::check_action(WindoW & window)
{
	// object manipulating commands
	if (action == "add_object" || action == "ao")
	{

	}
	if (action == "delete_object" || action == "do")
	{

	}
	if (action == "delete_all" || action == "da")
	{

	}
	if (action == "save_all" || action == "sa")
	{

	}

	// programm manipulating commands
	if (action == "close_window" || action == "cw")
	{

	}
	if (action == "create_window" || action == "start_window" || action == "sw")
	{
		window.create();
	}
	

}

Manager::~Manager()
{
}
