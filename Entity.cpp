#include "Entity.h"


float Entity::get_rotation()
{
	return gobject_spr.getRotation();
}
void Entity::set_rotation(float angle)
{
	gobject_spr.setRotation(angle);
}
json Entity::get_data()
{
	return entity;
}
void Entity::set_image_path(string path)
{
	image_path = path;
	set_image(image_path);
}
string Entity::get_image_path()
{
	return image_path;
}
void Entity::set_data()
{
	//entity[to_string(id)] = { get_x(),get_y(),type };

	entity[to_string(id)]["x"] = get_x();
	entity[to_string(id)]["y"] = get_y();
	entity[to_string(id)]["type"] = type;
	entity[to_string(id)]["image_path"] = image_path;
}
int Entity::get_id()
{
	return id;
}
void Entity::set_id(int id)
{
	this->id = id;
}
void Entity::set_type(string type)
{
	this->type = type;
}
string Entity::get_type()
{
	return type;
}
Entity::Entity()
{
}


Entity::~Entity()
{
}
