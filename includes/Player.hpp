#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <SFML/Window.hpp>

class Player
{
	private:
		float	MOVEMENT_SPEED;
		double	positionX;
		double	positionY;
		double	positionZ;
		double	rotationX;
		double	rotationY;
		double	rotationZ;

	public:
		Player();
		void	rotation(sf::Window *window);
		void	move();
		double	getPositionX() const;
		double	getPositionY() const;
		double	getPositionZ() const;
		double	getRotationX() const;
		double	getRotationY() const;
		double	getRotationZ() const;
};

#endif
