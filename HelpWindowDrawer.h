#pragma once
#include"stdafx.h"
#include"AboutWindow.h"
#include"HotKeyWindow.h"
#include"WindoW.h"

class HelpWindowDrawer
{
public:
	void show_about_window();
	void show_hot_key_window();

	HelpWindowDrawer();
	~HelpWindowDrawer();
};

