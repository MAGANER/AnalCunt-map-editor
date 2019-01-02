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


	gui.add(menu);
}


myMenuBar::~myMenuBar()
{
}
