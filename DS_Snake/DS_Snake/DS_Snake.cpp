
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "Food.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Snake");
	Snake snake;
	Food food(window);
	sf::Clock clock;
	bool IsAPressed;
	bool IsSPressed;
	bool IsWPressed;
	bool IsDPressed;

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			IsAPressed = true;
		}
		bool shouldUpdate = snake.UpdateState();
		timer = clock.getElapsedTime();
		if (timer >= sf::milliseconds(500) || shouldUpdate)
		{
			window.clear(sf::Color::White);
			snake.DrawSnake(window);
			food.DrawPart(window);
			snake.UpdateMovement();
			snake.UpdateCollision(food, window);

			window.display();
			clock.restart();
		}


		
	}
}


