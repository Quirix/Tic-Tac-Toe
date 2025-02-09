//
//  OPoint.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 22/6/24.
//

#include "OPoint.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>


OPoint::OPoint() {
    
    /*line1 = sf::RectangleShape{sf::Vector2f{ static_cast<float>(linewidth) , 5}};
    line2 = sf::RectangleShape{sf::Vector2f{ static_cast<float>(linewidth) , 5}};
    
    line2.move(sf::Vector2f{0, 175});
    // this line is not considering linewidth, 175 is a random value
    
    line1.rotate(45.f);
    line2.rotate(-45.f);*/
    
    if (!xTexture.loadFromFile("Images/circle.png"))
    {
        std::cerr << "Error in xTexture.loadFromFile(\"circle.png\") class OPoint\n";
    }
    
    if (!redxTexture.loadFromFile("Images/orngo.png"))
    {
        std::cerr << "Error in xTexture.loadFromFile(\"orngo.png\") class OPoint\n";
    }
    
    xSprite.setTexture(&xTexture);
    
    xSprite.setPosition(sf::Vector2f{ (pointWidth/2.f) + (xDifference/2), (pointHeight/2.f) + (yDifference/2)} );
    
    xSprite.setSize(sf::Vector2f{(float)pointWidth - xDifference, (float)pointHeight - yDifference} );
    xSprite.setOrigin(sf::Vector2f{pointWidth/2.f, pointHeight/2.f});
 
}

void OPoint::setPos(int x, int y, bool wdif)
{
    //line1.setPosition(sf::Vector2f{} );
    
    if (!wdif)
        xSprite.setPosition(sf::Vector2f{x+(pointWidth/2.f), y+(pointHeight/2.f) } );
    else
        xSprite.setPosition(sf::Vector2f{x+(pointWidth/2.f) + (xDifference/2), y+(pointHeight/2.f) + (yDifference/2) } );

}

void OPoint::draw(sf::RenderWindow& win)
{
    if (usingTexture == 'x')
        xSprite.setTexture(&xTexture);
    else xSprite.setTexture(&redxTexture);
    win.draw(xSprite);
}
