#include "HelpWindowDrawer.h"

void HelpWindowDrawer::show_hot_key_window()
{
	WindoW * window = new WindoW(400, 300, "Hot Keys...");
	HotKeyWindow* hot_key_window = new HotKeyWindow();

	while (window->is_open())
	{
		window->check_event();

		window->clear(sf::Color(74, 72, 75));
		hot_key_window->draw(window);
		window->display();
	}
	delete window;
	delete hot_key_window;

}
void HelpWindowDrawer::show_about_window()
{
	WindoW * window = new WindoW(400, 200, "About...");
	AboutWindow* about_window = new AboutWindow();

	while (window->is_open())
	{
		window->check_event();

		window->clear(sf::Color(74, 72, 75));
		about_window->draw(window);
		window->display();
	}
		delete window;
		delete about_window;

}
HelpWindowDrawer::HelpWindowDrawer()
{
}


HelpWindowDrawer::~HelpWindowDrawer()
{
}
