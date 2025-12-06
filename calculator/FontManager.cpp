//
// Created by Dave Smith on 11/5/25.
//

#include "FontManager.h"

std::string FontManager::getFilePath(FontType font)
{
    switch (font)
    {
        case OPEN_SANS: return "OpenSans-Regular.ttf";

    }

}

void FontManager::load(FontType font)
{
    if (_fonts.count(font) < 1)
        if (!_fonts[font].openFromFile(getFilePath(font)))
            exit(28);
}

sf::Font & FontManager::get(FontType font)
{
    load(font);
    return _fonts.at(font);
}
