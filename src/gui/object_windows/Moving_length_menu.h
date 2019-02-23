#ifndef MOVINGLENGTHMENU_H
#define MOVINGLENGTHMENU_H
#include"stdafx.h"

class Moving_length_menu
{
private:
	Theme theme;


	Label::Ptr lbl_enter_length;
	EditBox::Ptr edb_enter_length;

	Button::Ptr accept;

public:
	int get_length();

	Moving_length_menu(Gui* & gui, bool & ok);
	~Moving_length_menu();
};
#endif // MOVINGLENGTHMENU_H
