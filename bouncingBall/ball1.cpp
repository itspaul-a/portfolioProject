#include "Ball1.hpp"

Ball1::Ball1(const sf::Vector2u& winSize) : windowSize(winSize)
{
    ball.setRadius(25.0f);
    ball.setFillColor(sf::Color::Red);

    speed = 20.0f;
    xMove = speed;
    yMove = speed;
    
	if (!music.openFromFile("boing.mp3"))
    {
        std::cerr << "Error loading music" << std::endl;
    }
}

void Ball1::bounce()
{

    if (ball.getPosition().x + ball.getRadius() * 2 > windowSize.x)
    {
        xMove = -speed;
        music.play();
    }
    else if (ball.getPosition().x < 0 + ball.getRadius())
    {
        xMove = speed;
        music.play();
    }
    else if (ball.getPosition().y + ball.getRadius() * 2 > windowSize.y)
    {
        yMove = -speed;
        music.play();
    }
    else if (ball.getPosition().y < 0 + ball.getRadius())
    {
        yMove = speed;
        music.play();
    }

    ball.move({ xMove, yMove });
}

void Ball1::draw(sf::RenderWindow& window)
{
    window.draw(ball);
}

