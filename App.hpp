#include <SFML/Graphics.hpp>

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

