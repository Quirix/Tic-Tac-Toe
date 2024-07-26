//
//  NormalMode.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#include "NormalMode.hpp"

#include "Functions.hpp"

NormalMode::NormalMode(std::vector<XPoint>& xps, std::vector<OPoint>& ops, std::string& b, SoundManager& sm, sf::RenderWindow& w)
    : Mode{xps, ops, b, sm, w}
{
    
}

void NormalMode::inIntersect(sf::Event& event, std::vector<sf::RectangleShape>& boardRectangles) {
    int mouseX = event.mouseButton.x;
    int mouseY = event.mouseButton.y;
    
    sf::RectangleShape rec {sf::Vector2f{1, 1}};
    
    
    rec.setPosition(sf::Vector2f{(float) mouseX, (float) mouseY});
    
    for (int i = 0; i < 9; i++) {
        if (rec.getGlobalBounds().intersects(boardRectangles[i].getGlobalBounds()))
        {
            int lvl = i+1;
            
            if (pointExistInLevel(xPoints, oPoints, lvl) != 'n') break;
            
            // intersect
            
            if (turn == 'x')
            {
                XPoint xp;
                xp.setToLevel(lvl);
                xPoints.push_back(xp);
        
                turn = 'o';
                
                soundManager.clickSound.play();
                break;
            }
            
            if (turn == 'o')
            {
                OPoint op;
                op.setToLevel(lvl);
                oPoints.push_back(op);
                
                turn = 'x';
                soundManager.clickSound2.play();
                break;
            }
            
        }
    }
}

void NormalMode::pollEvent(sf::Event&) {}

void NormalMode::update() {}

void NormalMode::draw() {}
