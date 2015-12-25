#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.hpp"
#include "World.hpp"
#include "EventListener.hpp"
#include <iostream>

using namespace std;

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	sf::Window window(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Default, settings);
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	window.setVerticalSyncEnabled(true);

	// Activation de la lecture et de l'écriture dans le tampon de profondeur
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	// Mise en place d'une projection perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, 1.f, 1.f, 500.f);
	double count = 0;
	bool running = true;
	World	*world = new World();
	world->draw();
	while (running)
	{
		EventListener::checkEvents(window);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(-80.f, 0.f, -300.f);
		glRotatef(count * 5, 1.f, 0.f, 0.f);
		glRotatef(count * 3, 0.f, 1.f, 0.f);
		glRotatef(count * 9, 0.f, 0.f, 1.f);
		world->render();
		window.display();
		count += 0.05;
	}
	return (0);
}
