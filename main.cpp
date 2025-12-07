#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>
#include "Perpetuus/Perpetuus.hpp"
#include "calculator/Calc.hpp"
#include "Pong/Pong.hpp"

class taskBar : public sf::RectangleShape 
{
    float width = 800;
    float height = 50;

public:
    taskBar(sf::RenderWindow& window)
    {
        setFillColor(sf::Color::Blue);
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
        setFillColor(sf::Color::Green);
        setSize({width, height});
        setOrigin({width/2, height/2});
        setPosition({width/2, window.getSize().y - height/2});
    }

    bool containsMouse(sf::RenderWindow& window, sf::Vector2i mousePos)
    {
        return getGlobalBounds().contains((sf::Vector2f)mousePos);
    }
};

class App : public sf::RectangleShape
{
    float width = 40;
    float height = 40;

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
    
    taskBar taskbar(window);
    Pbutton button(window);

    App app(window, 80, 100);
    App app2(window, 80, 200);
    App app3(window, 80, 300);

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
            }
        }

        window.clear(sf::Color::Green);
        window.draw(backgroundSprite);
        window.draw(taskbar);
        window.draw(button);
        window.draw(app);
        window.draw(app2);
        window.draw(app3);
        window.display();
    }

    return 0;
}

