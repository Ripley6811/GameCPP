#include "InputManager.h"

InputManager::InputManager(Character * _character) : character(_character) {}

void InputManager::Update()
{
	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		character->Flap();
	}
	if (Keyboard::Key(GLFW_KEY_W)) character->GetRigidbody().AddForce(Vector3(0, 50, 0));
	if (Keyboard::Key(GLFW_KEY_S)) character->GetRigidbody().AddForce(Vector3(0, -50, 0));
	if (Keyboard::Key(GLFW_KEY_A)) character->GetRigidbody().AddForce(Vector3(-50, 0, 0));
	if (Keyboard::Key(GLFW_KEY_D)) character->GetRigidbody().AddForce(Vector3(50, 0, 0));

}