#include "Serialisator.h"


void Serialisator::deserialisate(vector<Entity *> & objects)
{

	bool ok = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "load level...",gui);
	SerialisatorWindow* serialisator = new SerialisatorWindow(gui, ok);


	while (window->is_open())
	{
		window->check_event(gui);

		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ok = true;
		}

		String path = serialisator->get_path();

		if (ok)
		{
			string file_path = path.toAnsiString();
			ifstream file;


            file.open(file_path);
            if (file.fail())
            {
                cout << "fuck you";
            }
            file >> world;

            int object_counter = 0;
            while (true)
            {
                if (!world["world"][to_string(object_counter)].empty())
                {
                    Entity * object = new Entity();

                    cout << "good" << endl;
                    int id = object_counter;
                    float x            = world["world"][to_string(object_counter)].at(0);
                    float y            = world["world"][to_string(object_counter)].at(1);
                    string image       = world["world"][to_string(object_counter)].at(2);
                    string type        = world["world"][to_string(object_counter)].at(3);
                    float rotation     = world["world"][to_string(object_counter)].at(4);
                    bool  is_drawable  = world["world"][to_string(object_counter)].at(5);
                    float width        = world["world"][to_string(object_counter)][6].at(0);
                    float height       = world["world"][to_string(object_counter)][6].at(1);
                    float txtur_rect_x = world["world"][to_string(object_counter)][6].at(2);
                    float txtur_rect_y = world["world"][to_string(object_counter)][6].at(3);

                    object->set_pos(x, y);
                    object->set_id(id);
                    object->set_image(image);
                    object->set_image_path(image);
                    object->set_type(type);
                    object->set_rotation(rotation);
                    object->set_drawable_state(is_drawable);
                    object->set_width(width);
                    object->set_height(height);

                    IntRect* rect = new IntRect(txtur_rect_x,txtur_rect_y,width,height);
                    cout<<x <<" "<<y<<endl;
                    object->set_texture_rect(*rect);
                    objects.push_back(object);
                    delete rect;
                    ++object_counter;
                }
                else
                {
                    cout << "fuck";
                    break;
                }
            }


			window->close();
			ok = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}
	delete gui;
	delete window;
	delete serialisator;

}
void Serialisator::serialisate(vector<Entity *> & objects)
{
	bool ok = false;

	Gui* gui = new Gui;
	WindoW* window = new WindoW(300, 300, "save level...", gui);
	SerialisatorWindow* serialisator = new SerialisatorWindow(gui, ok);

	while (window->is_open())
	{
		window->check_event(gui);

		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			ok = true;
		}


		String path = serialisator->get_path();
		if (ok)
		{
			string file_path = path.toAnsiString();
			json world;
			ofstream file;


            file.open(file_path, ios::app);

            auto object = objects.begin();
            while(object != objects.end())
            {
                world["world"][to_string((*object)->get_id())] = { (*object)->get_x(),
                                                                   (*object)->get_y(),
                                                                   (*object)->get_image_path(),
                                                                   (*object)->get_type(),
                                                                   (*object)->get_rotation(),
                                                                   (*object)->is_drawable(),
                                                                    ["texture_rect"]=
                                                                       {(*object)->get_width(),
                                                                        (*object)->get_height(),
                                                                        (*object)->get_texture_rect().left,
                                                                        (*object)->get_texture_rect().top
                                                                       }
                                                                };

                object++;
            }

				file << world;
				file.close();


			window->close();
			ok = false;
		}

		window->clear(sf::Color(74, 72, 75));
		gui->draw();
		window->display();
	}
	delete gui;
	delete window;
	delete serialisator;
}
Serialisator::Serialisator()
{
}


Serialisator::~Serialisator()
{
}
