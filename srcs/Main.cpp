#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "EventListener.hpp"
#include "Texture.hpp"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	sf::Window window(sf::VideoMode(1280, 720, 32), "acazuc's minecraft", sf::Style::Default, settings);
	glClearDepth(1.f);
	glClearColor(0.48f, 0.65f, 0.99f, 0.0f);
	window.setVerticalSyncEnabled(true);

	// Activation de la lecture et de l'écriture dans le tampon de profondeur
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Mise en place d'une projection perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, (float)window.getSize().x/(float)window.getSize().y, .01f, 500.f);
	double count = 0;
	bool running = true;
	window.setMouseCursorVisible(false);
	World	*world = new World();
	glEnable(GL_TEXTURE_2D);
	Texture texture("stone.png");
	texture.bind();
	world->draw();
	while (running)
	{
		EventListener::checkEvents(window);
		world->getPlayer()->rotation(&window);
		world->getPlayer()->move();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(world->getPlayer()->getRotationZ(), 0.f, 0.f, 1.f);
		glRotatef(world->getPlayer()->getRotationX(), 1.f, 0.f, 0.f);
		glRotatef(world->getPlayer()->getRotationY(), 0.f, 1.f, 0.f);
		glTranslatef(-world->getPlayer()->getPositionX()
			, -world->getPlayer()->getPositionY()
			, -world->getPlayer()->getPositionZ());
		world->render();
		window.display();
		count += 0.05;
	}
	return (0);
}