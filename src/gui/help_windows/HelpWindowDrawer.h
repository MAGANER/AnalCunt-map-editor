#ifndef HELPWINDOWDRAWER_H
#define HELPWINDOW_DRAWER_H
#include"stdafx.h"
#include"gui/help_windows/AboutWindow.h"
#include"gui/help_windows/HotKeyWindow.h"
#include"window/WindoW.h"

class HelpWindowDrawer
{
public:
	void show_about_window();
	void show_hot_key_window();

	HelpWindowDrawer();
	~HelpWindowDrawer();
};
#endif // HELPWINDOWDRAWER_H
