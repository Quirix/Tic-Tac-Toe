//
//  LoseWinDrawScreen.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 30/6/24.
//

#include "constants.hpp"

#include <iostream>
#include <cmath>

#include "LoseWinDrawScreen.hpp"

LWD::LWD(char tst, sf::RenderWindow& win) :
    tttstate(tst),
replayButton{sf::Vector2f{WinWidth/2, 600}, "", sf::Color{144, 238, 144, 240}, 'c'},
    window{win}
{
    replayButton.radius = 90;
}

char LWD::getAction() {
    return returnActionBack;
}

void LWD::pollEvent(sf::Event& event) {
    replayButton.handleMouseEvents(event);
}

void LWD::update() {
    
    if (transparency > 1) transparency = 1;
    
    if (transparency < 1) transparency += 0.001;

    
    const sf::Color& rc = replayButton.rec_normalColor;
    const sf::Color& tc = replayButton.text_normalColor;
    
    if (transparency < 1) {

        replayButton.rec_normalColor = sf::Color{rc.r, rc.g, rc.b, (sf::Uint8) (240*transparency)};
        replayButton.text_normalColor = (sf::Color{tc.r, tc.g, tc.b, (sf::Uint8) (255*transparency) } );
    }
    
    // fade effect ^^^
    
    if (replayButton.isClicked())
    {
        returnActionBack = 'r'; // replay
    }
    
    replayButton.update();

}

void LWD::draw(sf::RenderWindow& window) {
    

    replayButton.draw(window);
}
