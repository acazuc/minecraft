#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Window.hpp"
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
	while (running)
	{
		EventListener::checkEvents(window);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.f, 0.f, -200.f);
		glRotatef(count * 5, 1.f, 0.f, 0.f);
		glRotatef(count * 3, 0.f, 1.f, 0.f);
		glRotatef(count * 9, 0.f, 0.f, 1.f);
		glBegin(GL_QUADS);

		glColor3f(1, 0, 0);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f( 50.f,  50.f, -50.f);
		glVertex3f( 50.f, -50.f, -50.f);

		glColor3f(0, 1, 0);
		glVertex3f(-50.f, -50.f, 50.f);
		glVertex3f(-50.f,  50.f, 50.f);
		glVertex3f( 50.f,  50.f, 50.f);
		glVertex3f( 50.f, -50.f, 50.f);

		glColor3f(0, 0, 1);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f(-50.f,  50.f,  50.f);
		glVertex3f(-50.f, -50.f,  50.f);

		glColor3f(1, 1, 0);
		glVertex3f(50.f, -50.f, -50.f);
		glVertex3f(50.f,  50.f, -50.f);
		glVertex3f(50.f,  50.f,  50.f);
		glVertex3f(50.f, -50.f,  50.f);

		glColor3f(1, 0, 1);
		glVertex3f(-50.f, -50.f,  50.f);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f( 50.f, -50.f, -50.f);
		glVertex3f( 50.f, -50.f,  50.f);

		glColor3f(0, 1, 1);
		glVertex3f(-50.f, 50.f,  50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f( 50.f, 50.f, -50.f);
		glVertex3f( 50.f, 50.f,  50.f);

		glEnd();
		window.display();
		count += 0.005;
	}
	return (0);
}
