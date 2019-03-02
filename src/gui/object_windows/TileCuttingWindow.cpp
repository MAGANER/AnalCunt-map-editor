#include "TileCuttingWindow.h"

TileCuttingWindow::TileCuttingWindow(Gui* & gui, bool & able_to_cut, String button_name, String enter_field_name, string cash_path)
{
    cash = new Cash(cash_path);
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
	lbl_cut_rate->setText(enter_field_name);
	lbl_cut_rate->setTextSize(36);
	gui->add(lbl_cut_rate);

    edb_cut_rate = EditBox::create();
	edb_cut_rate->setRenderer(theme.getRenderer("EditBox"));
	edb_cut_rate->setSize(150, 100);
	edb_cut_rate->setTextSize(36);
	gui->add(edb_cut_rate);

	cut = Button::create();
	cut->setRenderer(theme.getRenderer("Button"));
	cut->setText(button_name);
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
void TileCuttingWindow::set_cash(String width, String height, String cut_rate)
{
    cash->add(width.toAnsiString());
    cash->add(height.toAnsiString());
    cash->add(cut_rate.toAnsiString());
}
void TileCuttingWindow::use_cash()
{
    if(!cash->_is_empty())
    {
        width_value  = atoi(cash->get(0).c_str());
        cout<<width_value<<endl;
        height_value = atoi(cash->get(1).c_str());

        lbl_cut_rate->setText(cash->get(2));
        edb_cut_rate->setText(lbl_cut_rate->getText());

        update_labels_values();
    }

}

void TileCuttingWindow::save_cash()
{
    cash->save();
}
void TileCuttingWindow::load_cash()
{
    cash->load();
}


int TileCuttingWindow::get_width()
{
    return width_value;
}
int TileCuttingWindow::get_height()
{
    return height_value;
}

