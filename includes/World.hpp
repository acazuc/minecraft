#ifndef WORLD_HPP
# define WORLD_HPP

# include <vector>

class Chunk;
class Player;

class World
{
	private:
		std::vector<Chunk*> *chunks;
		Player				*player;

	public:
		World();
		~World();
		void				draw();
		void				render();
		std::vector<Chunk*>	*getChunks();
		Player				*getPlayer();
		Chunk				*getChunk(int x, int z);
};

#endif
