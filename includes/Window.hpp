#include <SFML/Window.hpp>

class Window
{
	private:
		sf::Window	*window;

	public:
		Window(int width, int height, std::string name);
		sf::Window	*getWindow();
		int			getWidth();
		int			getHeight();
};
