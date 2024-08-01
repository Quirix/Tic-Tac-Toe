//
//  Xpoint.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 22/6/24.
//

#pragma once

#include "constants.hpp"
#include "PointClass.hpp"

#include <SFML/Graphics.hpp>

class XPoint : public Point
{
private:
    float xDifference = pointWidth/5;
    float yDifference = pointHeight/5;
    
    
public:
    //sf::RectangleShape line1;
    //sf::RectangleShape line2;
    
    sf::Texture xTexture;
    sf::Texture redXTexture;
    char usingTexture = 'x';
    sf::RectangleShape xSprite;
    
public:
    
    XPoint();
    
    void setPos(int x, int y, bool dif=true);
    
    void draw(sf::RenderWindow&);
};
