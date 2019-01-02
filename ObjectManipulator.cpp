#include "ObjectManipulator.h"

void ObjectManipulator::create_obj(vector<Entity *> & objects)
{
	Entity * object = new Entity();
	string type;
	string path;

	cout << "enter path to object image:";
	cin >> path;
	cout << "enter object type:";
	cin >> type;

	object->set_image(path);
	object->set_image_path(path);
	object->set_type(type);
	if (objects.size() == 0)
	{
		object->set_id(0);
	}
	else {
		object->set_id(objects.size());
	}


	current_object_id = object->get_id();

	objects.push_back(object);

}
void ObjectManipulator::delete_obj(vector<Entity *> & objects)
{
	objects.erase(objects.begin() + current_object_id);
}
void ObjectManipulator::rotate_obj(vector<Entity *> & objects, float angle)
{
	objects[current_object_id]->set_rotation(angle);
}
void ObjectManipulator::move_obj(vector<Entity *> & objects, string direction, float length)
{
	float old_x_pos = objects[current_object_id]->get_x();
	float old_y_pos = objects[current_object_id]->get_y();

	if (direction == "up")
	{	
		objects[current_object_id]->set_pos(old_x_pos, old_y_pos - length);
	}
	if (direction == "down")
	{
		objects[current_object_id]->set_pos(old_x_pos, old_y_pos + length);
	}
	if (direction == "left")
	{
		objects[current_object_id]->set_pos(old_x_pos - length, old_y_pos);
	}
	if (direction == "right")
	{
		objects[current_object_id]->set_pos(old_x_pos + length, old_y_pos);
	}
}
ObjectManipulator::ObjectManipulator()
{
}


ObjectManipulator::~ObjectManipulator()
{
}
