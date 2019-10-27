#pragma once
#include<list>
#include <SFML/Graphics.hpp>

class SnakePart
{
public:

	void DrawPart(sf::RenderWindow& window);
	SnakePart(float, float);
	const int& count = Count;
	int PositionX;
	int PositionY;

private:
	int Count = 0;
};

SnakePart::SnakePart(float positionX, float positionY)
{
	this->PositionX = positionX;
	this->PositionY = positionY;
}
void SnakePart::DrawPart(sf::RenderWindow& window)
{
	sf::RectangleShape body(sf::Vector2f(25, 25));
	body.setFillColor(sf::Color::Green);
	body.setPosition(sf::Vector2f(PositionX, PositionY));
	window.draw(body);
}