//
//  LightVirtualBoard.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 11/7/24.
//

#pragma once

#include <string>

class LightVirtualBoard
{
public:
    
    char tttstate = 'n';
    
    std::string strBoard;
    
    void update();
    
    void strToBoard(const std::string&);
    
    void putPoint(char, int);
    
    void pullPoint(int);
    
    void reset();
};
