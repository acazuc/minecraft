#ifndef CHUNK_HPP
# define CHUNK_HPP

class Chunk
{
	private:
		int		***blocks;
		int		glList;

	public:
		Chunk(int x, int z);
		~Chunk();
		void	draw();
		void	render();
		static const int	WIDTH = 32;
		static const int	HEIGHT = 32;
};

#endif
