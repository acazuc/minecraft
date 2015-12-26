#ifndef TEXTURE_HPP
# define TEXTURE_HPP

# include <iostream>

class Texture
{
	private:
		GLuint	textureID;
		int		width;
		int		height;
	
	public:
		Texture(std::string filename);
		~Texture();
		void	bind();
};

#endif
