#include "Scoreboard.hpp"

Scoreboard::Scoreboard() : _scoreText(_font, "0 : 0", 100), _scoreLeft(0), _scoreRight(0)
{
	if(!_font.openFromFile("myFont2.ttf"))
	{
		std::cout << "can't load font";
	}
	_scoreText.setString("0 : 0");
	_scoreText.setFillColor(sf::Color::White);
	//_scoreText.setPosition({800.f / 2 - 40, 10});
	_scoreText.setPosition({0, 10});
	if(!music.openFromFile("8-bit7.mp3"))
	{
		std::cout << "error loading boom" << std::endl;
	}
}

int Scoreboard::addLeft()
{
	music.play();
	return ++_scoreLeft;
}

int Scoreboard::addRight()
{
	music.play();
	return ++_scoreRight;
}

int Scoreboard::getScoreLeft()
{
	return _scoreLeft;
}

int Scoreboard::getScoreRight()
{
	return _scoreRight;
}

void Scoreboard::setScoreText(std::string s)
{
	_scoreText.setString(s);
}

sf::Text Scoreboard::getScoreText()
{
	return _scoreText;
}

