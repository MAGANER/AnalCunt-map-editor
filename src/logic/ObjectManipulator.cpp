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
    create(objects);
    if(!objects.empty())
    {
        cut_tile(objects);
        set_new_obj_near_to_last(objects);
    }

}
void ObjectManipulator::delete_obj(vector<Entity *> & objects)
{
	objects.erase(--objects.end());
}
void ObjectManipulator::rotate_obj(vector<Entity *> & objects, float angle)
{
    if(!objects.empty())
    {
        auto last_object = --objects.end();
       (*last_object)->set_rotation((*last_object)->get_rotation()+ angle);
    }
}
void ObjectManipulator::move_obj(vector<Entity *> & objects, string direction)
{
    if(!objects.empty())
    {
        auto last_object = --objects.end();
        float old_x_pos = (*last_object)->get_x();
        float old_y_pos = (*last_object)->get_y();

        if(direction == "up")
        {
            (*last_object)->set_pos(old_x_pos, old_y_pos - moving_length);
        }
        if(direction == "down")
        {
            (*last_object)->set_pos(old_x_pos, old_y_pos + moving_length);
        }
        if(direction == "left")
        {
            (*last_object)->set_pos(old_x_pos - moving_length, old_y_pos);
        }
        if (direction == "right")
        {
            (*last_object)->set_pos(old_x_pos + moving_length, old_y_pos);
        }
    }
}
void ObjectManipulator::change_obj_parameters(vector<Entity *> & objects)
{
	bool able_to_change = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(400, 400, "change object...", gui);
	ObjectParameterWindow* parameter_window = new ObjectParameterWindow(gui, able_to_change);

	parameter_window->set_parameters(objects, (*(--objects.end()))->get_id() );
	while (window->is_open())
	{
		window->check_event(gui);
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_change = true;
		}


		if (able_to_change)
		{
            auto last_object = --objects.end();

            int id = atoi(parameter_window->get_id().c_str());
            float rotation_angle = (float)atoi(parameter_window->get_rotation_angle().c_str());

            (*last_object)->set_id(id);
            (*last_object)->set_rotation(rotation_angle);
            (*last_object)->set_image_path(parameter_window->get_img_path());
            (*last_object)->set_type(parameter_window->get_type());

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

void ObjectManipulator::create(vector<Entity *> & objects)
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
		String drawable = creating_menu->get_drawble_state();

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
void ObjectManipulator::cut_tile(vector<Entity *> & objects)
{
    bool able_to_cut = false;

    auto last_object_ptr  = objects.end();
    last_object_ptr-=1; //get last object
    (*last_object_ptr)->set_pos(0.0f,0.0f);


	Gui *gui = new Gui;

    TileCutter * cutter = new TileCutter((*last_object_ptr)->get_width(),(*last_object_ptr)->get_height());


	int window_width  = (*last_object_ptr)->get_width()  + 200;
    int window_height = (*last_object_ptr)->get_height() + 200;
	WindoW *window = new WindoW(window_width,window_height,"cut tile...",gui);


	TileCuttingWindow* cutting_menu=  new TileCuttingWindow(gui,able_to_cut);

	cutting_menu->set_labels_position((*last_object_ptr)->get_width()+(*last_object_ptr)->get_x());


    while(window->is_open())
    {
        window->check_event(gui);

        float speed = cutting_menu->get_cut_rate();

        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            cutter->cut_up(speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            cutter->cut_up(-speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            cutter->cut_lefter(speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            cutter->cut_lefter(-speed);
        }

        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            cutter->move_up(speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            cutter->move_up(-speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            cutter->move_lefter(speed);
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            cutter->move_lefter(-speed);
        }

        if(able_to_cut)
        {
            sf::Vector2f size;
            size.x = cutter->get_width();
            size.y = cutter->get_height();

            sf::Vector2f position = cutter->get_position();

            IntRect rect(position.x,position.y,size.x,size.y);
            (*last_object_ptr)->set_texture_rect(rect);

            window->close();
        }
        cutting_menu->set_height(cutter->get_height());
        cutting_menu->set_width(cutter->get_width());
        cutting_menu->update_labels_values();


        window->clear(sf::Color(74, 72, 75));
		gui->draw();
        window->draw(*last_object_ptr);
        window->draw(*cutter->get_rect());
		window->display();
    }

    delete gui;
    delete window;
    delete cutting_menu;
    delete cutter;
}
void ObjectManipulator::set_new_obj_near_to_last(vector<Entity *> & objects)
{
    auto last_object  = --objects.end();


    if (objects.size() == 1)
    {
        (*last_object)->set_pos(100.0f, 100.0f);
        (*last_object)->set_id(0);
    }
    else
    {
        auto pre_last_object = --(--objects.end());
        float new_x = (*pre_last_object)->get_x()+moving_length;
        float new_y = (*pre_last_object)->get_y();

        (*last_object)->set_pos(new_x,new_y);
        (*last_object)->set_id((*last_object)->get_id());
    }
}
