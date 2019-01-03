#include "ObjectManipulator.h"

void ObjectManipulator::create_obj(vector<Entity *> & objects)
{

	bool able_to_create = false;

	Gui *gui = new Gui;
	WindoW *window = new WindoW(400,400,"create object...",gui);
	ObjectCreatingMenu creating_menu(gui,able_to_create);

	
	while (window->is_open())
	{
		window->check_event(gui);
		
		String img_path = creating_menu.get_img_path();
		String obj_type = creating_menu.get_obj_type();

		bool got_data = !(img_path.isEmpty() && obj_type.isEmpty());
		if (able_to_create && got_data)
		{
			Entity * object = new Entity();
			object->set_image(img_path.toAnsiString());
			object->set_image_path(img_path.toAnsiString());
			object->set_type(obj_type.toAnsiString());
			object->set_pos(100.0f, 100.0f);
			if (objects.size() == 0)
			{
				object->set_id(0);
			}
			else {
				object->set_id(objects.size());
			}


			current_object_id = object->get_id();

			objects.push_back(object);

			window->close();
			able_to_create = false;
		}
	

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete gui;
	delete window;
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
