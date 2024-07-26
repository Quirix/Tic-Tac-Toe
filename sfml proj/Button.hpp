//
//  Button.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 30/6/24.
//

#pragma once

#include <SFML/Graphics.hpp>

class Button {
private:
    bool isPressed=false;
    bool m_isClicked=false; // mouse released on button
    bool isHovering=false;

    std::string str;
    
    sf::Font font;
    
    void setTextPosition(const sf::Vector2f&);
    
    void setNormalColor();
    void setHoverColor();
    void setClickColor();
    void setPressColor();
    
public:
    char style; // r=rectangle c=cirlce
    bool active=true;
    sf::RectangleShape rec;
    sf::CircleShape circ;
    sf::Text text;
    
    sf::Color rec_normalColor{150, 150, 150, 240};
    sf::Color text_normalColor{sf::Color::Black};
    sf::Color outline_normalColor{sf::Color::Black};
    
    int radius=50;
    
    bool drawButton = true;
    
    sf::Shape& correct();
    
    void fullActive(bool b);
    
public:
    
    Button(const sf::Vector2f&, const std::string&,sf::Color=sf::Color{150, 150, 150, 240}, char ch='r');
    
    void setPosition(const sf::Vector2f&);
    
    void handleMouseEvents(sf::Event&);
    
    bool isClicked();
    
    void update();
    
    void draw(sf::RenderWindow&);
};
