#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Ball1
{
private:
    float speed,xMove,yMove;
    sf::CircleShape ball;
    sf::Vector2u windowSize;
	sf::Music music;

public:
    Ball1(const sf::Vector2u& winSize);

    void bounce();
    void draw(sf::RenderWindow& window);
};

