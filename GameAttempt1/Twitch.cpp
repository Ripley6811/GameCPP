#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"
#include "Engine\IO\mouse.h"
#include "Engine\IO\Keyboard.h"
#include "Twitch\InputManager.h"

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

	InputManager im(&player);

	while (true) 
	{
		engine.Update();
		player.Update();
		im.Update();

		engine.BeginRender();
		player.Render();
		engine.EndRender();
	}


	return 0;
}