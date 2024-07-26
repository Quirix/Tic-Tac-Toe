//
//  RunMode.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#include "Mode.hpp"

Mode::Mode(std::vector<XPoint>& xps, std::vector<OPoint>& ops, std::string& b, SoundManager& sm, sf::RenderWindow& w)
    : xPoints(xps), oPoints(ops), board{b}, soundManager(sm), window(w)
{
    
}

void Mode::inIntersect(sf::Event&, std::vector<sf::RectangleShape>& boardRectangles) {}

void Mode::pollEvent(sf::Event&) {}

void Mode::update() {}

void Mode::draw() {}

Mode::~Mode() {}
