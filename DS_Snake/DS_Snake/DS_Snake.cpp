
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "Food.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 427), "Snake");
	Snake snake(window);
	Food food(window);
	int ScoreCount{};
	sf::Clock clock;
	sf::Font font;
	if (!font.loadFromFile("BebasNeue-Regular.ttf")); {}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Black);

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			IsDPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			IsSPressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			IsWPressed = true;
		}

			snake.UpdateState();
	//	bool shouldUpdate = snake.UpdateState();
		timer = clock.getElapsedTime();
		if (timer >= sf::milliseconds(time) /*|| shouldUpdate*/)
		{
			text.setString("Score: " + std::to_string(ScoreCount));
			window.clear(sf::Color::White);
			snake.UpdateMovement();
			ScoreCount = snake.UpdateCollision(food, window, time, ScoreCount);
			
			snake.DrawSnake(window);
			food.DrawPart(window);

			window.draw(text);
			window.display();
			clock.restart();
		}


		
	}
}


