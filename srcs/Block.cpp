#include <SFML/OpenGL.hpp>
#include "World.hpp"
#include "Block.hpp"
#include "Chunk.hpp"
#include <iostream>
#include <vector>

Block::Block(Chunk *chunk, long x, long y, long z, char type)
{
	this->chunk = chunk;
	this->type = type;
	this->rX = x - chunk->getX();
	this->rZ = z - chunk->getZ();
	this->x = x;
	this->y = y;
	this->z = z;
}

bool	Block::isVisibleFace(int faceId)
{
	if (faceId == 1) //Front
	{
		if (this->rZ == 0)
			return (isVisibleFacePart(this->chunk->getX(), this->chunk->getZ() - Chunk::WIDTH, this->rX, this->y, Chunk::WIDTH - 1));
		return (this->chunk->getBlocks()[this->rX][this->y][this->rZ - 1]->isTransparent());
	}
	else if (faceId == 2) //Back
	{
		if (this->rZ == Chunk::WIDTH - 1)
			return (isVisibleFacePart(this->chunk->getX(), this->chunk->getZ() + Chunk::WIDTH, this->rX, this->y, 0));
		return (this->chunk->getBlocks()[this->rX][this->y][this->rZ + 1]->isTransparent());
	}
	else if (faceId == 3) //Left
	{
		if (this->rX == 0)
			return (isVisibleFacePart(this->chunk->getX() - Chunk::WIDTH, this->chunk->getZ(), Chunk::WIDTH - 1, this->y, this->rZ));
		return (this->chunk->getBlocks()[this->rX - 1][this->y][this->rZ]->isTransparent());
	}
	else if (faceId == 4) //Right
	{
		if (this->rX == Chunk::WIDTH - 1)
			return (isVisibleFacePart(this->chunk->getX() + Chunk::WIDTH, this->chunk->getZ(), 0, this->y, this->rZ));
		return (this->chunk->getBlocks()[this->rX + 1][this->y][this->rZ]->isTransparent());
	}
	else if (faceId == 5) //Bottom
	{
		if (this->y == 0)
			return (true);
		return (this->chunk->getBlocks()[this->rX][this->y - 1][this->rZ]->isTransparent());
	}
	else if (faceId == 6) //Top
	{
		if (this->y == Chunk::HEIGHT - 1)
			return (true);
		return (this->chunk->getBlocks()[this->rX][this->y + 1][this->rZ]->isTransparent());
	}
	return (true);
}

bool	Block::isVisibleFacePart(int chunkX, int chunkZ, int blockX, int blockY, int blockZ)
{
	std::vector<Chunk*>	*chunks;
	unsigned int		count;

	chunks = this->chunk->getWorld()->getChunks();
	count = 0;
	while (count < chunks->size())
	{
		if ((*chunks)[count]->getX() == chunkX && (*chunks)[count]->getZ() == chunkZ)
		{
			return ((*chunks)[count]->getBlocks()[blockX][blockY][blockZ]->isTransparent());
		}
		count++;
	}
	return (true);
}

bool	Block::isTransparent()
{
	return (!this->type);
}

void	Block::draw()
{
	if (!this->type)
		return ;
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	if (isVisibleFace(1))
	{
		glTexCoord2f(0, 0);
		glVertex3f(x-.5f, y-.5f, z-.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x-.5f, y+.5f, z-.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x+.5f, y+.5f, z-.5f);
		glTexCoord2f(1, 0);
		glVertex3f(x+.5f, y-.5f, z-.5f);
	}
	if (isVisibleFace(2))
	{
		glTexCoord2f(1, 0);
		glVertex3f(x-.5f, y-.5f, z+.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x-.5f, y+.5f, z+.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x+.5f, y+.5f, z+.5f);
		glTexCoord2f(0, 0);
		glVertex3f(x+.5f, y-.5f, z+.5f);
	}
	if (isVisibleFace(3))
	{
		glTexCoord2f(1, 0);
		glVertex3f(x-.5f, y-.5f, z-.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x-.5f, y+.5f, z-.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x-.5f, y+.5f, z+.5f);
		glTexCoord2f(0, 0);
		glVertex3f(x-.5f, y-.5f, z+.5f);
	}
	if (isVisibleFace(4))
	{
		glTexCoord2f(0, 0);
		glVertex3f(x+.5f, y-.5f, z-.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x+.5f, y+.5f, z-.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x+.5f, y+.5f, z+.5f);
		glTexCoord2f(1, 0);
		glVertex3f(x+.5f, y-.5f, z+.5f);
	}
	if (isVisibleFace(5))
	{
		glTexCoord2f(0, 0);
		glVertex3f(x-.5f, y-.5f, z+.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x-.5f, y-.5f, z-.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x+.5f, y-.5f, z-.5f);
		glTexCoord2f(1, 0);
		glVertex3f(x+.5f, y-.5f, z+.5f);
	}
	if (isVisibleFace(6))
	{
		glTexCoord2f(0, 0);
		glVertex3f(x-.5f, y+.5f, z+.5f);
		glTexCoord2f(0, 1);
		glVertex3f(x-.5f, y+.5f, z-.5f);
		glTexCoord2f(1, 1);
		glVertex3f(x+.5f, y+.5f, z-.5f);
		glTexCoord2f(1, 0);
		glVertex3f(x+.5f, y+.5f, z+.5f);
	}
	glEnd();
}
