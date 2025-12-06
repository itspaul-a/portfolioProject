//
// Created by Dave Smith on 11/12/25.
//

#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include "PositionHelper.h"
#include "StateManager.h"
template <typename T>
class Grid : public sf::Drawable{
    int rows, cols;
    float spacing = 0.f;
    std::vector<T> _objects;

public:
    Grid();
    Grid(int rows, int cols);
    Grid(int rows, int cols, float spacing, const T& def);
    void add(const T& object);
    T& at(unsigned int index);
    int size() const;
    void handleEvent(sf::RenderWindow&, std::optional<sf::Event> event);
    void update();
    void draw(sf::RenderTarget& window,
        sf::RenderStates states) const override;
    void position(int rows, int cols, float spacing);
};

#include "Grid.cpp"

#endif //GRID_H
