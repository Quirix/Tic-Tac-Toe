//
//  LightVirtualBoard.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 11/7/24.
//

#include "LightVirtualBoard.hpp"

#include "Functions.hpp"

#include <iostream>

void LightVirtualBoard::update()
{
    tttstate = checkState(strBoard);
}

void LightVirtualBoard::strToBoard(const std::string& str)
{
    if (str.length() != 9) {
        std::cerr << "(VirtualBoard.cpp) error in VIrtualBoard::strToBoard(..) str.length() is not 9)\n";
        return;
    }
    
    strBoard = str;
    
    update();
}

void LightVirtualBoard::putPoint(char pnt, int lvl)
{
    strBoard[lvl-1] = pnt;
    
    if ( (pnt != 'x') && (pnt != 'o') ) std::cerr << "(VirtualBoard.cpp) in class VirtualBoard Function putPoint(..) pnt (point) is not x or o.\n";
    
    update();
}

void LightVirtualBoard::pullPoint(int lvl)
{
    
    if (strBoard[lvl-1] == 'n') std::cerr << "(VirtualBoard.cpp) in class VirtualBoard Function pullPoint(..), point doesn't exist in strBoard[lvl-1\n";
    
    strBoard[lvl-1] = 'n';
    
    update();
}

void LightVirtualBoard::reset()
{
    strBoard = "nnnnnnnnn";
    tttstate = 'n';
}
