#include <SFML/Window.hpp>
#include "Window.hpp"

Window::Window(int width, int height, std::string name)
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 8;
	window = new sf::Window(sf::VideoMode(width, height, 32), name, sf::Style::Default, settings);
}
