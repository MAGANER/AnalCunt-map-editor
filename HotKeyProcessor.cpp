#include "HotKeyProcessor.h"


HotKeyProcessor::HotKeyProcessor()
{
	action = "-1";
	clicked = false;
	moving_length = 32;
}
void HotKeyProcessor::is_user_clicking()
{
	bool r = !(Keyboard::isKeyPressed(Keyboard::R));
	bool t = !Keyboard::isKeyPressed(Keyboard::T);
	bool escape = !Keyboard::isKeyPressed(Keyboard::Escape);
	bool num3 = !Keyboard::isKeyPressed(Keyboard::Num3);
	bool num4 = !Keyboard::isKeyPressed(Keyboard::Num4);
	bool up = !Keyboard::isKeyPressed(Keyboard::Up);
	bool down = !Keyboard::isKeyPressed(Keyboard::Down);
	bool left = !Keyboard::isKeyPressed(Keyboard::Left);
	bool right = !Keyboard::isKeyPressed(Keyboard::Right);
	bool Q = !Keyboard::isKeyPressed(Keyboard::Q);
	bool E = !Keyboard::isKeyPressed(Keyboard::E);
	bool M = !Keyboard::isKeyPressed(Keyboard::M);

	bool user_doesnt_click = escape &&  num3 && r && t && M
		&& up && down && left && right && Q && num4 && E;
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
		if (Keyboard::isKeyPressed(Keyboard::M))
		{
			action = "move to last";
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
			action = "rotate left";
		}
		if (Keyboard::isKeyPressed(Keyboard::T))
		{
			action = "rotate right";
		}
		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			action = "change last one";
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
	if (action == "create object")
	{
		obj_manipulator.create_obj(objects);
	}
	if (action == "move up")
	{
		obj_manipulator.move_obj(objects, "up");
	}
	if (action == "move down")
	{
		obj_manipulator.move_obj(objects, "down");
	}
	if (action == "move left")
	{
		obj_manipulator.move_obj(objects, "left");
	}
	if (action == "move right")
	{
		obj_manipulator.move_obj(objects, "right");
	}
	if (action == "serialise")
	{
		serialisator.serialisate(objects);
	}
	if (action == "set length")
	{
		obj_manipulator.change_moving_length();
	}
	if (action == "deserialisate")
	{
		serialisator.deserialisate(objects);
	}
	if (action == "rotate left")
	{
		obj_manipulator.rotate_obj(objects, 2.0f);
	}
	if (action == "rotate right")
	{
		obj_manipulator.rotate_obj(objects, -2.0f);
	}
	if (action == "change last one")
	{
		obj_manipulator.change_obj_parameters(objects);
	}
	if (action == "move to last")
	{
		camera.move_to_last_object(objects);
	}
	action = "-1";
}


HotKeyProcessor::~HotKeyProcessor()
{
}
