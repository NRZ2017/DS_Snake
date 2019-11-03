#pragma once
#include<list>
#include <SFML/Graphics.hpp>

class SnakePart
{
public:

	sf::RectangleShape body;
	void DrawPart(sf::RenderWindow& window);
	void UpdateHitbox();
	SnakePart(float, float);
	const int& count = Count;
	int PositionX;
	int PositionY;

	sf::FloatRect hitBox;
private:
	int Count = 0;
};

SnakePart::SnakePart(float positionX, float positionY)
{
	this->PositionX = positionX;
	this->PositionY = positionY;
	body = sf::RectangleShape(sf::Vector2f(25, 25));
	hitBox = body.getGlobalBounds();
}

void SnakePart::DrawPart(sf::RenderWindow& window)
{
	body.setFillColor(sf::Color::Green);
	body.setPosition(sf::Vector2f(PositionX, PositionY));
	window.draw(body);
}
 
void SnakePart::UpdateHitbox()
{
	hitBox.left = PositionX;
	hitBox.top = PositionY;
}