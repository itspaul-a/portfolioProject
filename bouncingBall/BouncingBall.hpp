#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball1.hpp"


class BouncingBall
{

public:

	void run()
	{
	    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Bouncing Ball");
	    window.setFramerateLimit(60);
	
	    Ball1 ball(window.getSize());
	
	    while (window.isOpen())
	    {
	        while (const std::optional event = window.pollEvent())
	        {
	            if (event->is<sf::Event::Closed>())
	                window.close();
	        }
	
	        ball.bounce();
	
	        window.clear(sf::Color::Black);
	        ball.draw(window);
	        window.display();
	    }
	}
};
