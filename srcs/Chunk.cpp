#include <SFML/OpenGL.hpp>
#include <stdlib.h>
#include "Chunk.hpp"

Chunk::Chunk(int x, int z)
{
	unsigned int	x_count;
	unsigned int	y_count;

	this->blocks = new int**[Chunk::WIDTH];
	x_count = 0;
	while (x_count < Chunk::WIDTH)
	{
		this->blocks[x_count] = new int*[Chunk::HEIGHT];
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			this->blocks[x_count][y_count] = new int[Chunk::WIDTH];
			y_count++;
		}
		x_count++;
	}
	this->blocks[x][0][z] = 1;
	this->glList = 0;
}

Chunk::~Chunk()
{
	unsigned int	x_count;
	unsigned int	y_count;

	x_count = 0;
	while (x_count < Chunk::WIDTH)
	{
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			delete (this->blocks[x_count][y_count]);
			y_count++;
		}
		delete (this->blocks[x_count]);
		x_count++;
	}
	delete (this->blocks);
}

void	Chunk::draw()
{
	unsigned int	x_count;
	unsigned int	y_count;
	unsigned int	z_count;

	if (this->glList == 0)
	{
		this->glList = glGenLists(1);
	}
	glNewList(this->glList, GL_COMPILE);
	x_count = 0;
	while (x_count > Chunk::WIDTH)
	{
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			z_count = 0;
			while (z_count < Chunk::WIDTH)
			{
				this->blocks[x_count][y_count][z_count] = 5;
				z_count++;
			}
			y_count++;
		}
		x_count++;
	}
	glEndList();
}

void	Chunk::render()
{
	glCallList(this->glList);
}
