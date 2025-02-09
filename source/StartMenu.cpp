//
//  StartMenu.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#include "StartMenu.hpp"

#include "constants.hpp"

#include <iostream>
#include <cmath>

StartMenu::StartMenu(sf::RenderWindow& win, GameState& currentstate, SoundManager& sm, int& mg)
:   Game{win, STARTMENU, currentstate, sm}, modeGame(mg),
    playNormalButton{sf::Vector2f{300, 500}, "NORMAL", sf::Color{144, 238, 144, 240} },
    playAiButton(sf::Vector2f{300, 300}, "AI", sf::Color{255, 127, 127} ),
    backAiSelectButton(sf::Vector2f{300, 300}, "BACK", sf::Color{255, 127, 127} ),
    ButtonAiDifficulty1{sf::Vector2f{195, 500}, "", sf::Color{144, 238, 144,}, 'c' },
    ButtonAiDifficulty2{sf::Vector2f{345, 500}, "", sf::Color{255, 255, 0,}, 'c' },
    ButtonAiDifficulty3{sf::Vector2f{495, 500}, "", sf::Color{255, 165, 0,}, 'c' },
    ButtonAiDifficulty4{sf::Vector2f{645, 500}, "", sf::Color{255, 0, 0,}, 'c' },
    allButtons{ButtonAiDifficulty1,ButtonAiDifficulty2,ButtonAiDifficulty3,ButtonAiDifficulty4,
    playNormalButton, playAiButton, backAiSelectButton}
{
    
    modeGame = 4;
    
    if (!thin.loadFromFile("Roboto/Roboto-Thin.ttf"))
    {
        std::cerr << "ERROR font didn't load class StartMenu, in constructon StartMenu()\n";
    }
    
    if (!bold.loadFromFile("Roboto/Roboto-Bold.ttf"))
    {
        std::cerr << "ERROR font didn't load class StartMenu, in constructon StartMenu()\n";
    }
    
    float widthtext = 0;
    
    text.setCharacterSize(100);
    
    text.setStyle(sf::Text::Underlined);
    text.setFont(thin);
    text.setString("Tic Tac Toe");
    text.setFillColor(sf::Color::Black); // black
    widthtext = text.getGlobalBounds().width;
    
    text.setOrigin(widthtext/2, 0);
    text.setPosition(sf::Vector2f{WinWidth/2, 10} );
    
    diffText.setCharacterSize(70);
    diffText.setString("SELECT A DIFFICULTY");
    diffText.setFont(thin);
    diffText.setFillColor(sf::Color::Transparent);
    diffText.setOrigin(diffText.getGlobalBounds().width/2, 0);
    diffText.setPosition(WinWidth/2, 350);
    
    int r = 50;
    
    ButtonAiDifficulty1.radius = r;
    ButtonAiDifficulty1.active = false;
    ButtonAiDifficulty2.radius = r;
    ButtonAiDifficulty2.active = false;
    ButtonAiDifficulty3.radius = r;
    ButtonAiDifficulty3.active = false;
    ButtonAiDifficulty4.radius = r;
    ButtonAiDifficulty4.active = false;
    
    rc2.setPosition(120, 440); // 130 440
    rc2.setSize( sf::Vector2f{580, 80} ); // 580, 80 || 570, 250
    rc2.setFillColor(sf::Color{255,255,255, 0}); //0,0,0,80
    rc2.setOutlineColor(sf::Color{0, 0, 0, 0}); //0,0,0,180
    rc2.setOutlineThickness(2);
    
    rc.setPosition(text.getGlobalBounds().getPosition().x-20, text.getGlobalBounds().getPosition().y-20);
    rc.setSize( sf::Vector2f{text.getGlobalBounds().width+40, text.getGlobalBounds().height+40} );
    rc.setFillColor(sf::Color{0,0,0, 80});
 
    backAiSelectButton.active = false;
    backAiSelectButton.drawButton = false;
    
    ButtonAiDifficulty1.fullActive(false);
    ButtonAiDifficulty2.fullActive(false);
    ButtonAiDifficulty3.fullActive(false);
    ButtonAiDifficulty4.fullActive(false);
    
}

void StartMenu::pollEvent(sf::Event& event)
{
    playNormalButton.handleMouseEvents(event);
    playAiButton.handleMouseEvents(event);
    backAiSelectButton.handleMouseEvents(event);
    
    ButtonAiDifficulty1.handleMouseEvents(event);
    ButtonAiDifficulty2.handleMouseEvents(event);
    ButtonAiDifficulty3.handleMouseEvents(event);
    ButtonAiDifficulty4.handleMouseEvents(event);
    
    switch (event.type) {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
            
        case sf::Event::TextEntered:
        {
            char txt{};
            if (event.text.unicode < 128)
                txt = static_cast<char>(event.text.unicode);
            
            break;
        }
            
        default:
        {
            break;
        }
    };
};

void StartMenu::update() {
    
    animation.update();
    
    if (playNormalButton.isClicked())
    {
        currentGameState = RUNNING;
        modeGame = -1;
    }
    
    if (playAiButton.isClicked())
    {
        animation.clear();

        aiSelect = true;
        
        rc2.setFillColor(sf::Color{rc2.getFillColor().r, rc2.getFillColor().g, rc2.getFillColor().b, 50});
        rc2.setOutlineColor(sf::Color{0, 0, 0, 40});
        
        playNormalButton.fullActive(false);
        
        ButtonAiDifficulty1.fullActive(true);
        ButtonAiDifficulty2.fullActive(true);
        ButtonAiDifficulty3.fullActive(true);
        ButtonAiDifficulty4.fullActive(true);
        
        // should've put all these buttons in a vector but whatever.
        
        playAiButton.fullActive(false);
        
        backAiSelectButton.fullActive(true);
        
        diffText.setFillColor(sf::Color{0,0,0,100});
        
    }
    
    if (backAiSelectButton.isClicked())
    {
        aiSelect = false;
        
        ButtonAiDifficulty1.fullActive(false);
        ButtonAiDifficulty2.fullActive(false);
        ButtonAiDifficulty3.fullActive(false);
        ButtonAiDifficulty4.fullActive(false);
        backAiSelectButton.fullActive(false);
        playNormalButton.fullActive(true);
        playAiButton.fullActive(true);
        
        const sf::Color& rc2clr = rc2.getFillColor();
        rc2.setFillColor(sf::Color{rc2clr.r, rc2clr.g, rc2clr.b, 0});
        rc2.setOutlineColor(sf::Color{0, 0, 0, 0});
        
        diffText.setFillColor(sf::Color::Transparent);
        
    }
    
    for (Button& e : allButtons)
    {
        if (e.isClicked())
        {
            soundManager.releaseSound.play();
        }
    }
    
    if (ButtonAiDifficulty1.isClicked()) {
        currentGameState = RUNNING;
        modeGame = 1;
    } if (ButtonAiDifficulty2.isClicked()) {
        currentGameState = RUNNING;
        modeGame = 2;
    } if (ButtonAiDifficulty3.isClicked()) {
        currentGameState = RUNNING;
        modeGame = 3;
    } if (ButtonAiDifficulty4.isClicked()) {
        currentGameState = RUNNING;
        modeGame = 4;
    }
    
    playAiButton.update();
    playNormalButton.update();
    backAiSelectButton.update();
    ButtonAiDifficulty1.update();
    ButtonAiDifficulty2.update();
    ButtonAiDifficulty3.update();
    ButtonAiDifficulty4.update();
}

void StartMenu::draw() {
    /*float widthtext = 0;
    static double x = 0.0174533;
    static bool up = true;
    widthtext = text2.getGlobalBounds().width;
    text2.setPosition(text.getPosition().x,500 + (std::sin(x)*20) );
    
    x += 0.0005;

    // color
    
    if (colorChange >= 255) up = false;
    if (colorChange <= 0) up = true;
    
    text2.setFillColor(sf::Color{static_cast<sf::Uint8>(colorChange), 0, 0});
    
    if (up) colorChange += 0.1;
    else colorChange -= 0.1;*/
    
    
    playAiButton.draw(window);
    playNormalButton.draw(window);
    //backAiSelectButton.draw(window);
    
    //window.draw(rc2);
    
    ButtonAiDifficulty1.draw(window);
    ButtonAiDifficulty2.draw(window);
    ButtonAiDifficulty3.draw(window);
    ButtonAiDifficulty4.draw(window);
    
    //window.draw(rc);
    window.draw(diffText);
    //window.draw(text);
}


