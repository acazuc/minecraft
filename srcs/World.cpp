#include <SFML/OpenGL.hpp>
#include <vector>
#include "World.hpp"
#include "Chunk.hpp"
#include <iostream>

World::World()
{
	Chunk*	chunk = new Chunk(0, 0);
	chunks.push_back(chunk);
}

World::~World()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		delete (chunks[count]);
		count++;
	}
}

void	World::draw()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		chunks[count]->draw();
		count++;
	}
}

void	World::render()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		chunks[count]->render();
		count++;
	}
}
