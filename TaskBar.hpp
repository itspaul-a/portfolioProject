#include <SFML/Graphics.hpp>

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

