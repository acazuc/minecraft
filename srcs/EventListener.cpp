#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>
#include "MouseButton.hpp"
#include "EventListener.hpp"

void	EventListener::checkEvents(sf::Window &window)
{
	sf::Event	event;

	while (window.pollEvent(event))
	{
		keyboardEvent(event);
		mouseEvent(event);
		wheelEvent(event);
	}
}

void	EventListener::keyboardEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		std::cout << "Key pressed: " << event.key.code << std::endl;
		if (event.key.code == sf::Keyboard::Escape)
		{
			exit(1);
		}
	}
	else if(event.type == sf::Event::KeyReleased)
	{
		std::cout << "Key released: " << event.key.code << std::endl;
	}
}

void	EventListener::mouseEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		MouseButton		button;
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "Left button pressed" << std::endl;
			button = LEFT;
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			std::cout << "Right button pressed" << std::endl;
			button = RIGHT;
		}
		else if (event.mouseButton.button == sf::Mouse::Middle)
		{
			std::cout << "Middle button pressed" << std::endl;
			button = MIDDLE;
		}
		else if (event.mouseButton.button == sf::Mouse::XButton1)
		{
			std::cout << "Prev button pressed" << std::endl;
			button = PREV;
		}
		else if (event.mouseButton.button == sf::Mouse::XButton2)
		{
			std::cout << "Next button pressed" << std::endl;
			button = NEXT;
		}

	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		MouseButton		button;
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "Left button released" << std::endl;
			button = LEFT;
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			std::cout << "Right button released" << std::endl;
			button = RIGHT;
		}
		else if (event.mouseButton.button == sf::Mouse::Middle)
		{
			std::cout << "Middle button released" << std::endl;
			button = MIDDLE;
		}
		else if (event.mouseButton.button == sf::Mouse::XButton1)
		{
			std::cout << "Prev button released" << std::endl;
			button = PREV;
		}
		else if (event.mouseButton.button == sf::Mouse::XButton2)
		{
			std::cout << "Next button released" << std::endl;
			button = NEXT;
		}
	}
	else if (event.type == sf::Event::MouseMoved)
	{
		int		mouseX = event.mouseMove.x;
		int		mouseY = event.mouseMove.y;
		std::cout << "Mouse x: " << mouseX << ", Mouse y: " << mouseY << std::endl;
	}
}

void	EventListener::wheelEvent(sf::Event event)
{
	if (event.type == sf::Event::MouseWheelMoved)
	{
		std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
	}
}
