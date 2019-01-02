#pragma once
#include"stdafx.h"
#include"Entity.h"
class ObjectManipulator
{
private:
	int current_object_id;
public:
	void create_obj(vector<Entity *> & objects);
	void delete_obj(vector<Entity *> & objects);
	void move_obj(vector<Entity *> & objects,string direction,float length);
	void rotate_obj(vector<Entity *> & objects,float angle);
	ObjectManipulator();
	~ObjectManipulator();
};

