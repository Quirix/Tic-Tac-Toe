//
//  Game.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#pragma once

#include "constants.hpp"
#include "Xpoint.hpp"
#include "OPoint.hpp"

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class Game {
private:
    std::vector<sf::RectangleShape> boardRectangles;
    std::vector<XPoint> xPoints;
    std::vector<OPoint> oPoints;
    
    std::string strBoard;
    
    char turn = 'x';
    
public:
    sf::RenderWindow window;
    
    GameState state;
    
public:
    
    Game();
    
    void pollEvent(sf::Event&);
    
    void update();
    void draw();
    
    
    virtual ~Game();
};
