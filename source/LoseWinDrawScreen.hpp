//
//  LoseWinDrawScreen.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 30/6/24.
//

#pragma once

#include "Button.hpp"

#include <string>

#include <SFML/Graphics.hpp>

class LWD {
private:
    const float txtX=WinWidth/2;
    const float txtY=WinHeight-100;
    
    float transparency=0;
    
    sf::RenderWindow& window;
    
    char tttstate;
    
    Button replayButton;
    
    char returnActionBack = 'n';
    
public:
    
    LWD(char, sf::RenderWindow&);
    
    char getAction();
    
    void pollEvent(sf::Event&);
    
    void update();
    
    void draw(sf::RenderWindow&);
    
};
