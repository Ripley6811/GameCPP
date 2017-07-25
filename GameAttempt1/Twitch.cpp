#include "Engine/Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\mouse.h"
#include "Engine\IO\Keyboard.h"

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

	while (true) 
	{
		engine.Update();
		testSprite.Update();

		//testSprite.MoveTo((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			testSprite.SetRotBy(10);
		}
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
		{
			testSprite.SetRotBy(-10);
		}
		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			testSprite.SetRotBy(-1);
		}
		if (Keyboard::Key(GLFW_KEY_W)) testSprite.MoveUp();
		if (Keyboard::Key(GLFW_KEY_S)) testSprite.MoveDown();
		if (Keyboard::Key(GLFW_KEY_A)) testSprite.MoveLeft();
		if (Keyboard::Key(GLFW_KEY_D)) testSprite.MoveRight();

		engine.BeginRender();
		testSprite.Render();
		engine.EndRender();
	}


	return 0;
}