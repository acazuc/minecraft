#ifndef CHUNK_HPP
# define CHUNK_HPP

class World;
class Block;

class Chunk
{
	private:
		World	*world;
		Block	****blocks;
		int		glList;
		int		x;
		int		z;

	public:
		Chunk(World *world, int x, int z);
		~Chunk();
		void	draw();
		void	render();
		Block	****getBlocks();
		World	*getWorld();
		int		getX();
		int		getZ();
		static const int	WIDTH = 16;
		static const int	HEIGHT = 128;
};

#endif
