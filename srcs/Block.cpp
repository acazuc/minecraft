#include <SFML/OpenGL.hpp>
#include "Block.hpp"
#include <iostream>

Block::Block(long x, long y, long z, char type)
{
	this->type = type;
	this->x = x;
	this->y = y;
	this->z = z;
}

void	Block::draw()
{
	if (!this->type)
		return ;
	glBegin(GL_QUADS);

	glColor3f(1, 0, 0);
	glVertex3f(x-.5f, y-.5f, z-.5f);
	glVertex3f(x-.5f, y+.5f, z-.5f);
	glVertex3f(x+.5f, y+.5f, z-.5f);
	glVertex3f(x+.5f, y-.5f, z-.5f);

	glColor3f(0, 1, 0);
	glVertex3f(x-.5f, y-.5f, z+.5f);
	glVertex3f(x-.5f, y+.5f, z+.5f);
	glVertex3f(x+.5f, y+.5f, z+.5f);
	glVertex3f(x+.5f, y-.5f, z+.5f);

	glColor3f(0, 0, 1);
	glVertex3f(x-.5f, y-.5f, z-.5f);
	glVertex3f(x-.5f, y+.5f, z-.5f);
	glVertex3f(x-.5f, y+.5f, z+.5f);
	glVertex3f(x-.5f, y-.5f, z+.5f);

	glColor3f(1, 1, 0);
	glVertex3f(x+.5f, y-.5f, z-.5f);
	glVertex3f(x+.5f, y+.5f, z-.5f);
	glVertex3f(x+.5f, y+.5f, z+.5f);
	glVertex3f(x+.5f, y-.5f, z+.5f);

	glColor3f(1, 0, 1);
	glVertex3f(x-.5f, y-.5f, z+.5f);
	glVertex3f(x-.5f, y-.5f, z-.5f);
	glVertex3f(x+.5f, y-.5f, z-.5f);
	glVertex3f(x+.5f, y-.5f, z+.5f);

	glColor3f(0, 1, 1);
	glVertex3f(x-.5f, y+.5f, z+.5f);
	glVertex3f(x-.5f, y+.5f, z-.5f);
	glVertex3f(x+.5f, y+.5f, z-.5f);
	glVertex3f(x+.5f, y+.5f, z+.5f);

	glEnd();
}
