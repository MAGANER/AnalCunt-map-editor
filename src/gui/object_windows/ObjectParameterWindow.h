#ifndef OBJECTPARAMETERWINDOW_H
#define OBJECTPARAMETERWINDOW_H
#include"stdafx.h"
#include"object/Entity.h"

class ObjectParameterWindow
{
private:

	Theme theme;

	Label::Ptr lbl_id;
	EditBox::Ptr edb_id;

	Label::Ptr lbl_type;
	EditBox::Ptr edb_type;

	Label::Ptr lbl_x_pos;
	EditBox::Ptr edb_x_pos;

	Label::Ptr lbl_y_pos;
	EditBox::Ptr edb_y_pos;

	Label::Ptr lbl_rotation_angle;
	EditBox::Ptr edb_rotation_angle;

	Label::Ptr lbl_image_path;
	EditBox::Ptr edb_image_path;

	Button::Ptr change;

public:
	void set_parameters(vector<Entity*> & objects, int & objects_id);

	string get_id();
	string get_type();
	string get_rotation_angle();
	string get_img_path();

	ObjectParameterWindow(Gui* & gui, bool & able_to_change);
	~ObjectParameterWindow();
};
#endif // OBJECTPARAMETERWINDOW_H
