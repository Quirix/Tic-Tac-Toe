//
//  VirtualBoard.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#pragma once

#include "Xpoint.hpp"
#include "OPoint.hpp"

#include <vector>
#include <iostream>

class VirtualBoard {
public:
    std::vector<XPoint> xPoints;
    std::vector<OPoint> oPoints;
    
    std::string strBoard;
    
    char tttstate = 'n';
    
    void update(); // updates strBoard and tttstate, do not put in update() of main class.
    
    void strToBoard(const std::string&);
    
    void putPoint(char, int);
    
    void pullPoint(int);
    
    void reset();
    
};
