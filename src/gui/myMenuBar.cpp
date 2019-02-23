#include "myMenuBar.h"



myMenuBar::myMenuBar(Gui & gui, vector<Entity*> &objects, ObjectManipulator&  obj_manipulator)
{
	theme.load("themes/Black.txt");

	menu = MenuBar::create();
	menu->setRenderer(theme.getRenderer("MenuBar"));
	menu->setSize(1000.0f, 50.0f);
	menu->setTextSize(24);

	menu->addMenu("File");

	menu->addMenuItem("Save");
	menu->connectMenuItem("File", "Save", &Serialisator::serialisate, &serialisator,ref(objects));

	menu->addMenuItem("Load");
	menu->connectMenuItem("File", "Load", &Serialisator::deserialisate, &serialisator, ref(objects));

	menu->addMenu("Objects");

	menu->addMenuItem("Create");
	menu->connectMenuItem("Objects", "Create", &ObjectManipulator::create_obj, &obj_manipulator, ref(objects));

	menu->addMenuItem("Change moving length");
	menu->connectMenuItem("Objects", "Change moving length", &ObjectManipulator::change_moving_length, &obj_manipulator);

	menu->addMenu("Help");

	menu->addMenuItem("About");
	menu->connectMenuItem("Help", "About",&HelpWindowDrawer::show_about_window,&drawer);

	menu->addMenuItem("Hot keys");
	menu->connectMenuItem("Help", "Hot keys", &HelpWindowDrawer::show_hot_key_window, &drawer);

	gui.add(menu);
}


myMenuBar::~myMenuBar()
{
}
