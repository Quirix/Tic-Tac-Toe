//
//  AIMode.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#pragma once

#include "VirtualBoard.hpp"
#include "Mode.hpp"

class AIMode : public Mode
{
private:
    
    int findBestMove(char p); // returns in int: level
    
    int chooseRandomMove(char p);
    
    int playDifficulty1(char);
    int playDifficulty2(char);
    int playDifficulty3(char);
    int playDifficulty4(char);
    
    void playAsBot();
    
public:
    int difficulty; // 1-2-3-4
    // 4 should be impossible to win against
    
    char turn = 'p'; // p=player, b=bot
    char starting = 'p';
    
public:
    
    AIMode(std::vector<XPoint>& xps, std::vector<OPoint>& ops, std::string& b, SoundManager& sm, sf::RenderWindow&, int d=1);
    
    void inIntersect(sf::Event&, std::vector<sf::RectangleShape>&) override;
    
    void pollEvent(sf::Event&) override;
    
    void update() override;
    
    void draw() override;
};
