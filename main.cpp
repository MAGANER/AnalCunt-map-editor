#include"stdafx.h"
#include<conio.h>
#include"Manager.h"
#include"WindoW.h"
#include"Entity.h"
#include<vector>

int main()
{
	int usabling_object_id;
	int object_counter = 0;
	WindoW window(400, 600, "AnalCunt map editor");
	Manager manager;
	vector<Entity *> objects;


		while (window.is_open())
		{
			window.check_event();
	        
			manager.get_action();
			manager.is_user_clicking();
			manager.check_action(window, object_counter, objects, usabling_object_id);
            
			
			window.draw(objects);

		}
	

	
	return 0;
}
