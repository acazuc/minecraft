#include <SFML/Window.hpp>

class Window
{
	public:
		Window(int width, int height, std::string name);

	private:
		sf::Window* window;
};
