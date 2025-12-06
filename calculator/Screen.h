//
// Created by Dave Smith on 11/12/25.
//

#ifndef SCREEN_H
#define SCREEN_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "RPN.hpp"
class Screen  : public sf::Drawable{

    sf::Text _text;
public:
    Screen();
    Screen(unsigned int characterSize);
    void handleEvent(sf::RenderWindow& window, std::optional<sf::Event> event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f position);
    void setString(const std::string& text);
	std::string calculate(std::string& expression);

    std::string getString() const;
};



#endif //SCREEN_H
