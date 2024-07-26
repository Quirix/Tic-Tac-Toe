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
#include "GameState.hpp"
#include "LoseWinDrawScreen.hpp"
#include "Mode.hpp"
#include "NormalMode.hpp"
#include "AIMode.hpp"

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameRun : public Game {
private:
    std::vector<sf::RectangleShape> boardRectangles;
    std::vector<XPoint> xPoints;
    std::vector<OPoint> oPoints;
    
    std::string strBoard;
    
    char turn = 'x';
    
    LWD* lwd = nullptr;
    
    void reset();
    
    void changePointsOfWin();
    
    Mode* mode = nullptr;
    char modechar;
    
public:
    
    
public:
    
    GameRun(sf::RenderWindow&, GameState&, SoundManager&);
    GameRun(sf::RenderWindow&, GameState&, SoundManager&, char, int);
    
    void pollEvent(sf::Event&);
    
    void update();
    void draw();
    
    
    virtual ~GameRun();
};
