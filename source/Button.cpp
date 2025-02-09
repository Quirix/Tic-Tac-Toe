//
//  Button.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 30/6/24.
//


#include <iostream>

#include "constants.hpp"

#include "Button.hpp"

Button::Button(const sf::Vector2f& pos, const std::string& s,sf::Color clr, char ch)
    : str{s}, style{ch}
{
    
    rec_normalColor = clr;
    
    const int recwidth = 200;
    const int recheight = 80;
    
    if (style == 'r') {
        rec.setPosition(pos);
        rec.setSize(sf::Vector2f{recwidth, recheight});
    }
    else if (style == 'c')
    {
        circ.setPosition(pos);
        circ.setRadius(radius);
        circ.setOrigin(circ.getGlobalBounds().width/2, circ.getGlobalBounds().height/2);
        circ.setOutlineColor(clr);
        circ.setOutlineThickness(2);
        outline_normalColor = clr;
    }
    
    setNormalColor();
    
    if (!font.loadFromFile("Roboto/Roboto-ThinItalic.ttf"))
    {
        std::cerr << "(Button.cpp) class Button constructor Button() font cannot load.\n";
    }
    
    int w=0;
    
    text.setFont(font);
    if (style == 'r') text.setCharacterSize(50);
    else if (style == 'c') text.setCharacterSize(40);
    
    text.setString(s);
    
    w = text.getGlobalBounds().width;
    text.setOrigin(w/2, text.getGlobalBounds().height/2);
    setTextPosition(pos);
    text.setFillColor(sf::Color::Black);
    
}

sf::Shape& Button::correct() {
    if (style == 'r') return rec;
    else if (style == 'c' ) return circ;
    else throw " (Button::correct()) style is not r or c";
    return rec;
}

void Button::setPosition(const sf::Vector2f& pos)
{
    correct().setPosition(pos);
    setTextPosition(pos);
}

void Button::setNormalColor(){
    correct().setFillColor(rec_normalColor);
    correct().setOutlineColor(outline_normalColor);
    text.setFillColor(text_normalColor);
}

void Button::setHoverColor(){
    correct().setFillColor(sf::Color{rec_normalColor.r, rec_normalColor.g, rec_normalColor.b, 127});
    text.setFillColor(sf::Color{0, 0, 0, 127} );
}

void Button::setClickColor(){
    correct().setFillColor(sf::Color{255, 255, 255, 80});
    text.setFillColor(sf::Color{0, 0, 0, 80} );
}

void Button::setPressColor(){
    correct().setFillColor(sf::Color{rec_normalColor.r, rec_normalColor.g, rec_normalColor.b, 50});
    text.setFillColor(sf::Color{0, 0, 0, 100} );
}


void Button::setTextPosition(const sf::Vector2f& pos){
    text.setPosition(pos.x+ (rec.getSize().x/2), pos.y+(rec.getSize().y/4) );
}

bool Button::isClicked() {
    return m_isClicked;
}

void Button::fullActive(bool b) {
    active = b;
    drawButton = b;
}

void Button::handleMouseEvents(sf::Event& event) {
    sf::Shape& shp = correct();
    if (!active) return;
    
    if (event.type == sf::Event::MouseButtonReleased)
    {
        sf::Vector2f mousepos = sf::Vector2f{(float) event.mouseButton.x,(float) event.mouseButton.y};

        
        if (shp.getGlobalBounds().contains(mousepos) )
            m_isClicked = true;
        
        
    }
    
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mousepos = sf::Vector2f{(float) event.mouseButton.x,(float) event.mouseButton.y};
        
        
        isPressed = (shp.getGlobalBounds().contains(mousepos));
        
    }
    
    if (event.type == sf::Event::MouseMoved)
    {
        sf::Vector2f mousepos = sf::Vector2f{(float) event.mouseMove.x,(float) event.mouseMove.y};
        
        if ( !(shp.getGlobalBounds().contains(mousepos)) && isPressed)
            isPressed = false;
        
        if (shp.getGlobalBounds().contains(mousepos) && !isPressed)
            isHovering = true;
        else if ( !(shp.getGlobalBounds().contains(mousepos)) ) isHovering = false;
    
    }
}

void Button::update() {
    if (style == 'c') circ.setRadius(radius);
    
    if (active) {
        if (isHovering && !isPressed) setHoverColor();
        if (isPressed) setPressColor();
        
        if (m_isClicked) {
            setNormalColor();
            isPressed = false;
        }
        
        if (!isHovering && !isPressed) setNormalColor();
    }
    
    else setNormalColor();
    m_isClicked = false; // supposed to be at end of update()
}

void Button::draw(sf::RenderWindow& window) {
    
    /*sf::RectangleShape rcshpt { sf::Vector2f{text.getGlobalBounds().width, text.getGlobalBounds().height}};
    rcshpt.setPosition(text.getPosition());
    rcshpt.setOrigin(text.getGlobalBounds().width/2, 0);
    rcshpt.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rc2 {sf::Vector2f{correct().getGlobalBounds().width, correct().getGlobalBounds().height} };
    rc2.setPosition(correct().getPosition());
    if (style=='r') rc2.setOrigin(0, 0);
    else rc2.setOrigin(correct().getGlobalBounds().width/2, correct().getGlobalBounds().height/2);
    rc2.setFillColor(sf::Color{125, 50, 70, 100});
    
    window.draw(rcshpt);
    window.draw(rc2);*/
    
    if (drawButton) {
        window.draw(correct());
        window.draw(text);
    }
}
