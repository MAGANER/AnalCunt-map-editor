#include "HotKeyProcessor.h"


void HotKeyProcessor::check_mouse_clicked_at_object(vector<Entity *> & objects, int & object_id, WindoW & win)
{	
	for (size_t i = 0; i < objects.size(); ++i)
	{
		Vector2i mouse_pos = sf::Mouse::getPosition(*win.get_win());
		float mouse_x = mouse_pos.x;
		float mouse_y = mouse_pos.y;

		float x_left_edge = objects[i]->get_x();

		float width = objects[i]->returnSprite().getTextureRect().width;
		float x_right_edge = objects[i]->get_x() + width;

		float y_top_edge = objects[i]->get_y();

		float height = objects[i]->returnSprite().getTextureRect().height;
		float y_down_edge = y_top_edge + height;


		bool x_intersection = mouse_x > x_left_edge 
			               && mouse_x < x_right_edge;

		bool y_intersection = mouse_y > y_top_edge
			               && mouse_y < y_down_edge;

		
		if (x_intersection && y_intersection)
		{
			object_id = objects[i]->get_id();
			break;
		}

		/* it doesn't work. why?
		if (objects[i]->returnSprite().getTextureRect().contains(mouse_pos))
		{
			object_id = objects[i]->get_id();
			break;
		}
		*/
	}
}
HotKeyProcessor::HotKeyProcessor()
{
	action = "-1";
	clicked = false;
	moving_length = 32;
}
void HotKeyProcessor::is_user_clicking()
{
	bool escape = !Keyboard::isKeyPressed(Keyboard::Escape);
	bool z = !Keyboard::isKeyPressed(Keyboard::Z);
	bool x = !Keyboard::isKeyPressed(Keyboard::X);
	bool num3 = !Keyboard::isKeyPressed(Keyboard::Num3);
	bool num4 = !Keyboard::isKeyPressed(Keyboard::Num4);
	bool up = !Keyboard::isKeyPressed(Keyboard::Up);
	bool down = !Keyboard::isKeyPressed(Keyboard::Down);
	bool left = !Keyboard::isKeyPressed(Keyboard::Left);
	bool right = !Keyboard::isKeyPressed(Keyboard::Right);
	bool Q = !Keyboard::isKeyPressed(Keyboard::Q);
	bool E = !Keyboard::isKeyPressed(Keyboard::E);
	bool R = !Keyboard::isKeyPressed(Keyboard::R);
	bool left_mouse_button = !Mouse::isButtonPressed(Mouse::Button::Left);

	bool user_doesnt_click = escape && z && x && num3
		&& up && down && left && right && Q && num4 && E && R && left_mouse_button;
	if (user_doesnt_click)
	{
		clicked = false;
	}
}
void HotKeyProcessor::get_action()
{
	if (!clicked)
	{
		// window manipulation
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			action = "close";
		}
		if (Keyboard::isKeyPressed(Keyboard::Z))
		{
			action = "clear";
		}
		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			action = "resize";
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			action = "up";
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			action = "down";
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			action = "left";
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			action = "right";
		}

		// object manipulation
		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			action = "create object";
		}
		if (Keyboard::isKeyPressed(Keyboard::Num4))
		{
			action = "set length";
		}
		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			action = "set rotation";
		}
		if (Mouse::isButtonPressed(Mouse::Button::Left))
		{
			action = "change";
		}


		// object moving
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			action = "move up";
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			action = "move down";
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			action = "move left";
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			action = "move right";
		}

		//saving project into json file
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			action = "serialise";
		}
		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			action = "deserialisate";
		}

		clicked = true;
	}
}
void HotKeyProcessor::check_action(WindoW & window,  vector<Entity *> & objects,  Camera & camera, ObjectManipulator & obj_manipulator)
{
	if (action == "up")
	{
		camera.move(action);
	}
	if (action == "down")
	{
		camera.move(action);
	}
	if (action == "left")
	{
		camera.move(action);
	}
	if (action == "right")
	{
		camera.move(action);
	}
	if (action == "close")
	{
		window.close();
	}
	if (action == "clear")
	{
		window.clear();
	}
	if (action == "resize")
	{
		int width, height;
		cout << "enter width:";
		cin >> width;
		cout << endl;
		
		cout << "enter height:";
		cin >> height;
		window.resize(width, height);
		camera.reset(width, height);

	}
	if (action == "create object")
	{
		obj_manipulator.create_obj(objects);
	}
	if (action == "move up")
	{
		obj_manipulator.move_obj(objects, "up", moving_length);
	}
	if (action == "move down")
	{
		obj_manipulator.move_obj(objects, "down", moving_length);
	}
	if (action == "move left")
	{
		obj_manipulator.move_obj(objects, "left", moving_length);
	}
	if (action == "move right")
	{
		obj_manipulator.move_obj(objects, "right", moving_length);
	}
	if (action == "serialise")
	{
		serialisator.serialisate(objects);
	}
	if (action == "set length")
	{
		int length = 0;
		cout << "enter moving length:";
		cin >> length;
		moving_length = length;
	}
	if (action == "deserialisate")
	{
		serialisator.deserialisate(objects);
	}
	if (action == "set rotation")
	{
		
		float angle = 0.0f;
		cout << "enter rotation angle:";
		cin >> angle;
		obj_manipulator.rotate_obj(objects, angle);
	}
	if (action == "change")
	{
		int object_id = -1;
		check_mouse_clicked_at_object(objects, object_id,window);
		if (object_id != -1)
		{
			obj_manipulator.choose_obj(object_id);
			obj_manipulator.change_obj_parameters(objects,object_id);
		}

	}
	action = "-1";
}


HotKeyProcessor::~HotKeyProcessor()
{
}
