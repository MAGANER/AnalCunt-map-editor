#ifndef TILECUTTINGWINDOW_H
#define TILECUTTINGWINDOW_H
#include"stdafx.h"

class TileCuttingWindow
{
private:
    Theme theme;

    Label::Ptr width; // of cut area
    int width_value;

    Label::Ptr height;// of cut area
    int height_value;

    Label::Ptr   lbl_cut_rate;
    EditBox::Ptr edb_cut_rate;

    Button::Ptr cut;
public:
    TileCuttingWindow(Gui* & gui, bool & able_to_cut);
    ~TileCuttingWindow();

    float get_cut_rate();
    void set_width(int width);
    void set_height(int height);
    void set_labels_position(int obj_width);
    void update_labels_values();
};

#endif // TILECUTTINGWINDOW_H
