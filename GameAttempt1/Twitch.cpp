#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\mouse.h"
#include "Engine\IO\Keyboard.h"

#include "Twitch\Character.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "Hello Twitch" << endl;
	// system("pause");

	Engine engine;

	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/dino-spaceship.png");
	testSprite.SetScale(0.12f);

	Character player(testSprite);

	while (true) 
	{
		engine.Update();
		player.Update();

		//testSprite.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			player.GetSprite().SetRotBy(10);
		}
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
		{
			player.GetSprite().SetRotBy(-10);
		}
		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			player.GetSprite().SetRotBy(-1);
		}
		if (Keyboard::Key(GLFW_KEY_W)) player.GetRigidbody().AddForce(Vector3(0, 50, 0));
		if (Keyboard::Key(GLFW_KEY_S)) player.GetRigidbody().AddForce(Vector3(0, -50, 0));
		if (Keyboard::Key(GLFW_KEY_A)) player.GetRigidbody().AddForce(Vector3(-50, 0, 0));
		if (Keyboard::Key(GLFW_KEY_D)) player.GetRigidbody().AddForce(Vector3(50, 0, 0));

		engine.BeginRender();
		player.Render();
		engine.EndRender();
	}


	return 0;
}