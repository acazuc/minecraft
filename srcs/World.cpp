#include <SFML/OpenGL.hpp>
#include <vector>
#include "Player.hpp"
#include "World.hpp"
#include "Chunk.hpp"

World::World()
{
	chunks = new std::vector<Chunk*>();
	Chunk	*chunk = new Chunk(this, 0, 0);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 16, 0);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 32, 0);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 32, 16);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 0, 16);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 0, 32);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 16, 32);
	chunks->push_back(chunk);
	chunk = new Chunk(this, 32, 32);
	chunks->push_back(chunk);
	this->player = new Player(this);
}

World::~World()
{
	unsigned int	count;

	count = 0;
	while (count < this->chunks->size())
	{
		delete ((*this->chunks)[count]);
		count++;
	}
	delete (chunks);
}

void	World::draw()
{
	unsigned int	count;

	count = 0;
	while (count < this->chunks->size())
	{
		(*this->chunks)[count]->draw();
		count++;
	}
}

void	World::render()
{
	unsigned int	count;

	count = 0;
	while (count < chunks->size())
	{
		(*this->chunks)[count]->render();
		count++;
	}
}

std::vector<Chunk*>	*World::getChunks()
{
	return (this->chunks);
}

Player	*World::getPlayer()
{
	return (this->player);
}

Chunk	*World::getChunk(int x, int z)
{
	unsigned int	count;

	count = 0;
	while (count < this->chunks->size())
	{
		if ((*this->chunks)[count]->getX() == x
			&& (*this->chunks)[count]->getZ() == z)
		{
			return ((*this->chunks)[count]);
		}
		count++;
	}
	return (NULL);
}
