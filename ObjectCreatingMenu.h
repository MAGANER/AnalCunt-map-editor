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

	String last_object_type, last_object_image_path;
public:
	ObjectCreatingMenu(Gui* & gui, bool & able_to_create);

	String get_obj_type();
	String get_img_path();

	void set_cash(String type, String image_path);
	void use_cash();

	void save_cash();
	void load_cash();

	~ObjectCreatingMenu();
};

