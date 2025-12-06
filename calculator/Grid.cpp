//
// Created by Dave Smith on 11/12/25.
//
#include "PositionHelper.h"
#ifndef GRID_CPP
#define GRID_CPP
#include "Grid.h"


#include <iostream>
template<typename T>
Grid<T>::Grid()
{
}
template<typename T>
Grid<T>::Grid(int rows, int cols) : rows(rows), cols(cols)
{
}
template<typename T>
Grid<T>::Grid(int rows, int cols, float spacing, const T &def)
    : _objects(rows * cols, def), rows(rows), cols(cols)
{
  // position(rows, cols, spacing);
}

template<typename T>
void Grid<T>::add(const T &object)
{
    _objects.push_back(object);
   // position(rows, cols, spacing);
}

template<typename T>
T& Grid<T>::at(unsigned int index)
{
    return _objects.at(index);
}

template<typename T>
int Grid<T>::size() const
{
    return _objects.size();
}

template<typename T>
void Grid<T>::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for (auto & o : _objects)
        window.draw(o);
}

template<typename T>
void Grid<T>::position(int rows, int cols, float spacing)
{
    //if (_objects.size() == rows * cols)
    {
        int j = 1;
        _objects.at(0).setPosition({100, 100});
        for (int i=0; i<rows; i++)
        {
            for (; j<cols; j++)
            {
                if ((i * cols + j) % cols == 0)
                {
                    T& prevObject = _objects.at((i-1)*cols + j);
                    T& object = _objects.at(i*cols + j);
                    sf::FloatRect f = prevObject.getGlobalBounds();
                    PositionHelper::below(f, object, spacing);
                    object.setPosition(object.getPosition());
                }
                else
                {
                    T& prevObject = _objects.at(i*cols + j -1);
                    T& object = _objects.at(i*cols + j);
                    sf::FloatRect f = prevObject.getGlobalBounds();
                    PositionHelper::rightOf(f, object, spacing);
                    object.setPosition(object.getPosition());
                }
            }
            j = 0;
        }
    }

}
template<typename T>
void Grid<T>::handleEvent(sf::RenderWindow& window, std::optional<sf::Event> event)
{
    for (auto &o : _objects)
    {
        o.handleEvent(window, event);
        if (o.getState(CLUCKED))
        {
            o.disableState(CLUCKED);
        }
    }

}
template<typename T>
void Grid<T>::update()
{
    for (auto& o : _objects)
        o.update();
}

#endif
