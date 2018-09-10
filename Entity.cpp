#include "Entity.h"


json Entity::get_data()
{
	return entity;
}
void Entity::set_data()
{
	entity[to_string(id)] = { get_x(),get_y(),type };
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
