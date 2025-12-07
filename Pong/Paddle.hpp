#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
	float _speed;
	float _direction;

public:
	Paddle(const sf::Vector2f& size, const sf::Vector2f& pos, float speed);

	void update(float dt, float windowHeight);
	void moveUp();
	void moveDown();
	void resetMovement();
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;
};

#endif

