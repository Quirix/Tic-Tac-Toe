//
//  NormalMode.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#pragma once

#include "Mode.hpp"

class NormalMode : public Mode
{
public:
    char turn = 'x';
    
public:
    
    NormalMode(std::vector<XPoint>&, std::vector<OPoint>&, std::string&, SoundManager&, sf::RenderWindow&);
    
    void inIntersect(sf::Event&, std::vector<sf::RectangleShape>&) override;
    
    void pollEvent(sf::Event&) override;
    
    void update() override;
    
    void draw() override;
    
};
