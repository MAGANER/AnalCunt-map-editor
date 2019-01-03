#pragma once
#include"ObjectManipulator.h"
#include"Serialisator.h"

#include"TGUI\TGUI.hpp"
#include"WindoW.h"
using namespace tgui;

class myMenuBar
{
private:
	Serialisator serialisator;

	Theme theme;
	MenuBar::Ptr menu;
public:
	myMenuBar(Gui & gui, vector<Entity*> &objects, ObjectManipulator&  obj_manipulator);
	~myMenuBar();
};

