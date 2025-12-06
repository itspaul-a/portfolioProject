//
// Created by Dave Smith on 11/5/25.
//

#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

enum FontType {OPEN_SANS, ARIAL, ROBOTO, HELVETICA};
class FontManager {
    inline static std::map<FontType, sf::Font> _fonts;

    static std::string getFilePath(FontType font);
    static void load(FontType font);

public:
    static sf::Font& get(FontType font);
};



#endif //FONTMANAGER_H
