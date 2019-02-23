#include "ObjectParameterWindow.h"

string ObjectParameterWindow::get_id()
{
	return edb_id->getText().toAnsiString();
}
string ObjectParameterWindow::get_img_path()
{
	return edb_image_path->getText().toAnsiString();
}
string ObjectParameterWindow::get_rotation_angle()
{
	return edb_rotation_angle->getText().toAnsiString();
}
string ObjectParameterWindow::get_type()
{
	return edb_type->getText().toAnsiString();
}

void ObjectParameterWindow::set_parameters(vector<Entity *> & objects, int & object_id)
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		if (object_id == objects[i]->get_id())
		{
			string id = to_string(object_id);
			edb_id->setText(id);
	
			string type = to_string(objects[i]->get_type());
			edb_type->setText(type);

			string img_path = to_string(objects[i]->get_image_path());
			edb_image_path->setText(img_path);

			string rotation_angle = to_string(objects[i]->get_rotation());
			edb_rotation_angle->setText(rotation_angle);

			break;
		}
	}
}
ObjectParameterWindow::ObjectParameterWindow(Gui* & gui, bool & able_to_change)
{
	theme.load("themes/Black.txt");

	lbl_id = Label::create();
	lbl_id->setRenderer(theme.getRenderer("Label"));
	lbl_id->setText("id:");
	lbl_id->setPosition(40, 40);
	lbl_id->setTextSize(48);
	gui->add(lbl_id);

	edb_id = EditBox::create();
	edb_id->setRenderer(theme.getRenderer("EditBox"));
	edb_id->setPosition(40, 100);
	edb_id->setSize(800, 100);
	edb_id->setTextSize(48);
	gui->add(edb_id);

	lbl_type = Label::create();
	lbl_type->setRenderer(theme.getRenderer("Label"));
	lbl_type->setText("type:");
	lbl_type->setPosition(40, 250);
	lbl_type->setTextSize(48);
	gui->add(lbl_type);

	edb_type = EditBox::create();
	edb_type->setRenderer(theme.getRenderer("EditBox"));
	edb_type->setPosition(40, 310);
	edb_type->setSize(800, 100);
	edb_type->setTextSize(48);
	gui->add(edb_type);


	lbl_rotation_angle = Label::create();
	lbl_rotation_angle->setRenderer(theme.getRenderer("Label"));
	lbl_rotation_angle->setText("rotation angle:");
	lbl_rotation_angle->setPosition(40, 410);
	lbl_rotation_angle->setTextSize(48);
	gui->add(lbl_rotation_angle);

	edb_rotation_angle = EditBox::create();
	edb_rotation_angle->setRenderer(theme.getRenderer("EditBox"));
	edb_rotation_angle->setPosition(40, 490);
	edb_rotation_angle->setSize(800, 100);
	edb_rotation_angle->setTextSize(48);
	gui->add(edb_rotation_angle);

	lbl_image_path = Label::create();
	lbl_image_path->setRenderer(theme.getRenderer("Label"));
	lbl_image_path->setText("path to image:");
	lbl_image_path->setPosition(40, 590);
	lbl_image_path->setTextSize(48);
	gui->add(lbl_image_path);

	edb_image_path = EditBox::create();
	edb_image_path->setRenderer(theme.getRenderer("EditBox"));
	edb_image_path->setPosition(40, 680);
	edb_image_path->setSize(800, 100);
	edb_image_path->setTextSize(48);
	gui->add(edb_image_path);

	change = Button::create();
	change->setRenderer(theme.getRenderer("Button"));
	change->setPosition(250, 820);
	change->setText("change!");
	change->setTextSize(48);
	change->setSize(300, 150);
	change->connect("pressed", [&]() {able_to_change = true; });
	gui->add(change);

}


ObjectParameterWindow::~ObjectParameterWindow()
{
}
