#ifndef PONG_HPP
#define PONG_HPP

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include <sstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <optional>

class Pong
{
	sf::Music music;
	sf::Music smash;

public:
	Pong();

	void run();
	bool intersect(const sf::FloatRect& a, const sf::FloatRect& b) const;
};

#endif

