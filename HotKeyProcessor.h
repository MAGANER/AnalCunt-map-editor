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
#include"Camera.h"
#include"Serialisator.h"
#include"ObjectManipulator.h"

using namespace std;

class HotKeyProcessor
{
private:
	int moving_length;
	bool clicked;
	string action;

	Serialisator serialisator;

public:
	void is_user_clicking();
	void get_action();
	void check_action(WindoW & window, vector<Entity *> & objects, Camera & camera, ObjectManipulator & obj_manipulator);

  

	HotKeyProcessor();
	~HotKeyProcessor();
};

