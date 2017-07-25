#include "Sprite.h"

Sprite::Sprite() : Sprite("", 0, 0) {}

Sprite::Sprite(string imagePath) : Sprite(imagePath, 0, 0) {}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	xPos = _xPos;
	yPos = _yPos;
	rot = 0;
	speed = 5;
	texture = imagePath != "" ? Texture(imagePath) : Texture();
}

void Sprite::Update()
{
	
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// Translate -> Rotate -> Scale
	glTranslatef(xPos, yPos, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(xScale, yScale, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	glTexCoord2f(1, 0); glVertex2f(texture.GetWidth(), 0);
	glTexCoord2f(1, 1); glVertex2f(texture.GetWidth(), texture.GetHeight());
	glTexCoord2f(0, 1); glVertex2f(0., texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

void Sprite::MoveTo(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Sprite::MoveBy(float x, float y)
{
	xPos += x;
	yPos += y;
}

void Sprite::MoveLeft()
{
	xPos -= speed;
}

void Sprite::MoveRight()
{
	xPos += speed;
}

void Sprite::MoveUp()
{
	yPos += speed;
}

void Sprite::MoveDown()
{
	yPos -= speed;
}

void Sprite::SetRotTo(float r)
{
	rot = r;
}

void Sprite::SetRotBy(float r)
{
	rot += r;
}

/**
 * Scales both x and y equally.
 */
void Sprite::SetScale(float x)
{
	xScale = x;
	yScale = x;
}


void Sprite::SetScale(float x, float y)
{
	xScale = x;
	yScale = y;
}