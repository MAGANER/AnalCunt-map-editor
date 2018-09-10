/* Manager - this object manages programm to do main actions
   actions list:
   1.add object
   2.delete object
   3.delete all
   4.save all
   5.close window
*/
#pragma once
#include"WindoW.h"
#include"Entity.h"
#include"Serialisator.h"

using namespace std;

class Manager
{
private:
	int moving_length;
	bool clicked;
	string action;

	Serialisator serialisator;
public:
	void is_user_clicking();
	void get_action();
	void check_action(WindoW & window, int & object_counter, vector<Entity *> & objects, int & usabling_object_id);


	Manager();
	~Manager();
};

