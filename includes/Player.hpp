#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <SFML/Window.hpp>

class World;
class Chunk;

class Player
{
	private:
		World	*world;
		float	MOVEMENT_SPEED;
		double	positionX;
		double	positionY;
		double	positionZ;
		double	rotationX;
		double	rotationY;
		double	rotationZ;

	public:
		Player(World *world);
		void	rotation(sf::Window *window);
		void	move();
		void	moveXZ(bool keyZ, bool keyQ, bool keyS, bool keyD);
		void	moveUpDown(bool keyLShift, bool keySpace);
		double	getMovementAngle(bool keyZ, bool keyQ, bool keyS, bool keyD);
		void	checkCollision();
		bool	checkCollisionUp(float addY);
		bool	checkCollisionDown(float addY);
		void	checkCollisionX();
		void	checkCollisionZ();
		bool	checkCollideBlock(float x, float y, float z);
		double	getPositionX() const;
		double	getPositionY() const;
		double	getPositionZ() const;
		double	getRotationX() const;
		double	getRotationY() const;
		double	getRotationZ() const;
};

#endif
