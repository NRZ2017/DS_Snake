#pragma once
#include <list>
#include<iostream>
#include "SnakePart.h"

enum class Directions
{
	up,
	down,
	left,
	right,
};

class Snake
{
public:
	void DrawSnake(sf::RenderWindow& window);
	void UpdateMovement();
	void UpdateState();
	const int& count = Count;
	Snake();



private:
	std::list<SnakePart> snake;
	int Count = 0;
	int Offset;

	Directions currentDirection;

};

Snake::Snake()
{
	snake = std::list<SnakePart>();
	Count = 1;
	Offset = 27;
	currentDirection = Directions::right;
	snake.push_back(SnakePart(100, 100));
	snake.push_back(SnakePart(100 + Offset, 100));
}

void Snake::UpdateState()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		currentDirection = Directions::down;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		currentDirection = Directions::up;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		currentDirection = Directions::right;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		currentDirection = Directions::left;
	}

}

void Snake::UpdateMovement()
{


	switch (currentDirection)
	{
	case Directions::up:
		snake.back().PositionY = snake.front().PositionY - Offset;
		snake.back().PositionX = snake.front().PositionX;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	case Directions::down:
		snake.back().PositionY = snake.front().PositionY + Offset;
		snake.back().PositionX = snake.front().PositionX;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	case Directions::right:
		snake.back().PositionX = snake.front().PositionX + Offset;
		snake.back().PositionY = snake.front().PositionY;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	case Directions::left:
		snake.back().PositionX = snake.front().PositionX - Offset;
		snake.back().PositionY = snake.front().PositionY;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	}

}

void Snake::DrawSnake(sf::RenderWindow& window)
{
	for (auto i = snake.begin(); i != snake.end(); i++)
	{
		i->DrawPart(window);
	}

}