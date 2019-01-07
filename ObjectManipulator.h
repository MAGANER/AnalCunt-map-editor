#pragma once
#include"stdafx.h"
#include"Entity.h"
#include"WindoW.h"
#include"ObjectCreatingMenu.h"
#include"ObjectParameterWindow.h"
#include"Moving_length_menu.h"

class ObjectManipulator
{
private:
	int moving_length;
	int current_object_id;
public:
	void create_obj(vector<Entity *> & objects);
	void delete_obj(vector<Entity *> & objects);
	void move_obj(vector<Entity *> & objects,string direction);
	void rotate_obj(vector<Entity *> & objects,float angle);
	void change_obj_parameters(vector<Entity *> & objects, int & object_id);
	void change_obj_parameters(vector<Entity *> & objects);
	void choose_obj(int id);
	void change_moving_length();

	ObjectManipulator();
	~ObjectManipulator();
};

