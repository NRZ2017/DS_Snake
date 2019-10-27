
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"

int main()
{
	Snake snake;
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(600, 400), "Snake");

	sf::Time timer;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		snake.UpdateState();

		timer = clock.getElapsedTime();
		if (timer >= sf::milliseconds(500) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			window.clear(sf::Color::White);
			snake.DrawSnake(window);
			snake.UpdateMovement();

			window.display();
			clock.restart();
		}
	}
}


