#ifndef CHUNK_HPP
# define CHUNK_HPP

class Block;

class Chunk
{
	private:
		Block	****blocks;
		int		glList;
		int		x;
		int		z;

	public:
		Chunk(int x, int z);
		~Chunk();
		void	draw();
		void	render();
		Block	****getBlocks();
		int		getX();
		int		getZ();
		static const int	WIDTH = 160;
		static const int	HEIGHT = 128;
};

#endif
