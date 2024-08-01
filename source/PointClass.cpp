//
//  PointClass.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 22/6/24.
//

#include "constants.hpp"
#include "PointClass.hpp"

#include <iostream>

void Point::setToLevel(int level) {
    // this is not needed, i could just
    // use a switch but whatever.
    
    if (level <= 9 && level > 0)  {
    
        bool brk = false;
        
        for (int i = 0; i < 3; i++) {
            int r = 0;
            
            
            for (int j = 0; j < 3; j++)
            {
                setPos(pointWidth*j, pointHeight*i);
                
                r += 3 * i;
                r += j + 1;
               
                if (r==level)
                {
                    brk = true;
                    break;
                }
                r = 0;
                
            }
            
            if (brk) break;
        }
        
        Level = level;
    }
    
    else
        std::cerr << "error in setToLevel(int), class PointClass, arg level is less than 1 or more than 9\n";
    
}
