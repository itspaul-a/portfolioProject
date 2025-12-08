#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "Perpetuus/Perpetuus.hpp"
#include "calculator/Calc.hpp"
#include "Pong/Pong.hpp"
#include "fourierEpicycleDrawing/EpicycleDrawing.hpp"

class taskBar : public sf::RectangleShape 
{
    float width = 800;
    float height = 50;

public:
    taskBar(sf::RenderWindow& window)
    {
        setFillColor(sf::Color(52,133,220));
        setSize({(float)window.getSize().x, 50});
        setOrigin({width/2, height/2});
        setPosition({width/2, window.getSize().y - height/2});
    }
};

class Pbutton : public sf::RectangleShape 
{
    float width = 100;
    float height = 50;

public:
    Pbutton(sf::RenderWindow& window)
    {
        setSize({width, height});
        setOrigin({width/2, height/2});
        setPosition({width/2, window.getSize().y - height/2});
    }
};

class TaskClock : public sf::RectangleShape 
{
	float width = 150;
	float height = 50;
	sf::Font font;
	std::unique_ptr<sf::Text> text;

public:
	TaskClock(sf::RenderWindow &window)
	{
		if(font.openFromFile("myFont2.ttf"))
			std::cout << "error loading font";
		
		
		setFillColor(sf::Color(37, 99, 221));
		setSize({width, height});
		setOrigin({width/2, height/2});
		setPosition({window.getSize().x - width, window.getSize().y - height/2});
		
		text = std::make_unique<sf::Text>(font, "00:00:00", 22);
		text->setCharacterSize(22);
		text->setFillColor(sf::Color::White);
		text->setPosition({getPosition().x - 40, getPosition().y - 15});

	}

	void update()
	{
		std::time_t now = std::time(nullptr);
		std::tm* localTime = std::localtime(&now);

		int hour = localTime->tm_hour;
		std::string ampm = "AM";

		if(hour >=12)
		{
			ampm = "PM";
			if(hour > 12)
			{
				hour -= 12;
			}
		}

		if(hour == 0)
		{
			hour = 12;
		}

		std::ostringstream oss;
		oss << std::setfill('0')
			<< std::setw(2) << hour << ":"
			<< std::setw(2) << localTime->tm_min << ":"
			<< std::setw(2) << localTime->tm_sec
			<< " " << ampm;

		text->setString(oss.str());

	}
	

	void draw(sf::RenderWindow &window)
	{
		window.draw(*this);
		window.draw(*text);
	}
	
};

class App : public sf::RectangleShape
{
    float width = 60;
    float height = 60;

public:
    App(sf::RenderWindow& window, float x, float y)
    {
        setFillColor(sf::Color::White);
        setSize({width, height});
        setOrigin({width/2, height/2});
        setPosition({x, y});
    }

    bool containsMouse(sf::RenderWindow& window, sf::Vector2i mousePos)
    {
        return getGlobalBounds().contains((sf::Vector2f)mousePos);
    }
};

int main()
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
    
    taskBar taskbar(window);
    Pbutton button(window);
	button.setTexture(&startBtnTexture);

	TaskClock tClock(window);
	
	//this should be a vector
    App app(window, 80, 100);
	app.setTexture(&mageTexture);
    App app2(window, 80, 200);
	app2.setTexture(&calcTexture);
    App app3(window, 80, 300);
	App app4(window, 80, 400);
	app4.setTexture(&sumTexture);

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
		tClock.update();
		tClock.draw(window);
        window.display();
    }

    return 0;
}

