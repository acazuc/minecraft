#ifndef CHUNK_HPP
# define CHUNK_HPP

# include "Block.hpp"

class Chunk
{
	private:
		Block	****blocks;
		int		glList;

	public:
		Chunk(int x, int z);
		~Chunk();
		void	draw();
		void	render();
		static const int	WIDTH = 160;
		static const int	HEIGHT = 1280;
};

#endif
