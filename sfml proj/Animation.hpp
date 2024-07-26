//
//  Animation.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 21/7/24.
//

#pragma once

#include "Button.hpp"

#include <vector>

class Animation {
private:
    std::vector<std::reference_wrapper<Button>> buttons;
    std::vector<std::reference_wrapper<sf::RectangleShape>> recs;
    std::vector<std::reference_wrapper<sf::Text>> texts;
    std::vector<std::string> typeAnim; //o=fadeout, i=fadein. || b,r,t || length(0,1,2,3,4)
    
    std::vector<double> values;
    std::vector<float> specialStop;
    
    sf::Color fadeout(int, const sf::Color&);
    sf::Color fadein(int, const sf::Color&);
    
    sf::Color correctFade(int, const sf::Color&, char);
    
    void eraseFromAllVectors(const std::string&, int, int);
    
public:
    void update();
    
    void putAnim(Button&, const std::string&, float s=-1);
    void putAnim(sf::RectangleShape&, const std::string&, float s=-1);
    void putAnim(sf::Text&, const std::string&, float s=-1);
    
    void clear();
    
};
