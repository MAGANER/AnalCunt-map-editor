#ifndef TILECUTTINGWINDOW_H
#define TILECUTTINGWINDOW_H
#include"stdafx.h"
#include"logic/Cash.h"

/*
  it is used to cutter tile from tile map,
  but also this is needed to set physical body.
*/
class TileCuttingWindow
{
private:
    Cash* cash;
    Theme theme;

    Label::Ptr width; // of cut area
    int width_value;

    Label::Ptr height;// of cut area
    int height_value;

    Label::Ptr   lbl_cut_rate;
    EditBox::Ptr edb_cut_rate;

    Button::Ptr cut;
public:
    TileCuttingWindow(Gui* & gui, bool & able_to_cut, String button_name, String enter_field_name, string cash_path);
    ~TileCuttingWindow();


    int get_width();
    int get_height();
    float get_cut_rate();
    void set_width(int width);
    void set_height(int height);
    void set_labels_position(int obj_width);
    void update_labels_values();


    void set_cash(String width, String height,String cut_rate);
	void use_cash();

	void save_cash();
	void load_cash();
};

#endif // TILECUTTINGWINDOW_H
