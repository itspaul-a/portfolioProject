#include <SFML/Graphics.hpp>

class Dot : public sf::CircleShape 
{
public:
    Dot(float radius, float X, float Y) 
	{
        setRadius(radius);
        setFillColor(sf::Color::Yellow);
        setOrigin({radius, radius});
        setPosition({X, Y});
    }
};

