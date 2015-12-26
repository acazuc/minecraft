#ifndef BLOCK_HPP
# define BLOCK_HPP

class Chunk;

class Block
{
	private:
		bool	isVisibleFace(int faceId);
		Chunk	*chunk;
		char	type;
		int		rX;
		int		rZ;
		long	x;
		long	y;
		long	z;

	public:
		Block(Chunk *chunk, long x, long y, long z, char type);
		void	draw();
};

#endif
