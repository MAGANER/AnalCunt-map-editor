#include"stdafx.h"
#include<conio.h>
#include"Manager.h"
#include"WindoW.h"

int main()
{
	WindoW window(400, 600, "AnalCunt map editor");
	Manager manager;
	

		while (window.is_open())
		{
			window.check_event();
	        
			manager.get_action();
			manager.check_action(window);
		}

	
	_getch();
	return 0;
}
