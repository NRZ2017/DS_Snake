#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "SnakePart.h"

class Food
{
public:
	sf::RectangleShape body;
	sf::FloatRect hitBox;
	Food(sf::RenderWindow& window); 
	Food();
	void DrawPart(sf::RenderWindow& window);
	void UpdateHitbox();
	void RandomPosition(sf::RenderWindow& window);


private:
	int genX;
	int genY;
};
Food::Food() : genX(0), genY(0)
{
}
Food::Food(sf::RenderWindow& window)
{
	srand(time(NULL));
	body = sf::RectangleShape(sf::Vector2f(15, 15));
	genX = rand() % window.getSize().x + 0;
	genY = rand() % window.getSize().y + 0;
	hitBox = body.getGlobalBounds();
}

void Food::UpdateHitbox()
{
	hitBox.left = genX;
	hitBox.top = genY;
}

void Food::RandomPosition(sf::RenderWindow& window)
{
	genX = rand() % window.getSize().x + 0;
	genY = rand() % window.getSize().y + 0;
}

void Food::DrawPart(sf::RenderWindow& window)
{
	body.setFillColor(sf::Color::Black);
	body.setPosition(genX, genY);
	window.draw(body);
	if (genX >= window.getSize().x || genY >= window.getSize().y)
	{
		RandomPosition(window);
		body.setPosition(genX, genY);
		window.draw(body);
	}
}
