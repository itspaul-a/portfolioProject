#include "Ball.hpp"

Ball::Ball(float radius, const sf::Vector2f& pos, float speed)
	: _speed(speed)
{
	setRadius(radius);
	setOrigin({radius, radius});
	setPosition(pos);
	setFillColor(sf::Color::Red);

	_velocity = { _speed, _speed};

	if(!music.openFromFile("8-bit2.mp3"))
	{
		std::cout << "error loading music" << std::endl;
	}
}

void Ball::update(float dt)
{
	move(_velocity * dt);
}

void Ball::bounceX()
{
	_velocity.x = -_velocity.x;
	music.play();
}

void Ball::bounceY()
{
	_velocity.y = -_velocity.y;
	music.play();
}

void Ball::resetPosition(const sf::Vector2f& pos)
{
	setPosition(pos);
	_velocity = {_speed * ((rand()%2) ? 1 : -1 ), _speed * ((rand()%2) ? 1 : -1)};
}

void Ball::setVelocity(const sf::Vector2f& vel)
{
	_velocity = vel;
}

sf::FloatRect Ball::getBounds() const 
{
	return getGlobalBounds();
}

sf::Vector2f Ball::getPosition() const 
{
	return sf::CircleShape::getPosition();
}

sf::Vector2f Ball::getVelocity() const 
{
	return _velocity;
}

