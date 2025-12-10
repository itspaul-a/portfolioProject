#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

class TaskClock : public sf::RectangleShape 
{
	float width = 150;
	float height = 50;
	sf::Font font;
	std::unique_ptr<sf::Text> text;

public:
	TaskClock(sf::RenderWindow &window)
	{
		if(font.openFromFile("OpenSans-Regular.ttf"))
			std::cout << "error loading font";
		
		
		setFillColor(sf::Color(37, 99, 221));
		setSize({width, height});
		setOrigin({width/2, height/2});
		setPosition({window.getSize().x - width, window.getSize().y - height/2});
		
		text = std::make_unique<sf::Text>(font, "00:00", 22);
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
			<< std::setw(2) << localTime->tm_min
			<< " " << ampm;

		text->setString(oss.str());

	}
	

	void draw(sf::RenderWindow &window)
	{
		window.draw(*this);
		window.draw(*text);
	}
	
};

