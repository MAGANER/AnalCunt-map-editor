#include "ObjectManipulator.h"

void ObjectManipulator::change_moving_length()
{
	bool ok = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "change moving length", gui);
	Moving_length_menu* menu = new Moving_length_menu(gui, ok);

	while (window->is_open())
	{
		window->check_event(gui);


		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ok = true;
		}

		int new_length = menu->get_length();
		bool got_data = new_length != 0;
		if (ok && got_data)
		{
			moving_length = new_length;
			ok = false;
			window->close();
		}
		else
		{
			ok = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete gui;
	delete window;
	delete menu;
}
void ObjectManipulator::choose_obj(int id)
{
	current_object_id = id;
}
void ObjectManipulator::create_obj(vector<Entity *> & objects)
{
	bool able_to_create = false;

	Gui *gui = new Gui;
	WindoW *window = new WindoW(400,400,"create object...",gui);
	ObjectCreatingMenu* creating_menu=  new ObjectCreatingMenu(gui,able_to_create);


	bool use_cash = false;
	while (window->is_open())
	{
		window->check_event(gui);


		if (objects.size() != 0 && !use_cash)
		{
			creating_menu->load_cash();
			creating_menu->use_cash();
			use_cash = true;
		}

		String img_path = creating_menu->get_img_path();
		String obj_type = creating_menu->get_obj_type();
		String   drawable = creating_menu->get_drawble_state();

		bool got_data = !(img_path.isEmpty() && obj_type.isEmpty() && drawable.isEmpty());

		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_create = true;
		}

		if (able_to_create && got_data)
		{
			Entity * object = new Entity();
			object->set_image(img_path.toAnsiString());
			object->set_image_path(img_path.toAnsiString());
			object->set_type(obj_type.toAnsiString());

			string drawable_state = drawable.toAnsiString();
			bool  _drawable = atoi(drawable_state.c_str());
			object->set_drawable_state(_drawable);

			if (objects.size() == 0)
			{
				object->set_pos(100.0f, 100.0f);
				object->set_id(0);
			}
			else {
				//when we continue to made new level, we open programm
				//and this variable will have zero value
				//so we have to check that
				if (current_object_id == 0)
				{
					object->set_pos(objects[current_object_id]->get_x() + moving_length, objects[current_object_id]->get_y());
				}
				else {
					object->set_pos(objects[objects.size()-1]->get_x() + moving_length, objects[objects.size() - 1]->get_y());
				}

				object->set_id(objects.size());
			}


			creating_menu->set_cash(obj_type, img_path,drawable_state);
			creating_menu->save_cash();


			current_object_id = object->get_id();

			objects.push_back(object);

			window->close();

			able_to_create = false;
			use_cash = false;
		}


		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete creating_menu;
	delete gui;
	delete window;
}
void ObjectManipulator::delete_obj(vector<Entity *> & objects)
{
	objects.erase(objects.begin() + current_object_id);
}
void ObjectManipulator::rotate_obj(vector<Entity *> & objects, float angle)
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->get_id() == current_object_id)
		{
			objects[i]->set_rotation(objects[i]->get_rotation()+ angle);
		}
	}

}
void ObjectManipulator::move_obj(vector<Entity *> & objects, string direction)
{
	//when we continue to made new level, we open programm
	//and current object id will have zero value
	//so we have to check that

	if (objects.size() != 0 && current_object_id == 0 )
	{
		cout << "shot" << endl;
		choose_obj(objects.size() - 1);
	}
		float old_x_pos = objects[current_object_id]->get_x();
		float old_y_pos = objects[current_object_id]->get_y();

		if (direction == "up")
		{
				objects[current_object_id]->set_pos(old_x_pos, old_y_pos - moving_length);
		}
		if (direction == "down")
		{
				objects[current_object_id]->set_pos(old_x_pos, old_y_pos + moving_length);
		}
		if (direction == "left")
		{
				objects[current_object_id]->set_pos(old_x_pos - moving_length, old_y_pos);
		}
		if (direction == "right")
		{
				objects[current_object_id]->set_pos(old_x_pos + moving_length, old_y_pos);
		}
}
void ObjectManipulator::change_obj_parameters(vector<Entity *> & objects)
{
	bool able_to_change = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(400, 400, "change object...", gui);
	ObjectParameterWindow* parameter_window = new ObjectParameterWindow(gui, able_to_change);

	parameter_window->set_parameters(objects, current_object_id);
	while (window->is_open())
	{
		window->check_event(gui);
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_change = true;
		}


		if (able_to_change)
		{
			for (size_t i = 0; i < objects.size(); ++i)
			{
				if (current_object_id == objects[i]->get_id())
				{
					int id = atoi(parameter_window->get_id().c_str());
					float rotation_angle = (float)atoi(parameter_window->get_rotation_angle().c_str());

					objects[i]->set_id(id);
					objects[i]->set_rotation(rotation_angle);
					objects[i]->set_image_path(parameter_window->get_img_path());
					objects[i]->set_type(parameter_window->get_type());
				}
			}

			able_to_change = false;
			window->close();
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete window;
	delete gui;
	delete parameter_window;
}
void ObjectManipulator::change_obj_parameters(vector<Entity *> & objects, int & object_id)
{
	bool able_to_change = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(400, 400, "change object...", gui);
	ObjectParameterWindow* parameter_window = new ObjectParameterWindow(gui, able_to_change);

	parameter_window->set_parameters(objects, object_id);
	while (window->is_open())
	{
		window->check_event(gui);
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_change = true;
		}


		if (able_to_change)
		{
			for (size_t i = 0; i < objects.size(); ++i)
			{
				if (object_id == objects[i]->get_id())
				{
					int id =atoi(parameter_window->get_id().c_str());
					float rotation_angle = (float)atoi(parameter_window->get_rotation_angle().c_str());

					objects[i]->set_id(id);
					objects[i]->set_rotation(rotation_angle);
					objects[i]->set_image_path(parameter_window->get_img_path());
					objects[i]->set_type(parameter_window->get_type());
				}
			}

			able_to_change = false;
			window->close();
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete window;
	delete gui;
	delete parameter_window;
}
ObjectManipulator::ObjectManipulator()
{
	current_object_id = 0;
	moving_length = 32;
}


ObjectManipulator::~ObjectManipulator()
{
}