#include "SerialisatorWindow.h"


String SerialisatorWindow::get_path()
{
	return edb_enter_path->getText();
}
SerialisatorWindow::SerialisatorWindow(Gui* & gui, bool & ok)
{
	
	theme.load("themes/Black.txt");

	lbl_enter_path = Label::create();
	lbl_enter_path->setRenderer(theme.getRenderer("Label"));
	lbl_enter_path->setText("enter file path:");
	lbl_enter_path->setPosition(40, 40);
	lbl_enter_path->setTextSize(48);
	gui->add(lbl_enter_path);
	

	edb_enter_path = EditBox::create();
	edb_enter_path->setRenderer(theme.getRenderer("EditBox"));
	edb_enter_path->setPosition(40, 100);
	edb_enter_path->setSize(800, 100);
	edb_enter_path->setTextSize(48);
	gui->add(edb_enter_path);

	accept = Button::create();
	accept->setRenderer(theme.getRenderer("Button"));
	accept->setPosition(250, 550);
	accept->setText("ok");
	accept->setTextSize(48);
	accept->setSize(300, 150);
	accept->connect("pressed", [&]() {ok = true; });
	gui->add(accept);

}


SerialisatorWindow::~SerialisatorWindow()
{
}
