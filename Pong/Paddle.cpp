#include "Paddle.hpp"

Paddle::Paddle(const sf::Vector2f& size, const sf::Vector2f& pos, float speed)
	: _speed(speed), _direction(0)
{
	setSize(size);
	setOrigin({size.x / 2, size.y / 2});
	setPosition(pos);
	setFillColor(sf::Color::White);
}

void Paddle::update(float dt, float windowHeight)
{
	auto pos = getPosition();
	pos.y += _direction * _speed * dt;

	float halfHeight = getSize().y / 2;

	if(pos.y - halfHeight < 0) 
	{
		pos.y = halfHeight;
	}
	if(pos.y + halfHeight > windowHeight) 
	{
		pos.y = windowHeight - halfHeight;
	}

	setPosition(pos);
}

void Paddle::moveUp()
{
	_direction = -1;
}

void Paddle::moveDown()
{
	_direction = 1;
}

void Paddle::resetMovement()
{
	_direction = 0;
}

sf::FloatRect Paddle::getBounds() const 
{
	return getGlobalBounds();
}

sf::Vector2f Paddle::getPosition() const
{
	return sf::RectangleShape::getPosition();
}

