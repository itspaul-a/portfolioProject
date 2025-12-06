#include <iostream>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "FontManager.h"
#include "PositionHelper.h"
#include <vector>

#include "Calculator.h"
#include "Grid.h"


class Calc 
{
public:
	void run()
	{
	    sf::RenderWindow window(
	        sf::VideoMode({480, 720},32),
	        "Calculator");
	    window.setFramerateLimit(60);
	    Calculator calculator;
	
	    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	    {
	        while (const std::optional event = window.pollEvent())
	        {
	            if (event->is<sf::Event::Closed>())
	                window.close();
	            calculator.handleEvent(window, event);
	        }
	
	        calculator.update();
	        window.clear();
	        window.draw(calculator);
	        window.display();
	    }
	}
};
