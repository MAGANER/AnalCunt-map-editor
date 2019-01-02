#include "HotKeyProcessor.h"



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

	bool user_doesnt_click = escape && z && x && num3
		&& up && down && left && right && Q && num4 && E && R;
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
	action = "-1";
}


HotKeyProcessor::~HotKeyProcessor()
{
}
