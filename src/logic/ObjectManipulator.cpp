#include "ObjectManipulator.h"

void ObjectManipulator::change_moving_length()
{
	bool able_to_change = false; // change moving length if that is true

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "change moving length", gui);
	Moving_length_menu* menu = new Moving_length_menu(gui, able_to_change);

	while (window->is_open())
	{
		window->check_event(gui);


		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_change = true;
		}

		int new_length = menu->get_length();


		bool got_data = new_length != 0; // check length field is not empty


		// set new length and close appeared window
		if (able_to_change && got_data)
		{
			moving_length = new_length;
			able_to_change = false;
			window->close();
		}
		else
		{
			able_to_change = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}

	delete gui;
	delete window;
	delete menu;
}
void ObjectManipulator::create_obj(vector<Entity *> & objects)
{
    create(objects);
    if(!objects.empty())
    {
        cut_tile(objects);
        set_physical_body(objects);
        set_new_obj_near_to_last(objects);
    }

}
void ObjectManipulator::delete_obj(vector<Entity *> & objects)
{
    //delete last object
	objects.erase(--objects.end());
}
void ObjectManipulator::rotate_obj(vector<Entity *> & objects, float angle)
{
    //it's important to check
    //unless last_object shall point nothing
    if(!objects.empty())
    {
        //rotate last object
        auto last_object = --objects.end();
       (*last_object)->set_rotation((*last_object)->get_rotation()+ angle);
    }
}
void ObjectManipulator::move_obj(vector<Entity *> & objects, string direction)
{
    //it's impossible to move
    //if there are no objects
    //so first check there are objects
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
	bool able_to_change = false;// change object paremeters if that is true

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


		// set new parameter and close appeared window
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
	moving_length = 32;
}
ObjectManipulator::~ObjectManipulator()
{
}

void ObjectManipulator::create(vector<Entity *> & objects)
{
    bool able_to_create = false; // create object if that is true
    bool used_cash = false;      // load and set cash if that is false

	Gui *gui = new Gui;
	WindoW *window = new WindoW(400,400,"create object...",gui);
	ObjectCreatingMenu* creating_menu=  new ObjectCreatingMenu(gui,able_to_create);



	while (window->is_open())
	{
		window->check_event(gui);


		// load cash of last object
		// and set it
		if (objects.size() != 0 && !used_cash)
		{
			creating_menu->load_cash();
			creating_menu->use_cash();
			used_cash = true;
		}

        // get data from enter fields
		String img_path = creating_menu->get_img_path();
		String obj_type = creating_menu->get_obj_type();
		String drawable = creating_menu->get_drawble_state();

		// check they aren't empty
		bool got_data = !(img_path.isEmpty() && obj_type.isEmpty() && drawable.isEmpty());

		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			able_to_create = true;
		}

		if (able_to_create && got_data)
		{
            // create object
			Entity * object = new Entity();
			object->set_image(img_path.toAnsiString());
			object->set_image_path(img_path.toAnsiString());
			object->set_type(obj_type.toAnsiString());


			string drawable_state = drawable.toAnsiString();
			bool  _drawable = atoi(drawable_state.c_str());
			object->set_drawable_state(_drawable);


			// set id
            if(objects.size() != 0)
            {
                auto last_object = --objects.end();
                int id           = (*last_object)->get_id()+1;
                object->set_id(id);
            }
            else
            {
                // if object is  created first ever
                object->set_id(0);
            }




			creating_menu->set_cash(obj_type, img_path,drawable_state);
			creating_menu->save_cash();

			objects.push_back(object);


			window->close();
			able_to_create = false;
			used_cash = false;
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
    bool able_to_cut = false; // cut tile if that is true


    auto last_object  = --objects.end();
    (*last_object)->set_pos(0.0f,0.0f);


	Gui *gui = new Gui;
    TileCutter * cutter = new TileCutter((*last_object)->get_width(),(*last_object)->get_height());

    // set window size, relating to object size
    // cos object must be in the window
	int window_width  = (*last_object)->get_width()  + 200;
    int window_height = (*last_object)->get_height() + 200;
	WindoW *window = new WindoW(window_width,window_height,"cut tile...",gui);


	TileCuttingWindow* cutting_menu=  new TileCuttingWindow(gui,able_to_cut,"cut!","cut rate:");
	// set position, relating to object size
	cutting_menu->set_labels_position((*last_object)->get_width()+(*last_object)->get_x());

    while(window->is_open())
    {
        window->check_event(gui);

        float speed = cutting_menu->get_cut_rate();

        // Cutting
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

        // Moving
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

        //Close window
        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window->close();
        }

        // user changes cutting area
        // so we have to always update
        // values of cutting area sizes
        cutting_menu->set_height(cutter->get_height());
        cutting_menu->set_width(cutter->get_width());
        cutting_menu->update_labels_values();


        // if user pressed button "Cut!"
        // than cut and close appeared window
        if(able_to_cut)
        {
            // size of cutting area
            sf::Vector2f size;
            size.x = cutter->get_width();
            size.y = cutter->get_height();

            // position of cutting area
            sf::Vector2f position = cutter->get_position();

            // only this rect will be drawn
            IntRect rect(position.x,position.y,size.x,size.y);
            (*last_object)->set_texture_rect(rect);

            window->close();
        }




        window->clear(sf::Color(74, 72, 75));
		gui->draw();
        window->draw(*last_object);
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
    // set created object near to last object

    auto last_object  = --objects.end();

    // if it's first object
    // than it sets at start
    if (objects.size() == 1)
    {
        (*last_object)->set_pos(100.0f, 100.0f);
        (*last_object)->set_id(0);
    }
    else
    {
        // object is already added
        // so last one is pre last
        // and new object is last one
        auto pre_last_object = --(--objects.end());
        float new_x = (*pre_last_object)->get_x()+moving_length;
        float new_y = (*pre_last_object)->get_y();

        (*last_object)->set_pos(new_x,new_y);
        (*last_object)->set_id((*last_object)->get_id());
    }
}
void ObjectManipulator::set_physical_body(vector<Entity*>& objects)
{
    bool able_to_set = false;


    auto last_object  = --objects.end();
    (*last_object)->set_pos(0.0f,0.0f);


	Gui *gui = new Gui;
    TileCutter * cutter = new TileCutter((*last_object)->get_width(),(*last_object)->get_height());

    // set window size, relating to object size
    // cos object must be in the window
	int window_width  = (*last_object)->get_width()  + 200;
    int window_height = (*last_object)->get_height() + 200;
	WindoW *window = new WindoW(window_width,window_height,"set physical body...",gui);


	TileCuttingWindow* cutting_menu=  new TileCuttingWindow(gui,able_to_set,"set!","set rate:");
	// set position, relating to object size
	cutting_menu->set_labels_position((*last_object)->get_width()+(*last_object)->get_x());

    while(window->is_open())
    {
        window->check_event(gui);

        float speed = cutting_menu->get_cut_rate();

        // Cutting
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

        // Moving
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

        //Close window
        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window->close();
        }

        // user changes setting area
        // so we have to always update
        // values of setting area sizes
        cutting_menu->set_height(cutter->get_height());
        cutting_menu->set_width(cutter->get_width());
        cutting_menu->update_labels_values();


        // if user pressed button "set!"
        // than set and close appeared window
        if(able_to_set)
        {
            // size of setting area
            sf::Vector2f size;
            size.x = cutter->get_width();
            size.y = cutter->get_height();

            // position of setting area
            sf::Vector2f position = cutter->get_position();

            // only this rect will be physical body
            IntRect rect(position.x,position.y,size.x,size.y);
            (*last_object)->set_physical_body(rect);

            window->close();
        }




        window->clear(sf::Color(74, 72, 75));
		gui->draw();
        window->draw(*last_object);
        window->draw(*cutter->get_rect());
		window->display();
    }

    delete gui;
    delete window;
    delete cutting_menu;
    delete cutter;

}

