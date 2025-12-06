//
// Created by Dave Smith on 11/6/25.
//

#ifndef MOUSEHELPER_H
#define MOUSEHELPER_H
#include <SFML/Graphics.hpp>


class MouseHelper {

public:
    static bool isHovered(const sf::FloatRect& bounds,
        const sf::RenderWindow& window);
    static bool isClicked(const sf::FloatRect& bounds,
        const sf::RenderWindow& window);
};



#endif //MOUSEHELPER_H
