#include <SFML/Window.hpp>
#include <math.h>
#include "Player.hpp"

Player::Player()
{
	MOVEMENT_SPEED = 0.24f;
	positionX = 0;
	positionY = 0;
	positionZ = 0;
	rotationX = 0;
	rotationY = 0;
	rotationZ = 0;
}

void	Player::rotation(sf::Window *window)
{
	sf::Vector2i	*center;
	sf::Vector2i	delta;

	center = new sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2);
	delta = sf::Mouse::getPosition(*window) - *center;
	sf::Mouse::setPosition(*center, *window);
	delete (center);
	this->rotationY += delta.x;
	this->rotationX += delta.y;
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
	double	angle;
	bool	keyZ;
	bool	keyQ;
	bool	keyS;
	bool	keyD;

	keyZ = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
	keyQ = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
	keyS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	keyD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (keyZ || keyQ || keyS || keyD)
	{
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
			angle = rotationY;
			if (keyZ && keyD && !keyQ && !keyS)
				angle -= 45;
			else if (keyZ && !keyD && keyQ && !keyS)
				angle -= 135;
			else if (keyZ && !keyD && !keyQ && !keyS)
				angle -= 90;
			else if (!keyZ && !keyD && keyQ && keyS)
				angle += 135;
			else if (!keyZ && keyD && !keyQ && keyS)
				angle += 45;
			else if (!keyZ && !keyD && !keyQ && keyS)
				angle += 90;
			else if (!keyZ && !keyD && keyQ && !keyS)
				angle += 180;
			else if (!keyZ && keyD && !keyQ && !keyS)
				angle += 0;
			this->positionX += this->MOVEMENT_SPEED*cos(angle/180.f*M_PI);
			this->positionZ += this->MOVEMENT_SPEED*sin(angle/180.f*M_PI);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		this->positionY -= MOVEMENT_SPEED;
	}
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->positionY += MOVEMENT_SPEED;
	}
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
