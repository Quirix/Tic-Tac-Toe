//
//  Game.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#include "Functions.hpp"

#include "GameRunning.hpp"

#include <iostream>

void GameRun::reset()
{
    if (lwd) delete lwd;
    lwd = nullptr;
    
    xPoints.clear();
    oPoints.clear();
    strBoard.clear();
    
    turn = 'x';
    
    int d=1;
    
    if (mode) {
        
        if (modechar == 'a')
        {
            d = (dynamic_cast<AIMode&>(*mode).difficulty);
        }
        
        delete mode;
        mode = nullptr;
    }
    
    if (modechar == 'n') mode = new NormalMode{xPoints, oPoints, strBoard, soundManager, window};
    else if (modechar == 'a') mode = new AIMode{xPoints, oPoints, strBoard, soundManager, window, d};
    
    else std::cerr << " (GameRunning.cpp) error in function reset() modechar is neither 'n' (normal) or 'a' (ai)\n";
    
}

void GameRun::changePointsOfWin()
{
    std::string board = boardInString(xPoints, oPoints);
    char tttstate = checkState(board);
    
    std::vector<Point*> pointswin {nullptr, nullptr, nullptr};

    char point = tttstate;
        
    // right to left
    for (int i = 0; i < 3; i++)
    {
        int j = 3*i;
        if (board[j] == point && board[j+1] == point && board[j+2] == point) {
            pointswin = { levelToPoint(j+1, xPoints, oPoints), levelToPoint(j+2, xPoints, oPoints), levelToPoint(j+3, xPoints, oPoints) };
            break;
        }
    }
      
    // top to down
    for (int i = 0; i < 3; i++) {
        if (board[i] == point && board[i+3] == point && board[i+6] == point) {
            pointswin = {levelToPoint(i+1, xPoints, oPoints), levelToPoint(i+4, xPoints, oPoints), levelToPoint(i+7, xPoints, oPoints) };
            break;
        }
    }
        
    // diagonal
    if (board[0] == point && board[4] == point && board[8] == point)
        pointswin = {levelToPoint(1, xPoints, oPoints), levelToPoint(5, xPoints, oPoints), levelToPoint(9, xPoints, oPoints)};
    if (board[2] == point && board[4] == point && board[6] == point)
        pointswin = {levelToPoint(3, xPoints, oPoints), levelToPoint(5, xPoints, oPoints), levelToPoint(7, xPoints, oPoints) };
        
    
    if ( pointswin[0] && pointswin[1] && pointswin[2] )
    {
        if (tttstate == 'x') {
            dynamic_cast<XPoint&>(*pointswin[0]).usingTexture = 'r';
            dynamic_cast<XPoint&>(*pointswin[1]).usingTexture = 'r';
            dynamic_cast<XPoint&>(*pointswin[2]).usingTexture = 'r';
        }
        
        if (tttstate == 'o') {
            dynamic_cast<OPoint&>(*pointswin[0]).usingTexture = 'r';
            dynamic_cast<OPoint&>(*pointswin[1]).usingTexture = 'r';
            dynamic_cast<OPoint&>(*pointswin[2]).usingTexture = 'r';
        }
    }
    // do modifications here
        
    
}

GameRun::GameRun(sf::RenderWindow& win, GameState& currentstate, SoundManager& sm)
: Game{win, RUNNING, currentstate, sm}
{
    createRectangles(boardRectangles);
    
    mode = new NormalMode{xPoints, oPoints, strBoard, soundManager, window};
    modechar = 'n';
}

GameRun::GameRun(sf::RenderWindow& win, GameState& currentstate, SoundManager& sm, char m, int dif)
: Game{win, RUNNING, currentstate, sm}
{
    createRectangles(boardRectangles);
    
    if (m == 'n') // normal
        mode = new NormalMode{xPoints, oPoints, strBoard, soundManager, window};
    
    else if (m == 'a' ) // ai
        mode = new AIMode{xPoints, oPoints, strBoard, soundManager, window, dif};
    
    else std::cerr << "(GameRunning.cpp) class GameRun constructor GameRun::GameRun(),  m (mode) is not n (normal) or a (ai).";
    
    modechar = m;
    
}


void GameRun::pollEvent(sf::Event& event){
    if (lwd) lwd->pollEvent(event);
    if (mode) mode->pollEvent(event);
    
    switch (event.type) {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
            
        case sf::Event::MouseButtonReleased:
        {
            
            if (checkState(strBoard) != 'n') break;
            
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (mode) mode->inIntersect(event, boardRectangles);
            }
            
            break;
        }
            
        default: {
            break;
        }
    }
}

void GameRun::update(){
    static bool once_lwd_sound = false;
    
    strBoard = boardInString(xPoints, oPoints);
    
    if (mode) mode->update();
    
    char tttstate = checkState(strBoard); // ttt = tic tac toe
    
    if (tttstate != 'n')
    {
        if (!lwd) lwd = new LWD{tttstate, window};
        
        if (!once_lwd_sound)
        {
            changePointsOfWin();
            soundManager.lwdsound.play();
        }
        once_lwd_sound = true;
    }
    
    else once_lwd_sound = false;
    
    if (lwd)
    {
        lwd->update();
        
        if (lwd->getAction() == 'r')
        {
            soundManager.onreplaysound.play();
            
            // reset
            
            reset();
            
        }
    }
    
}

void GameRun::draw(){
    
    for (auto& p : xPoints)
        p.draw(window);
    for (auto& p : oPoints)
        p.draw(window);
    
    drawBoard(window);
    
    if (lwd) lwd->draw(window);
    if (mode) mode->draw();
}


GameRun::~GameRun(){
    if (lwd) delete lwd;
    if (mode) delete mode;
}
