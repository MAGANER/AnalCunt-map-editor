#include "Manager.h"



Manager::Manager()
{
}
void Manager::get_action()
{
	cin >> action;
}
void Manager::check_action()
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
	

}

Manager::~Manager()
{
}
