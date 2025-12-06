//
// Created by Dave Smith on 11/6/25.
//

#include "MouseHelper.h"

bool MouseHelper::isHovered(const sf::FloatRect &bounds, const sf::RenderWindow &window)
{
    auto mPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    return bounds.contains(mPos);
}

bool MouseHelper::isClicked(const sf::FloatRect &bounds, const sf::RenderWindow &window)
{
    return isHovered(bounds,window) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}
