
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "Food.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 427), "Snake");
	Snake snake(window);
	Food food(window);
	sf::Clock clock;
	bool IsAPressed;
	bool IsSPressed;
	bool IsWPressed;
	bool IsDPressed;
	int time = 500;

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
			snake.UpdateState();
	//	bool shouldUpdate = snake.UpdateState();
		timer = clock.getElapsedTime();
		if (timer >= sf::milliseconds(time) /*|| shouldUpdate*/)
		{
			window.clear(sf::Color::White);
			snake.UpdateMovement();
			snake.UpdateCollision(food, window, time);

			snake.DrawSnake(window);
			food.DrawPart(window);
			window.display();
			clock.restart();
		}


		
	}
}


