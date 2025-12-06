//
// Created by Dave Smith on 11/4/25.
//

#ifndef POSITIONHELPER_H
#define POSITIONHELPER_H

#include <SFML/Graphics.hpp>

class PositionHelper {

public:
    static void leftOf(const sf::FloatRect& bounds, sf::Shape& obj, float spacing = 0.f);
    static void rightOf(const sf::FloatRect& bounds, sf::Shape& obj, float spacing = 0.f);
    static void below(const sf::FloatRect& bounds, sf::Shape& obj, float spacing = 0.f);
    static void above(const sf::FloatRect& bounds, sf::Shape& obj, float spacing = 0.f);
    static void centerOf(const sf::FloatRect& bounds, sf::Shape& obj, float spacing = 0.f);
    static void centerText(const sf::Shape &obj, sf::Text &text);
};



#endif //POSITIONHELPER_H
