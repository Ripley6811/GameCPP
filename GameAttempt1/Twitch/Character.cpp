#include "Character.h"

Character::Character()
{
}

Character::Character(Sprite _sprite)
{
	sprite = _sprite;
	rb.Init(0.9f, -10, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}

void Character::Update()
{
	sprite.Update();
	rb.Update();
}

void Character::Render()
{
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));
}

Sprite& Character::GetSprite()
{
	return sprite;
}

Rigidbody& Character::GetRigidbody()
{
	return rb;
}
