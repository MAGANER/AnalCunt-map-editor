#include "Moving_length_menu.h"


int Moving_length_menu::get_length()
{
	return atoi(edb_enter_length->getText().toAnsiString().c_str());
}
Moving_length_menu::Moving_length_menu(Gui* & gui, bool & ok)
{
	theme.load("themes/Black.txt");

	lbl_enter_length = Label::create();
	lbl_enter_length->setRenderer(theme.getRenderer("Label"));
	lbl_enter_length->setText("enter moving length:");
	lbl_enter_length->setPosition(40, 40);
	lbl_enter_length->setTextSize(48);
	gui->add(lbl_enter_length);


	edb_enter_length = EditBox::create();
	edb_enter_length->setRenderer(theme.getRenderer("EditBox"));
	edb_enter_length->setPosition(40, 100);
	edb_enter_length->setSize(800, 100);
	edb_enter_length->setTextSize(48);
	gui->add(edb_enter_length);

	accept = Button::create();
	accept->setRenderer(theme.getRenderer("Button"));
	accept->setPosition(250, 550);
	accept->setText("ok");
	accept->setTextSize(48);
	accept->setSize(300, 150);
	accept->connect("pressed", [&]() {ok = true; });
	gui->add(accept);

}


Moving_length_menu::~Moving_length_menu()
{
}
