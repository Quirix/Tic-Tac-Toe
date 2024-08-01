// 22/6/24

#pragma once

class Point{
public:
    int Level = 0;
public:
    
    virtual void setPos(int, int, bool d=true) = 0;
    
    void setToLevel(int level);
    
};
