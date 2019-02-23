#include<vector>
#include"stdafx.h"
#include"logic/HotKeyProcessor.h"
#include"logic/ObjectManipulator.h"
#include"window/WindoW.h"
#include"window/Camera.h"
#include"object/Entity.h"
#include"gui/myMenuBar.h"

int main()
{
	ObjectManipulator obj_manipulator;

	vector<Entity *> objects;

	Gui gui;
	WindoW window(720, 640, "AnalCunt map editor",gui);

	myMenuBar menuBar(gui,objects, obj_manipulator);
	Camera camera;
	HotKeyProcessor manager;



	    camera.reset(720, 640);
		while (window.is_open())
		{
			window.check_event(gui);

			manager.get_action();
			manager.is_user_clicking();
			manager.check_action(window,  objects,  camera, obj_manipulator);


			window.set_view(camera.get_view());
			window.clear(sf::Color(74, 72, 75));
			window.draw(objects);
			gui.draw();
			window.display();

		}

	return 0;
}
