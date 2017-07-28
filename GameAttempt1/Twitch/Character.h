#ifndef TWITCH_CHARACTER
#define TWITCH_CHARACTER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Character
{
public:

	Character();
	Character(Sprite _sprite);
	
	void Flap();

	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRigidbody();

private:
	Sprite sprite;
	Rigidbody rb;

};

#endif