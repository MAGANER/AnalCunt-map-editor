#include "TileCuttingWindow.h"

TileCuttingWindow::TileCuttingWindow(Gui* & gui, bool & able_to_cut)
{
    theme.load("themes/Black.txt");

    width = Label::create();
	width->setRenderer(theme.getRenderer("Label"));
	width->setText("width:"+to_string(width_value));
	width->setTextSize(36);
	gui->add(width);

    height = Label::create();
	height->setRenderer(theme.getRenderer("Label"));
	height->setText("height:"+to_string(height_value));
	height->setTextSize(36);
	gui->add(height);

    lbl_cut_rate = Label::create();
	lbl_cut_rate->setRenderer(theme.getRenderer("Label"));
	lbl_cut_rate->setText("cut rate:");
	lbl_cut_rate->setTextSize(36);
	gui->add(lbl_cut_rate);

    edb_cut_rate = EditBox::create();
	edb_cut_rate->setRenderer(theme.getRenderer("EditBox"));
	edb_cut_rate->setSize(150, 100);
	edb_cut_rate->setTextSize(36);
	gui->add(edb_cut_rate);

	cut = Button::create();
	cut->setRenderer(theme.getRenderer("Button"));
	cut->setText("cut!");
	cut->setTextSize(36);
	cut->setSize(200, 150);
	cut->connect("pressed", [&]() {able_to_cut = true; });
	gui->add(cut);
}

TileCuttingWindow::~TileCuttingWindow()
{

}

float TileCuttingWindow::get_cut_rate()
{
    string str_value = edb_cut_rate->getText().toAnsiString();
    return atof(str_value.c_str());
}
void TileCuttingWindow::set_height(int height)
{
    height_value = height;
}
void TileCuttingWindow::set_width(int width)
{
    width_value = width;
}
void TileCuttingWindow::set_labels_position(int obj_width)
{
    width->setPosition(obj_width+400.0f,40.0f);
    height->setPosition(obj_width+400.0f,90.0f);
    lbl_cut_rate->setPosition(obj_width+400.0f,150.0f);
    edb_cut_rate->setPosition(obj_width+400.0f,200.0f);
    cut->setPosition(obj_width+400.0f,500.0f);
}
void TileCuttingWindow::update_labels_values()
{
    height->setText("height:"+to_string(height_value));
    width->setText("width:"+to_string(width_value));
}

