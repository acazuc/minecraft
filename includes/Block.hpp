#ifndef BLOCK_HPP
# define BLOCK_HPP

class Block
{
	private:
		char	type;
		long	x;
		long	y;
		long	z;

	public:
		Block(long x, long y, long z, char type);
		void	draw();
};

#endif
