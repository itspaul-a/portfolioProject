#include <SFML/Graphics.hpp>

class Circle : public sf::CircleShape 
{
public:
    Circle(float radius, float X, float Y) 
	{
        setRadius(radius);
        setFillColor(sf::Color::Transparent);
        setOutlineColor(sf::Color::White);
        setOutlineThickness(1);
        setOrigin({radius, radius});
        setPosition({X, Y});
    }
};

