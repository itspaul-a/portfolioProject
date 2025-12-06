//
// Created by Dave Smith on 11/12/25.
//

#include "Screen.h"

#include "FontManager.h"
#include "RPN.hpp"
#include <sstream>

Screen::Screen() : Screen(24.f)
{

}

Screen::Screen(unsigned int characterSize) : _text(FontManager::get(OPEN_SANS))
{
    _text.setCharacterSize(characterSize);
}

void Screen::handleEvent(sf::RenderWindow &window, std::optional<sf::Event> event)
{
    if (event->is<sf::Event::TextEntered>())
    {
        char c = event->getIf<sf::Event::TextEntered>()->unicode;
        std::string s = _text.getString();
        if (c == 8)
            s.pop_back();
        else
            s.push_back(c);
        _text.setString(s);
    }
}

void Screen::setPosition(sf::Vector2f position)
{
    _text.setPosition(position);
}

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_text);
}

void Screen::setString(const std::string &text)
{
    _text.setString(text);
}

std::string Screen::getString() const
{
    return _text.getString();
}


std::string Screen::calculate(std::string& expression)
{
	std::istringstream iss(expression);

	Postfix pf;
	RPN evaluator;
	iss >> pf;
	double a = evaluator.evaluate(pf);
	int answer = a;
	return std::to_string(answer);
}
