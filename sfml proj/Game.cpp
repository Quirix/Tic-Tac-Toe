//
//  Game.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#include "Functions.hpp"

#include "Game.hpp"

#include <iostream>

Game::Game()
: window(sf::VideoMode{WinWidth, WinHeight}, "Tic Tac Toe")
{
    
    createRectangles(boardRectangles);
}

void Game::pollEvent(sf::Event& event){
    switch (event.type) {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
            
        case sf::Event::MouseButtonReleased:
        {
            
            if (event.mouseButton.button == sf::Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                
                sf::RectangleShape rec {sf::Vector2f{1, 1}};
                
                
                rec.setPosition(sf::Vector2f{(float) mouseX, (float) mouseY});
                
                for (int i = 0; i < 9; i++) {
                    if (rec.getGlobalBounds().intersects(boardRectangles[i].getGlobalBounds()))
                    {
                        int lvl = i+1;
                        
                        if (pointExistInLevel(xPoints, oPoints, lvl) != 'n') break;
                        
                        
                        if (turn == 'x')
                        {
                            XPoint xp;
                            xp.setToLevel(lvl);
                            xPoints.push_back(xp);
                            
                            turn = 'o';
                            break;
                        }
                        
                        if (turn == 'o')
                        {
                            OPoint op;
                            op.setToLevel(lvl);
                            oPoints.push_back(op);
                            
                            turn = 'x';
                            break;
                        }
                    
                    }
                }
            }
            
            break;
        }
            
        default: {
            break;
        }
    }
}

void Game::update(){
    strBoard = boardInString(xPoints, oPoints);
}

void Game::draw(){
    for (auto& p : xPoints)
        p.draw(window);
    for (auto& p : oPoints)
        p.draw(window);
    
    drawBoard(window);
    
}


Game::~Game(){
    
}
