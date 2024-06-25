//
//  Functions.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#include "Functions.hpp"
#include "constants.hpp"

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
