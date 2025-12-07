#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Scoreboard
{
	sf::Font _font;
	sf::Text _scoreText;
	sf::Music music;
	int _scoreLeft;
	int _scoreRight;

public:
	Scoreboard();

	int addLeft();
	int addRight();
	int getScoreLeft();
	int getScoreRight();
	void setScoreText(std::string s);
	sf::Text getScoreText();
};

#endif

