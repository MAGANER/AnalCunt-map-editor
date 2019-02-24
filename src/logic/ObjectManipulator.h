#ifndef OBJECTMANIPULATOR_H
#define OBJECTMANIPULATOR_H
#include"stdafx.h"
#include"object/Entity.h"
#include"window/WindoW.h"
#include"gui/object_windows/ObjectCreatingMenu.h"
#include"gui/object_windows/ObjectParameterWindow.h"
#include"gui/object_windows/Moving_length_menu.h"
#include"gui/object_windows/TileCuttingWindow.h"
#include"logic/TileCutter.h"

class ObjectManipulator
{
private:
	int moving_length;

    void create(vector<Entity *> & objects);
    void cut_tile(vector<Entity *> & objects);
    void set_new_obj_near_to_last(vector<Entity *> & objects);
public:
	void create_obj(vector<Entity *> & objects);
	void delete_obj(vector<Entity *> & objects);
	void move_obj(vector<Entity *> & objects,string direction);
	void rotate_obj(vector<Entity *> & objects,float angle);
	void change_obj_parameters(vector<Entity *> & objects);
	void change_moving_length();

	ObjectManipulator();
	~ObjectManipulator();
};
#endif // OBJECTMANIPULATOR_H
