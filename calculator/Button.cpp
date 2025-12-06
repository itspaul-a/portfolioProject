//
// Created by Dave Smith on 11/4/25.
//

#include "Button.h"

#include <iostream>

#include "FontManager.h"
#include "MouseHelper.h"
#include "PositionHelper.h"


void Button::setOnHover(std::function<void(Button& button)> f)
{
    onHover = f;
}

void Button::setOnClick(std::function<void(Button& button)> f)
{
    onClick = f;
}

void Button::setOnUnhover(std::function<void(Button& button)> f)
{
    onUnhover = f;
}

void Button::setOnUnclick(std::function<void(Button& button)> f)
{
    onUnclick = f;
}

Button::Button() : Button(25.f, "", FontManager::get(OPEN_SANS))
{
}

Button::Button(float radius, std::string text, sf::Font& font) : _text(font)
{
    setRadius(radius);
    _text.setString(text);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    PositionHelper::centerText(*this, _text);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    sf::CircleShape copy = *this;
    window.draw(copy, states);
    window.draw(_text, states);
}

void Button::setPosition(const sf::Vector2f &position)
{
    sf::CircleShape::setPosition(position); // call the parent setPosition
    PositionHelper::centerText(*this, _text);
}

void Button::handleEvent(const sf::RenderWindow &window, const std::optional<sf::Event> &event)
{
    setState(HOVERED, MouseHelper::isHovered(sf::CircleShape::getGlobalBounds(), window));
    if (MouseHelper::isClicked(sf::CircleShape::getGlobalBounds(), window))
       enableState(CLICKED);
}

void Button::update()
{
    if (getState(HOVERED))
    {
        if (onHover)
            onHover(*this);
    }
    else
    {
        if (onUnhover)
            onUnhover(*this);
    }

    if (getState(CLICKED))
    {
       if (onClick)
           onClick(*this);
    }
    else
        if (onUnclick)
            onUnclick(*this);

}

std::string Button::getString() const
{
    return _text.getString();
}
