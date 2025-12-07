#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Ball : public sf::CircleShape
{
	sf::Vector2f _velocity;
	float _speed;
	sf::Music music;

public:
	Ball(float radius, const sf::Vector2f& pos, float speed);

	void update(float dt);
	void bounceX();
	void bounceY();
	void resetPosition(const sf::Vector2f& pos);
	void setVelocity(const sf::Vector2f& vel);
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
};

#endif

