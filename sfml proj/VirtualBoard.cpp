//
//  VirtualBoard.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#include "VirtualBoard.hpp"

#include "Functions.hpp"

void VirtualBoard::update()
{
    strBoard = boardInString(xPoints, oPoints);
    
    tttstate = checkState(strBoard);
}

void VirtualBoard::strToBoard(const std::string& str)
{
    xPoints.clear();
    oPoints.clear();
    
    if (str.length() != 9) {
        std::cerr << "(VirtualBoard.cpp) error in VIrtualBoard::strToBoard(..) str.length() is not 9)\n";   
        return;
    }
    
    for (int i = 0 ; i < 9; i++)
    {
        if (str[i] == 'x')
        {
            XPoint xp;
            xp.setToLevel(i+1);
            xPoints.push_back(xp);
        }
        if (str[i] == 'o')
        {
            OPoint op;
            op.setToLevel(i+1);
            oPoints.push_back(op);
        }
    }
    
    update();
}

void VirtualBoard::putPoint(char pnt, int lvl)
{
    if (pnt == 'x')
    {
        XPoint xp;
        xp.setToLevel(lvl);
        
        xPoints.push_back(xp);
    }
    
    else if (pnt == 'o')
    {
        OPoint op;
        op.setToLevel(lvl);
        
        oPoints.push_back(op);
    }
    
    else std::cerr << "(VirtualBoard.cpp) in class VirtualBoard Function putPoint(..) pnt (point) is not x or o.\n";
    
    update();
}

void VirtualBoard::pullPoint(int lvl)
{
    
    if (pointExistInLevel(xPoints, oPoints, lvl) == 'x')
    {
        for (int i = 0 ; i < xPoints.size(); i++)
        {
            if (xPoints[i].Level == lvl) xPoints.erase(xPoints.begin() + i );
        }
    }
    
    else if (pointExistInLevel(xPoints, oPoints, lvl) == 'o')
    {
        for (int i = 0 ; i < oPoints.size(); i++)
        {
            if (oPoints[i].Level == lvl) oPoints.erase(oPoints.begin() + i );
        }
    }
    
    else std::cerr << "(VirtualBoard.cpp) in class VirtualBoard Function pullPoint(..), point doesn't exist in xPoints[lvl] or oPoints[lvl]\n";
    
    update();
}

void VirtualBoard::reset()
{
    xPoints.clear();
    oPoints.clear();
    
    update();
}
