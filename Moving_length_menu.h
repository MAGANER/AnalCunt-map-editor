#pragma once
#include"TGUI\TGUI.hpp"

using namespace tgui;

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

