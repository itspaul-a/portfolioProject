//
// Created by Dave Smith on 11/12/25.
//

#include "Calculator.h"
#include "FontManager.h"
#include <iostream>
#include <string>

struct data
{
    std::string key;
    std::function<void(Button& button)> function;
};
Calculator::Calculator() : _buttons(), _display()
{
    initialization();
}
void Calculator::initialization()
{

    auto number = [this](Button& button)
    {
		sf::Color grey(200,200,200);
        button.setFillColor(grey);
        auto s = _display.getString();
        s.push_back(button.getString()[0]);
        _display.setString(s);
        button.disableState(CLICKED);
        return;
    };


	auto Hovered = [this](Button& button)
    {

		sf::Color orange(255,149,0);
		sf::Color grey(150,150,150);
        button.setFillColor(sf::Color(212,212,210));
        //button.disableState(HOVERED);

		char c = button.getString()[0];
		if(c == '+' || c == '-' || c == 'x' || c == '/' || c == '=')
		{
			button.setFillColor(orange);
		}
		
		if(button.getString()[0] == '+' && button.getString()[1] == '/')
		{
			button.setFillColor(sf::Color(212,212,210));
		}

        return;
    };

	auto unHovered = [this](Button& button)
    {
	
		sf::Color orange(255,149,0);
		sf::Color grey(150,150,150);
        button.setFillColor(grey);
		char c = button.getString()[0];

		if(c == '+' || c == '-' || c == 'x' || c == '/' || c == '=')
		{
			button.setFillColor(orange);
		}

		if(button.getString()[0] == '+' && button.getString()[1] == '/')

		{
			button.setFillColor(grey);
		}

        return;
    };


    std::vector<std::string> keys =
                        {"<-", "+/-", "%", "/",
                        "7", "8", "9", "x",
                        "4", "5", "6", "+",
                        "1", "2", "3", "-",
                        "c", "0", ".", "="};

    sf::Font& font = FontManager::get(OPEN_SANS);

    for (auto& k : keys)
    {
        Button one(25.f, k, font);
		if(k[0] == 'X')
		{
			one.setFillColor(sf::Color(255,149,0));
		}
		one.setOnHover(Hovered);
		one.setOnUnhover(unHovered);
	    _buttons.add(one);
        int last = _buttons.size() -  1;
        
		switch (k[0])
        {
            case '<':
                _buttons.at(last).setOnClick([this](Button& button)
                {
                    std::string text = _display.getString();
					if(text.empty())
					{
						_display.setString("");
					}
					else
					{
						text.pop_back();
                    	_display.setString(text);
					}
                    button.disableState(CLICKED);
                });
            break;
            case '+':
				_buttons.at(last).setOnClick([this](Button& button)
                {
					std::string text = _display.getString();
					text += '+';
					_display.setString(text);
					button.disableState(CLICKED);
                });
				break;
            case 'c':
                _buttons.at(last).setOnClick([this](Button& button)
                {
                    _display.setString("");
                    button.disableState(CLICKED);
                });

            break;

			case '=':
				 _buttons.at(last).setOnClick([this](Button& button)
                {
					std::string x = _display.getString();
					std::string a = _display.calculate(x);
					_display.setString(a);
					button.disableState(CLICKED);
				});
			break;

            default:
                _buttons.at(last).setOnClick(number);
        }

    }
    _buttons.position(5, 4, 10.f);

}
void Calculator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_display);
    target.draw(_buttons);
}

void Calculator::handleEvent(sf::RenderWindow & window, std::optional<sf::Event> event)
{
    _display.handleEvent(window, event);
    _buttons.handleEvent(window, event);
}

void Calculator::update()
{
    _buttons.update();
}
