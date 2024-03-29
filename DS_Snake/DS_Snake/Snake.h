#pragma once
#include <list>
#include<iostream>
#include "SnakePart.h"
#include "Food.h"

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
	bool UpdateState();
	int UpdateCollision(Food& food, sf::RenderWindow& window, int& time, int score);
	const int& count = Count;
	Snake(sf::RenderWindow& window);
	Snake();


private:
	std::list<SnakePart> snake{};
	int Count{};
	int Offset{};
	sf::FloatRect windowHitbox{};
	Directions currentDirection{};

};

Snake::Snake() {}

Snake::Snake(sf::RenderWindow& window)
{
	snake = std::list<SnakePart>();
	Count = 1;
	Offset = 27;
	currentDirection = Directions::right;
	windowHitbox = sf::FloatRect(0, 0, window.getSize().x, window.getSize().y);
	snake.push_back(SnakePart(100, 100));
}

bool Snake::UpdateState()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		currentDirection = Directions::down;
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		currentDirection = Directions::up;
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		currentDirection = Directions::right;
		return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		currentDirection = Directions::left;
		return true;
	}
	return false;
}


void Snake::UpdateMovement()
{


	switch (currentDirection)
	{
	case Directions::up:
	{
		auto& backpart = snake.back();
		backpart.PositionY = snake.front().PositionY - Offset;
		backpart.PositionX = snake.front().PositionX;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	}
	case Directions::down:
	{
		snake.back().PositionY = snake.front().PositionY + Offset;
		snake.back().PositionX = snake.front().PositionX;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	}
	case Directions::right:
	{
		snake.back().PositionX = snake.front().PositionX + Offset;
		snake.back().PositionY = snake.front().PositionY;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	}
	case Directions::left:
	{
		snake.back().PositionX = snake.front().PositionX - Offset;
		snake.back().PositionY = snake.front().PositionY;
		snake.push_front(snake.back());
		snake.pop_back();
		break;
	}
	}

}

int Snake::UpdateCollision(Food& food, sf::RenderWindow& window, int& time, int score)
{
	snake.front().UpdateHitbox();
	food.UpdateHitbox();
	if (snake.front().hitBox.intersects(food.hitBox))
	{
		score++;
		food.RandomPosition(window);
		food.UpdateHitbox();
		snake.push_back(SnakePart(snake.back().PositionX, snake.back().PositionY));
		time -= 10;
	}
	if (snake.front().hitBox.left < windowHitbox.left - 27)
	{
		window.close();
	}
	if (snake.front().hitBox.left + snake.front().hitBox.width > windowHitbox.width + 27)
	{
		window.close();
	}
	if (snake.front().hitBox.top < windowHitbox.top - 27)
	{
		window.close();
	}
	if (snake.front().hitBox.top + snake.front().hitBox.height > windowHitbox.height + 27)
	{
		window.close();
	}
	for (auto i = snake.begin(); i != snake.end(); i++)
	{
		if (snake.begin() == i)
		{
			continue;
		}

		if (snake.front().hitBox.intersects(i->hitBox))
		{
			window.close();
		}
	}
	return score;
}

void Snake::DrawSnake(sf::RenderWindow& window)
{
	for (auto i = snake.begin(); i != snake.end(); i++)
	{
		i->DrawPart(window);
	}

}

