#include <SFML/OpenGL.hpp>
#include <stdlib.h>
#include <iostream>
#include "Chunk.hpp"
#include "Block.hpp"
#include "World.hpp"

Chunk::Chunk(World *world, int x, int z)
{
	unsigned int	x_count;
	unsigned int	y_count;
	unsigned int	z_count;
	char			type;

	this->world = world;
	this->x = x;
	this->z = z;
	this->blocks = new Block***[Chunk::WIDTH];
	x_count = 0;
	while (x_count < Chunk::WIDTH)
	{
		this->blocks[x_count] = new Block**[Chunk::HEIGHT];
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			this->blocks[x_count][y_count] = new Block*[Chunk::WIDTH];
			z_count = 0;
			while (z_count < Chunk::WIDTH)
			{
				type = 0;
				if (y_count == 0)
					type = 7;
				if (y_count < 10)
					type = 1;
				else if (y_count < 13)
					type = 3;
				else if (y_count == 13)
					type = 2;
				this->blocks[x_count][y_count][z_count] = new Block(this, x + x_count, y_count, z + z_count, type);
				z_count++;
			}
			y_count++;
		}
		x_count++;
	}
	this->glList = 0;
}

Chunk::~Chunk()
{
	unsigned int	x_count;
	unsigned int	y_count;
	unsigned int	z_count;

	x_count = 0;
	while (x_count < Chunk::WIDTH)
	{
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			z_count = 0;
			while (z_count < Chunk::WIDTH)
			{
				delete (this->blocks[x_count][y_count][z_count]);
				z_count++;
			}
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
	while (x_count < Chunk::WIDTH)
	{
		y_count = 0;
		while (y_count < Chunk::HEIGHT)
		{
			z_count = 0;
			while (z_count < Chunk::WIDTH)
			{
				this->blocks[x_count][y_count][z_count]->draw();
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
	if (this->glList != 0)
	{
		glCallList(this->glList);
	}
}

Block	****Chunk::getBlocks()
{
	return (this->blocks);
}

World	*Chunk::getWorld()
{
	return (this->world);
}

int		Chunk::getX()
{
	return (this->x);
}

int		Chunk::getZ()
{
	return (this->z);
}
