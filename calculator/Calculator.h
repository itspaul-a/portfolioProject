//
// Created by Dave Smith on 11/12/25.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Button.h"
#include "Grid.h"
#include "Screen.h"
#include "SFML/Graphics/Drawable.hpp"


class Calculator : public sf::Drawable{
    Screen _display;
    Grid<Button> _buttons;
    void initialization();
public:
    Calculator();
    void handleEvent(sf::RenderWindow&, std::optional<sf::Event> event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //CALCULATOR_H
