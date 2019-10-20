
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"

int main()
{
	Snake snake;
	sf::RenderWindow window(sf::VideoMode(600, 400), "Snake");


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
		window.clear(sf::Color::White);
		snake.DrawSnake(window);
		snake.Update();

		window.display();
	}
}


