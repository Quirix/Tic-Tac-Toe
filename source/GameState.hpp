//
//  GameState.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 27/6/24.
//

#pragma once

#include "constants.hpp"
#include "SoundManager.hpp"

#include <SFML/Graphics.hpp>

class Game {
public:
    sf::RenderWindow& window;
    
    GameState& currentGameState;
    const GameState assignedGameState;
    
    SoundManager& soundManager;
    
public:
    
    Game(sf::RenderWindow& win, GameState state, GameState& currentstate, SoundManager& sm)
    : window{win}, assignedGameState{state}, currentGameState{currentstate}, soundManager{sm} {}
    
    virtual void pollEvent(sf::Event&) = 0;
    
    virtual void update() = 0;
    virtual void draw() = 0;
    
    virtual ~Game() {};
    
};
