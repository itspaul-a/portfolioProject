#include <SFML/Graphics.hpp>

class StartButton : public sf::RectangleShape 
{
    float width = 200;
    float height = 100;

public:
    StartButton(sf::RenderWindow& window)
    {
        setSize({width, height});
        setOrigin({width/2, height/2});
        setPosition({width/2, window.getSize().y - 25.f});
    }
};

