#include <SFML/OpenGL.hpp>
#include <vector>
#include "World.hpp"

World::World()
{
	chunks.push_back(new Chunk(0, 0));
}

World::~World()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		remove (chunks[count]);
		count++;
	}
}

void	World::draw()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		remove (chunks[count]);
		count++;
	}
}

void	World::render()
{
	unsigned int	count;

	count = 0;
	while (count < chunks.size())
	{
		remove (chunks[count]);
		count++;
	}
}
