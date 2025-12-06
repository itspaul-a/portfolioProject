//
// Created by Dave Smith on 11/4/25.
//

#include "PositionHelper.h"

void PositionHelper::leftOf(const sf::FloatRect &bounds, sf::Shape &obj, float spacing)
{
    sf::FloatRect objBounds = obj.getGlobalBounds();
    obj.setPosition({bounds.position.x - objBounds.size.x - spacing,
                    bounds.position.y});
}

void PositionHelper::centerText(const sf::Shape &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.size.x / 2.0f, textRect.size.y / 2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().position.x,
                                center.y + text.getLocalBounds().position.y};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.position.x + tRect.size.x / 2, tRect.position.y + tRect.size.y / 2});
}

void PositionHelper::rightOf(const sf::FloatRect &bounds, sf::Shape &obj, float spacing)
{
    obj.setPosition({bounds.position.x + bounds.size. x + spacing, bounds.position.y});
}

void PositionHelper::below(const sf::FloatRect &bounds, sf::Shape &obj, float spacing)
{
    obj.setPosition({bounds.position.x, bounds.position.y + bounds.size.y + spacing});
}

void PositionHelper::above(const sf::FloatRect &bounds, sf::Shape &obj, float spacing)
{
}

void PositionHelper::centerOf(const sf::FloatRect &bounds, sf::Shape &obj, float spacing)
{
}
