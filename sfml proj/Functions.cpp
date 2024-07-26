//
//  Functions.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Functions.hpp"
#include "constants.hpp"
#include "LightVirtualBoard.hpp"

void drawBoard(sf::RenderWindow& win){
    sf::RectangleShape rec1 = sf::RectangleShape{{WinWidth, 5.f}};
    rec1.setFillColor(sf::Color{0, 0, 0, 125} );
    rec1.rotate(90.f);
    rec1.move(sf::Vector2f{pointWidth + 5.f, 0} );
    
    sf::RectangleShape rec2 = sf::RectangleShape{{WinWidth, 5.f}};
    rec2.setFillColor(sf::Color{0, 0, 0, 125} );
    rec2.rotate(90.f);
    rec2.move(sf::Vector2f{ (pointWidth*2) + 5.f, 0} );
    
    sf::RectangleShape rec3 = sf::RectangleShape{{WinWidth, 5.f}};
    rec3.setFillColor(sf::Color{0, 0, 0, 125} );
    rec3.move(sf::Vector2f{0, pointHeight + 5.f} );
    
    sf::RectangleShape rec4 = sf::RectangleShape{{WinWidth, 5.f}};
    rec4.setFillColor(sf::Color{0, 0, 0, 125} );
    rec4.move(sf::Vector2f{0, (pointHeight*2) + 5.f} );
    
    win.draw(rec1);
    win.draw(rec2);
    win.draw(rec3);
    win.draw(rec4);
    // unecessary, wastes memory and time
}

void createRectangles(std::vector<sf::RectangleShape>& vec)
{
    for (int i = 0; i < 3; i++)
    {
        int heightRec = (pointHeight * i) + 5.f;
        
        sf::RectangleShape rec1 {sf::RectangleShape{sf::Vector2f{pointWidth-5.f, pointHeight+5.f}} };
        sf::RectangleShape rec2 {sf::RectangleShape{sf::Vector2f{pointWidth-5.f, pointHeight+5.f}} };
        sf::RectangleShape rec3 {sf::RectangleShape{sf::Vector2f{pointWidth-5.f, pointHeight+5.f}} };
        
        rec1.setPosition(0, heightRec);
        rec2.setPosition(pointWidth+5.f, heightRec);
        rec3.setPosition( (pointWidth*2)+5.f, heightRec);
        
        rec1.setFillColor(sf::Color::Transparent);
        rec2.setFillColor(sf::Color::Transparent);
        rec3.setFillColor(sf::Color::Transparent);
        
        vec.push_back(rec1);
        vec.push_back(rec2);
        vec.push_back(rec3);
    }
}

char pointExistInLevel(std::vector<XPoint>& xp, std::vector<OPoint>& op, int lvl)
{
    
    for (auto& p : xp) {
        if (p.Level == lvl)
            return 'x';
    }
    
    for (auto& p : op) {
        if (p.Level == lvl)
            return 'o';
    }
    
    return 'n';
}

std::string boardInString(std::vector<XPoint>& xp, std::vector<OPoint>& op) {
    std::string s = "nnnnnnnnn";
    
    for (auto& p : xp)
        s[p.Level-1] = 'x';
    for (auto& p : op)
        s[p.Level-1] = 'o';
    
    
    return s;
}

bool stateWinPoint(const std::string& board, char point) {
    // right to left
    for (int i = 0; i < 3; i++)
    {
        int j = 3*i;
        if (board[j] == point && board[j+1] == point && board[j+2] == point)
            return true;
    }
    
    
    // top to down
    for (int i = 0; i < 3; i++)
        if (board[i] == point && board[i+3] == point && board[i+6] == point)
            return true;
    
    
    // diagonal
    if (board[0] == point && board[4] == point && board[8] == point)
        return true;
    if (board[2] == point && board[4] == point && board[6] == point)
        return true;
    
    return false;
}

char checkState(const std::string& board)
{
    
    if (stateWinPoint(board, 'x'))
        return 'x';
    if (stateWinPoint(board, 'o'))
        return 'o';
    
    // draw
    int num=0;
    for (int i = 0; i < 9; i++)
        if (board[i] != 'n') num++;
    
    if (num==9) return 'd';
    
    return 'n';
}

Game* returnCorrectState(const std::vector<Game*>& allGameStates, GameState state)
{
    for (auto* e : allGameStates)
    {
        if (e && e->assignedGameState == state) return e;
    }
    
    std::cerr << "ERROR/WARNING in returnCorrectState(..), couldn't find Game* class with same \n"
    "assignedGameState as current state\n";
    return nullptr;
}

Point* levelToPoint(int lvl, std::vector<XPoint>& xpoints, std::vector<OPoint>& opoints)
{
    
    for (auto& e : xpoints)
    {
        if (e.Level == lvl) return &e;
    }
    
    for (auto& e : opoints)
    {
        if (e.Level == lvl) return &e;
    }
    
    return nullptr;
}

// 0 - range
int getRandomNumber(int range)
{
    static bool once = false;
    
    if (!once) {
        std::srand( (unsigned int) std::time(nullptr));
        once = true;
    }
    
    int random_value = std::rand() % (range+1);
    
    return random_value;
    
    return 1;
}

std::vector<int> getAvailableLevels(std::vector<XPoint>& xPoints, std::vector<OPoint>& oPoints)
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    
    for (auto& e : xPoints)
        vec[e.Level-1] = 0;
    
    for (auto& e : oPoints)
        vec[e.Level-1] = 0;
    
    int vecsize = 9;
    
    while (true)
    {
        
        int i=0;
        
        for (int j = 0 ; j < vecsize; j++)
        {
            if (vec[j] == 0)
            {
                vec.erase(vec.begin() + j);
                
                vecsize--;
                i++;
                
                break;
            }
            
        }
        
        if (i==0) break;
        
    }
    
    return vec;
}

std::vector<int> getAvailableLevels(const std::string& str)
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    
    for (int i = 0 ; i < str.length(); i++) {
        
        if ( (str[i] == 'x') || (str[i] == 'o') ) vec[i] = 0;
    }
    
    int vecsize = 9;
    
    while (true)
    {
        
        int i=0;
        
        for (int j = 0 ; j < vecsize; j++)
        {
            if (vec[j] == 0)
            {
                vec.erase(vec.begin() + j);
                
                vecsize--;
                i++;
                
                break;
            }
            
        }
        
        if (i==0) break;
        
    }
    
    return vec;
}

std::vector<int> getAvailableLevels(const std::string& str, bool)
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    
    for (int i = 0 ; i < str.length(); i++) {
        
        if ( (str[i] == 'x') || (str[i] == 'o') ) vec[i] = 0;
    }
    
    return vec;
}

char oppsPoint(char p) // opposite point
{
    if (p == 'x') return 'o';
    if (p == 'o') return 'x';
    
    return '-';
}

int minimax(std::string position, int depth, bool maximizingPlayer)
{
    LightVirtualBoard vb;
    vb.strToBoard(position);
    
    if ( (depth == 0) || (vb.tttstate != 'n') )
    {
        if (vb.tttstate == 'x') {
            return 1;
        }
        
        if (vb.tttstate == 'o') {
            return -1;
        }
        
        if (vb.tttstate == 'd') {
            return 0;
        }
    }
    
    if (maximizingPlayer)
    {
        
        int value = -10000;
        
        for (auto e : getAvailableLevels(vb.strBoard))
        {
            vb.putPoint('x', e);
            
            value = std::max(value, minimax(vb.strBoard, depth-1, false));
            
            vb.strToBoard(position);
        }
        
        return value;
    }
    
    else
    {
        
        int value = 1000;
        
        for (auto e : getAvailableLevels(vb.strBoard))
        {
            vb.putPoint('o', e);
            
            value = std::min(value, minimax(vb.strBoard, depth-1, true));
            
            vb.strToBoard(position);
        }
        
        return value;
    }
    
    
    /*
    *    20/7/24
    * this was bugged for a week+ and i couldn't find the issue and i finally
    * fixed it and it is working
    *
    * problem was that in maximizingPlayer vb.putPoint('o' <<<, e);
    * and in minimizingPlayer vb.putPoint('x' <<<, e);
    *
    * the fixed is: in maximizingPlayer vb.putPoint('x' <<, e) instead of 'o'
    * and in minimizingPlayer vb.putPoint('o' <<, e) instead of 'x'
    *
     */
    
}

