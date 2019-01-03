#pragma once
#include"stdafx.h"
#include"ObjectManipulator.h"

class ObjectCreatingMenu
{
private:
	Theme theme;

	Label::Ptr lbl_enter_type;
	Label::Ptr lbl_enter_img_path;

	EditBox::Ptr edb_enter_type;
	EditBox::Ptr edb_enter_img_path;

	Button::Ptr create;


public:
	ObjectCreatingMenu(Gui* & gui, bool & able_to_create);

	String get_obj_type();
	String get_img_path();

	~ObjectCreatingMenu();
};

