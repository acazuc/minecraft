#include <SFML/Window.hpp>
#include <math.h>
#include "Player.hpp"
#include "World.hpp"
#include "Chunk.hpp"
#include "Block.hpp"

Player::Player(World *world)
{
	this->world = world;
	MOVEMENT_SPEED = 0.24f;
	this->positionX = -10;
	this->positionY = 5;
	this->positionZ = 0;
	this->rotationX = 0;
	this->rotationY = 0;
	this->rotationZ = 0;
}

void	Player::rotation(sf::Window *window)
{
	sf::Vector2i	*center;
	sf::Vector2i	delta;

	center = new sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2);
	delta = sf::Mouse::getPosition(*window) - *center;
	sf::Mouse::setPosition(*center, *window);
	delete (center);
	this->rotationY += delta.x / 5.;
	this->rotationX += delta.y / 5.;
	if (this->rotationY < 0)
		this->rotationY+= 360;
	else if (this->rotationY > 360)
		this->rotationY-= 360;
	if (this->rotationX > 90)
		this->rotationX = 90;
	else if (this->rotationX < -90)
		this->rotationX = -90;
}

void	Player::move()
{
	bool	keyLShift;
	bool	keySpace;
	bool	keyZ;
	bool	keyQ;
	bool	keyS;
	bool	keyD;

	keyLShift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	keySpace = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	keyZ = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
	keyQ = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	keyS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	keyD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (keyZ || keyQ || keyS || keyD)
	{
		moveXZ(keyZ, keyQ, keyS, keyD);
	}
	if (keyLShift || keySpace)
	{
		moveUpDown(keyLShift, keySpace);
	}
}

void	Player::moveXZ(bool keyZ, bool keyQ, bool keyS, bool keyD)
{
	double	angle;

	if (keyZ && keyS)
	{
		keyZ = false;
		keyS = false;
	}
	if (keyQ && keyD)
	{
		keyQ = false;
		keyD = false;
	}
	if (keyZ || keyQ || keyS || keyD)
	{
		angle = rotationY + getMovementAngle(keyZ, keyQ, keyS, keyD);
		this->positionX += this->MOVEMENT_SPEED*cos(angle/180.f*M_PI);
		this->positionZ += this->MOVEMENT_SPEED*sin(angle/180.f*M_PI);
	}
}

void	Player::moveUpDown(bool keyLShift, bool keySpace)
{
	float	addY;

	if (keyLShift && keySpace)
	{
		keyLShift = false;
		keySpace = false;
	}
	addY = 0;
	if (keyLShift)
		addY = -MOVEMENT_SPEED;
	else if (keySpace)
		addY = MOVEMENT_SPEED;
	if ((addY < 0 && checkCollisionDown(addY))
		|| (addY > 0 && checkCollisionUp(addY)))
		addY = 0;
	this->positionY += addY;
}

double	Player::getMovementAngle(bool keyZ, bool keyQ, bool keyS, bool keyD)
{
	if (keyZ && keyD && !keyQ && !keyS)
		return (-45);
	else if (keyZ && !keyD && keyQ && !keyS)
		return (-135);
	else if (keyZ && !keyD && !keyQ && !keyS)
		return (-90);
	else if (!keyZ && !keyD && keyQ && keyS)
		return (135);
	else if (!keyZ && keyD && !keyQ && keyS)
		return (45);
	else if (!keyZ && !keyD && !keyQ && keyS)
		return (90);
	else if (!keyZ && !keyD && keyQ && !keyS)
		return (180);
	else if (!keyZ && keyD && !keyQ && !keyS)
		return (0);
	return (0);
}

bool	Player::checkCollisionUp(float addY)
{
	bool	collide;

	collide = false;
	if (this->positionX - round(this->positionX) > 0) {
		collide = collide || checkCollideBlock(this->positionX + .2f, this->positionY + addY + .2f + .5f, this->positionZ);
	}
	else if (this->positionX - round(this->positionX) < 0) {
		collide = collide || checkCollideBlock(this->positionX - .2f, this->positionY + addY + .2f + .5f, this->positionZ);
	}
	if (this->positionZ - round(this->positionZ) > 0) {
		collide = collide || checkCollideBlock(this->positionX, this->positionY + addY + .2f + .5f, this->positionZ + .2f);
	}
	else if (this->positionZ - round(this->positionZ) < 0) {
		collide = collide || checkCollideBlock(this->positionX, this->positionY + addY + .2f + .5f, this->positionZ - .2f);
	}
	collide = collide || checkCollideBlock(this->positionX, this->positionY + addY + .2f + .5f, this->positionZ);
	if (collide) {
		this->positionY = round(this->positionY + addY + .2f) - .7f;
	}
	return (collide);
}

bool	Player::checkCollisionDown(float addY)
{
	bool	collide;

	collide = false;
	if (this->positionX - round(this->positionX) > 0) {
		collide = collide || checkCollideBlock(this->positionX + .2f, this->positionY + addY - 1.7f - .5f, this->positionZ);
	}
	else if (this->positionX - round(this->positionX) < 0) {
		collide = collide || checkCollideBlock(this->positionX - .2f, this->positionY + addY - 1.7f - .5f, this->positionZ);
	}
	if (this->positionZ - round(this->positionZ) > 0) {
		collide = collide || checkCollideBlock(this->positionX, this->positionY + addY - 1.7f - .5f, this->positionZ + .2f);
	}
	else if (this->positionZ - round(this->positionZ) < 0) {
		collide = collide || checkCollideBlock(this->positionX, this->positionY + addY - 1.7f - .5f, this->positionZ - .2f);
	}
	collide = collide || checkCollideBlock(this->positionX, this->positionY + addY - 1.7f - .5f, this->positionZ);
	if (collide) {
		this->positionY = round(this->positionY + addY - 1.7f) + 2.2f;
	}
	return (collide);
}

void	Player::checkCollisionX()
{

}

void	Player::checkCollisionZ()
{

}

bool	Player::checkCollideBlock(float x, float y, float z)
{
	Chunk	*chunk;
	Block	*block;
	int		chunkX;
	int		chunkZ;

	if (y >= 0 && y < Chunk::HEIGHT)
	{
		chunkX = floor(x / 16.) * 16.;
		chunkZ = floor(z / 16.) * 16.;
		if ((chunk = this->world->getChunk(chunkX, chunkZ)))
		{
			if ((block = chunk->getBlocks()[(int)(x - chunkX)][(int)(y)][(int)(z - chunkZ)]))
			{
				return (block->isSolid());
			}
		}
	}
	return (false);
}

double	Player::getPositionX() const
{
	return (this->positionX);
}

double	Player::getPositionY() const
{
	return (this->positionY);
}

double	Player::getPositionZ() const
{
	return (this->positionZ);
}

double	Player::getRotationX() const
{
	return (this->rotationX);
}

double	Player::getRotationY() const
{
	return (this->rotationY);
}

double	Player::getRotationZ() const
{
	return (this->rotationZ);
}
