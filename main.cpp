#include"stdafx.h"
#include<conio.h>
#include"Manager.h"
#include"WindoW.h"
#include"Entity.h"
#include<vector>
#include"Camera.h"

int main()
{
	int usabling_object_id;
	int object_counter = 0;
	WindoW window(720, 640, "AnalCunt map editor");
	Camera camera;
	Manager manager;
	vector<Entity *> objects;


	    camera.reset(720, 640);
		while (window.is_open())
		{
			window.check_event();
	        
			manager.get_action();
			manager.is_user_clicking();
			manager.check_action(window, object_counter, objects, usabling_object_id, camera);
            
			
			window.set_view(camera.get_view());
			window.clear();
			window.draw(objects);
			window.display();

		}
	

	
	return 0;
}
