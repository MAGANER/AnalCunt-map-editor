#ifndef OBJECTCREATINGMENU_H
#define OBJECTCREATINGMENU_H
#include"stdafx.h"
#include"logic/ObjectManipulator.h"

class ObjectCreatingMenu
{
private:
	Theme theme;

	Label::Ptr lbl_enter_drawble_state;
	Label::Ptr lbl_enter_type;
	Label::Ptr lbl_enter_img_path;

	EditBox::Ptr edb_enter_type;
	EditBox::Ptr edb_enter_img_path;
	EditBox::Ptr edb_enter_drawable_state;



	Button::Ptr create;

	String last_object_type, last_object_image_path, last_object_drawable_state;
public:
	ObjectCreatingMenu(Gui* & gui, bool & able_to_create);

	String get_obj_type();
	String get_img_path();
	String get_drawble_state();

	void set_cash(String type, String image_path, String drawable_state);
	void use_cash();

	void save_cash();
	void load_cash();

	~ObjectCreatingMenu();
};
#endif // OBJECTCREATINGMENU_H
