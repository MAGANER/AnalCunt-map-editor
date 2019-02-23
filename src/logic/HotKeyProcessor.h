/* this class checks pressed hot keys
   actions list:
   1.add object
   2.delete object
   3.delete all
   4.save all
   5.close window
   6.move camera
   7.move objects
   8.save/load levels
*/
#ifndef HOTKEYPROCESSOR_H
#define HOTKEYPROCESSOR_H
#include"stdafx.h"
#include"window/WindoW.h"
#include"window/Camera.h"
#include"object/Entity.h"
#include"logic/Serialisator.h"
#include"logic/ObjectManipulator.h"

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
#endif // HOTKEYPROCESSOR_H
