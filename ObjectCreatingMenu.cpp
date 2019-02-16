#include "ObjectCreatingMenu.h"


void ObjectCreatingMenu::set_cash(String type,String image_path,String drawable_state)
{
	last_object_type = type;
	last_object_image_path = image_path; 
	last_object_drawable_state = drawable_state;
}
void ObjectCreatingMenu::use_cash()
{
	edb_enter_type->setText(last_object_type);
	edb_enter_img_path->setText(last_object_image_path);
	edb_enter_drawable_state->setText(last_object_drawable_state);
}

void ObjectCreatingMenu::save_cash()
{
	ofstream file;
	file.open("data/cash.txt");
	file.clear();
	if (!file)
	{
		cout << "wtf" << endl;
	}

	file << last_object_type.toAnsiString();
	file << endl;
	file << last_object_image_path.toAnsiString();
	file << endl;
	file << last_object_drawable_state.toAnsiString();
	file.close();
}
void ObjectCreatingMenu::load_cash()
{
	ifstream file;
	file.open("data/cash.txt");
	if (!file)
	{
		cout << "wtf" << endl;
	}

	string type, img_path, drawable_state;
	file >> type;
	file >> img_path;
	file >> drawable_state;
	file.close();

	last_object_type = type;
	last_object_image_path = img_path;
	last_object_drawable_state = drawable_state;
	cout << last_object_image_path.toAnsiString() << endl;
	cout << last_object_type.toAnsiString() << endl;
}


String ObjectCreatingMenu::get_img_path()
{
	return edb_enter_img_path->getText();
}
String ObjectCreatingMenu::get_obj_type()
{
	return edb_enter_type->getText();
}
String ObjectCreatingMenu::get_drawble_state()
{
	return edb_enter_drawable_state->getText();
}

ObjectCreatingMenu::ObjectCreatingMenu(Gui* & gui, bool & able_to_create)
{
	theme.load("themes/Black.txt");

	lbl_enter_type = Label::create();
	lbl_enter_type->setRenderer(theme.getRenderer("Label"));
	lbl_enter_type->setText("enter object type:");
	lbl_enter_type->setPosition(40, 40);
	lbl_enter_type->setTextSize(36);
	gui->add(lbl_enter_type);

	edb_enter_type = EditBox::create();
	edb_enter_type->setRenderer(theme.getRenderer("EditBox"));
	edb_enter_type->setPosition(40, 90);
	edb_enter_type->setSize(800, 90);
	edb_enter_type->setTextSize(36);
	gui->add(edb_enter_type);


	lbl_enter_img_path = Label::create();
	lbl_enter_img_path->setRenderer(theme.getRenderer("Label"));
	lbl_enter_img_path->setText("enter image path:");
	lbl_enter_img_path->setPosition(40, 200);
	lbl_enter_img_path->setTextSize(36);
	gui->add(lbl_enter_img_path);


	edb_enter_img_path = EditBox::create();
	edb_enter_img_path->setRenderer(theme.getRenderer("EditBox"));
	edb_enter_img_path->setPosition(40, 260);
	edb_enter_img_path->setSize(800, 100);
	edb_enter_img_path->setTextSize(36);
	gui->add(edb_enter_img_path);


	lbl_enter_drawble_state = Label::create();
	lbl_enter_drawble_state->setRenderer(theme.getRenderer("Label"));
	lbl_enter_drawble_state->setText("enter drawable state:");
	lbl_enter_drawble_state->setPosition(40, 380);
	lbl_enter_drawble_state->setTextSize(36);
	gui->add(lbl_enter_drawble_state);

	edb_enter_drawable_state = EditBox::create();
	edb_enter_drawable_state->setRenderer(theme.getRenderer("EditBox"));
	edb_enter_drawable_state->setPosition(40, 440);
	edb_enter_drawable_state->setSize(800, 100);
	edb_enter_drawable_state->setTextSize(36);
	gui->add(edb_enter_drawable_state);
	


	create = Button::create();
	create->setRenderer(theme.getRenderer("Button"));
	create->setPosition(250, 550);
	create->setText("create!");
	create->setTextSize(48);
	create->setSize(300, 150);
	create->connect("pressed", [&]() {able_to_create = true; });
	gui->add(create);
}


ObjectCreatingMenu::~ObjectCreatingMenu()
{
}
