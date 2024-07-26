//
//  Functions.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 25/6/24.
//

#pragma once

#include "Xpoint.hpp"
#include "OPoint.hpp"
#include "GameState.hpp"
#include "GameRunning.hpp"
#include "StartMenu.hpp"

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

void drawBoard(sf::RenderWindow& win);

void createRectangles(std::vector<sf::RectangleShape>& vec);

char pointExistInLevel(std::vector<XPoint>&, std::vector<OPoint>&, int lvl);

std::string boardInString(std::vector<XPoint>&, std::vector<OPoint>&);

bool stateWinPoint(const std::string&, char);

char checkState(const std::string& );

Game* returnCorrectState(const std::vector<Game*>&, GameState);

Point* levelToPoint(int, std::vector<XPoint>&, std::vector<OPoint>&);

int getRandomNumber(int);

std::vector<int> getAvailableLevels(std::vector<XPoint>&, std::vector<OPoint>&);

std::vector<int> getAvailableLevels(const std::string&);

std::vector<int> getAvailableLevels(const std::string&, bool);

char oppsPoint(char); // opposite point

int minimax(std::string, int, bool);

template <typename T>

T selectFromArray(const std::vector<T>& v) {
    return v[ (int) ( getRandomNumber( ((int) (v.size())) - 1 ) ) ];
}
