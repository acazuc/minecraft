#include <SFML/OpenGL.hpp>
#include <vector>
#include "World.hpp"
#include "Chunk.hpp"
#include <iostream>

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
