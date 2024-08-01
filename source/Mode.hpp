//
//  RunMode.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#pragma once

#include "Xpoint.hpp"
#include "OPoint.hpp"
#include "SoundManager.hpp"

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

class Mode
{
protected:
    std::vector<XPoint>& xPoints;
    std::vector<OPoint>& oPoints;
    
    std::string& board;
    
    SoundManager& soundManager;
    
    sf::RenderWindow& window;
    
public:
    
    Mode(std::vector<XPoint>&, std::vector<OPoint>&, std::string&, SoundManager&, sf::RenderWindow&);

    virtual void inIntersect(sf::Event&, std::vector<sf::RectangleShape>&);
    
    virtual void pollEvent(sf::Event&);
    
    virtual void update();
    
    virtual void draw();
    
    virtual ~Mode();
};
