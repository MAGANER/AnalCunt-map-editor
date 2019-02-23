#ifndef MYMENUBAR_H
#define MYMENUBAR_H
#include"stdafx.h"
#include"logic/ObjectManipulator.h"
#include"logic/Serialisator.h"
#include"gui/help_windows/HelpWindowDrawer.h"
#include"window/WindoW.h"


class myMenuBar
{
private:
	Serialisator serialisator;
	Theme theme;
	MenuBar::Ptr menu;

	HelpWindowDrawer drawer;
public:
	myMenuBar(Gui & gui, vector<Entity*> &objects, ObjectManipulator&  obj_manipulator);
	~myMenuBar();
};
#endif // MYMENUBAR_H
