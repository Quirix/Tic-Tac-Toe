//
//  Functions.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#pragma once

#include "Xpoint.hpp"
#include "OPoint.hpp"

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

void drawBoard(sf::RenderWindow& win);

void createRectangles(std::vector<sf::RectangleShape>& vec);

char pointExistInLevel(std::vector<XPoint>&, std::vector<OPoint>&, int lvl);

std::string boardInString(std::vector<XPoint>&, std::vector<OPoint>&);

bool stateWinPoint(const std::string&, char);

char checkState(const std::string& );
