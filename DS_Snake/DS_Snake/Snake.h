#pragma once
#include <list>
#include<iostream>
#include "SnakePart.h"

enum Directions
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
	void Update();
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
	snake.push_back(SnakePart(100, 100));
	Count = 1;
	Offset = 10;
	currentDirection = Directions::right;
}

void Snake::Update()
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


	switch (currentDirection)
	{
	case Directions::up:
		snake.back().FPositionX = snake.front().FPositionY + Offset;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	case Directions::down:
		snake.back().FPositionX = snake.front().FPositionY - Offset;
		snake.push_back(snake.front());
		snake.pop_front();
		break;
	case Directions::right:
			snake.back().FPositionX = snake.front().FPositionX + Offset;
			snake.push_front(snake.back());
			snake.pop_back();
		break;
	case Directions::left:
		snake.back().FPositionX = snake.front().FPositionX - Offset;
		snake.push_back(snake.front());
		snake.pop_front();
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