#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.hpp"

Window::Window(int width, int height, std::string name)
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 32;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	window = new sf::Window(sf::VideoMode(width, height, 32), name, sf::Style::Default, settings);
	glClearDepth(1.f);
	glClearColor(0.48f, 0.65f, 0.99f, 0.0f);
	window->setVerticalSyncEnabled(true);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, (float)getWidth()/(float)getHeight(), .01f, 500.f);
}

sf::Window	*Window::getWindow()
{
	return (this->window);
}

int		Window::getWidth()
{
	return (this->window->getSize().x);
}

int		Window::getHeight()
{
	return (this->window->getSize().y);
}
