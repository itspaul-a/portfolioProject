#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "Perpetuus/Perpetuus.hpp"
#include "calculator/Calc.hpp"
#include "Pong/Pong.hpp"
#include "fourierEpicycleDrawing/EpicycleDrawing.hpp"
#include "bouncingBall/BouncingBall.hpp"
#include "TaskBar.hpp"
#include "StartButton.hpp"
#include "App.hpp"
#include "TaskClock.hpp"


class Portfolio
{

public:
	void run()
	{
	    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Portfolio");
	    window.setFramerateLimit(60);
	
		sf::Texture startBtnTexture;
		if(startBtnTexture.loadFromFile("startBtn.png"))
			std::cout << "error loading startBtn";
	
		sf::Texture mageTexture;
		if(mageTexture.loadFromFile("mage2.png"))
			std::cout << "error loading mage";
	
		sf::Texture sumTexture;
		if(sumTexture.loadFromFile("sum.png"))
			std::cout << "error loading sum";
	
		sf::Texture calcTexture;
		if(calcTexture.loadFromFile("calcIcon.png"))
			std::cout << "error loading calcIcon";
	
		sf::Texture pongTexture;
		if(pongTexture.loadFromFile("ping-pong.png"))
			std::cout << "error loading pongIcon";
	
		sf::Texture bounceTexture;
		if(bounceTexture.loadFromFile("cricket-ball.png"))
			std::cout << "error loading cricket-ball";
	    
	    taskBar taskbar(window);
	    StartButton button(window);
		button.setTexture(&startBtnTexture);
	
		TaskClock tClock(window);
		
		//this should be a vector
	    App app(window, 80, 100);
		app.setTexture(&mageTexture);
	    App app2(window, 80, 200);
		app2.setTexture(&calcTexture);
	    App app3(window, 80, 300);
		app3.setTexture(&pongTexture);
		app3.setSize({70,60});
		App app4(window, 80, 400);
		app4.setTexture(&sumTexture);
		App app5(window, 80, 500);
		app5.setTexture(&bounceTexture);
	
	    sf::Texture backgroundTexture;
	    if(!backgroundTexture.loadFromFile("background.png"))
	    {
	        std::cout << "error loading background";
	    }
	    sf::Sprite backgroundSprite(backgroundTexture);
	
	    sf::Vector2u windowSize = window.getSize();
	    float windowWidth = (float)windowSize.x;
	    float windowHeight = (float)windowSize.y;
	
	    sf::Vector2u textureSize = backgroundSprite.getTexture().getSize();
	    float textureWidth = (float)textureSize.x;
	    float textureHeight = (float)textureSize.y;
	
	    float scaleX = windowWidth / textureWidth;
	    float scaleY = windowHeight / textureHeight;
	
		Perpetuus game;
		Calc calculator;
		Pong pong;
		EpicycleDrawing epiDraw;
		BouncingBall bBall;
	
	
	
	    backgroundSprite.setScale({scaleX, scaleY});
	
	    while (window.isOpen())
	    {
	        while (const std::optional event = window.pollEvent())
	        {
	            if (event->is<sf::Event::Closed>()) window.close();
	
	            if (event->is<sf::Event::MouseButtonPressed>())
	            {
	                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	                
	                if (app.containsMouse(window, mousePos))
						game.run();
	
	                if (app2.containsMouse(window, mousePos))
						calculator.run();
	
	                if (app3.containsMouse(window, mousePos))
						pong.run();
	
					if(app4.containsMouse(window, mousePos))
						epiDraw.run();
	
					if(app5.containsMouse(window, mousePos))
						bBall.run();
	            }
	        }
	
	        window.clear(sf::Color::Green);
	        window.draw(backgroundSprite);
	        window.draw(taskbar);
	        window.draw(button);
	        window.draw(app);
	        window.draw(app2);
	        window.draw(app3);
			window.draw(app4);
			window.draw(app5);
			tClock.update();
			tClock.draw(window);
	        window.display();
	    }
	
	}
};
