#include"stdafx.h"
#include<conio.h>
#include"Manager.h"
#include"WindoW.h"
#include"Entity.h"
#include<vector>
#include"Camera.h"
#include"TGUI\TGUI.hpp"

using namespace tgui;

int main()
{
	Gui gui;
	WindoW window(720, 640, "AnalCunt map editor",gui);
	Camera camera;
	Manager manager;
	vector<Entity *> objects;


	    camera.reset(720, 640);
		while (window.is_open())
		{
			window.check_event(gui);
	        
			manager.get_action();
			manager.is_user_clicking();
			manager.check_action(window,  objects,  camera);
            
			
			window.set_view(camera.get_view());
			window.clear();
			gui.draw();
			window.draw(objects);
			window.display();

		}
	

	
	return 0;
}
