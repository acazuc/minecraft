#ifndef BLOCK_HPP
# define BLOCK_HPP

class Chunk;

class Block
{
	private:
		bool	isVisibleFace(int faceId);
		bool	isVisibleFacePart(int chunkX, int chunkZ, int blockX, int blockY, int blockZ);
		Chunk	*chunk;
		char	type;
		int		rX;
		int		rZ;
		long	x;
		long	y;
		long	z;

	public:
		Block(Chunk *chunk, long x, long y, long z, char type);
		bool	isTransparent();
		void	draw();
};

#endif
