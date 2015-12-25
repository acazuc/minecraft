#ifndef WORLD_HPP
# define WORLD_HPP

# include <vector>
# include "Chunk.hpp"

class World
{
	private:
		std::vector<Chunk*> chunks;

	public:
		World();
		~World();
		void	draw();
		void	render();
};

#endif
