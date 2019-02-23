#ifndef SERIALISATORWINDOW_H
#define SERIALISATORWINDOW_H
#include"stdafx.h"

class SerialisatorWindow
{
private:
	Theme theme;

	Label::Ptr lbl_enter_path;
	EditBox::Ptr edb_enter_path;

	Button::Ptr accept;
public:
	String get_path();
	SerialisatorWindow(Gui* & gui, bool & ok);
	~SerialisatorWindow();
};
#endif // SERIALISATORWINDOW_H
