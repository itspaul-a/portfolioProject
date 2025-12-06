//
// Created by Dave Smith on 11/4/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include "StateManager.h"


class Button : public sf::CircleShape, public StateManager
{
public:
    void setOnHover(std::function<void(Button& button)> f);
    void setOnClick(std::function<void(Button& button)> f);
    void setOnUnhover(std::function<void(Button& button)> f);
    void setOnUnclick(std::function<void(Button& button)> f);

private:
    sf::Text _text;
    std::function<void(Button& button)> onHover;////Functors (pointers to functions)
    std::function<void(Button& button)> onClick;
    std::function<void(Button& button)> onUnhover;
    std::function<void(Button& button)> onUnclick;
public:
    Button();
    Button(float radius, std::string text, sf::Font& font);
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void handleEvent(const sf::RenderWindow& window,
        const std::optional<sf::Event> &event);
    void update();
    std::string getString() const;
};



#endif //BUTTON_H
