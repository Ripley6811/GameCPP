#ifndef TWITCH_INPUTMANAGER
#define TWITCH_INPUTMANAGER

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/mouse.h"
#include "Character.h"

class InputManager
{
public:
	InputManager(Character* _character);

	void Update();

private:
	Character* character;

};

#endif