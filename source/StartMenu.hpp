//
//  StartMenu.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#pragma once

#include "GameState.hpp"
#include "Button.hpp"
#include "Animation.hpp"

#include <SFML/Graphics.hpp>

class StartMenu : public Game {
private:
    sf::Font thin;
    sf::Font bold;
    
    sf::Text text;
    sf::Text diffText;
    
    float colorChange=0;
    
    int& modeGame;
    
    bool aiSelect = false;
    
    Animation animation;
    
    Button playNormalButton; // play normal mode button
    Button playAiButton; // play ai mode button
    Button backAiSelectButton;
    
    Button ButtonAiDifficulty1;
    Button ButtonAiDifficulty2;
    Button ButtonAiDifficulty3;
    Button ButtonAiDifficulty4;
    
    std::vector<std::reference_wrapper<Button>> allButtons;
    
    sf::RectangleShape rc2;
    sf::RectangleShape rc;
    
public:
    
    StartMenu(sf::RenderWindow&, GameState&, SoundManager&, int&);
    
    void pollEvent(sf::Event&) override;
    
    void update() override;
    void draw() override;
    
    ~StartMenu() {};
    
};
