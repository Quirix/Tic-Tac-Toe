//
//  AIMode.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 9/7/24.
//

#include "AIMode.hpp"

#include "Functions.hpp"
#include "LightVirtualBoard.hpp"

#include <iostream>

int AIMode::findBestMove(char p)
{
    
    if (board == "nnnnnnnnn") {
        std::vector<int> vec {1, 3, 7, 9, 5};
        return selectFromArray(vec);
    }
    
    LightVirtualBoard vb;
    vb.strToBoard(board);
    
    std::vector<int> results;
    
    for (auto e : getAvailableLevels(board, true))
    {
        if (e != 0) {
            vb.putPoint(p, e);
            
            int mm = minimax(vb.strBoard, 10, (p == 'o'));
                
            results.push_back(mm);
            
            vb.strToBoard(board);
        }
        
        else
        {
            if (p == 'x') results.push_back(-100);
            else results.push_back(100);
        }
    }
    
    int w=-5;
    int b;
    
    if (p=='x') b = -100;
    else b = 100;
    
    for (int i = 0 ; i < results.size(); i++)
    {
        if (p == 'x' && results[i] > b)
        {
            b = results[i];
            w = i;
        }
        
        if (p == 'o' && results[i] < b)
        {
            b = results[i];
            w = i;
        }
        
    }
    
    return w+1;
}



int AIMode::chooseRandomMove(char p)
{
    int randomlvl = -1;
    
    while (true) {
        randomlvl = getRandomNumber(8) + 1;
        
        if (pointExistInLevel(xPoints, oPoints, randomlvl) == 'n') break;
    }
    
    return randomlvl;
}

int AIMode::playDifficulty1(char p){
    return chooseRandomMove(p);
}

int AIMode::playDifficulty2(char p){
    int random = getRandomNumber(9) + 1; // 1-10
    
    if (random <= 5) return findBestMove(p);
    return chooseRandomMove(p);
    
    // 50% best
}

int AIMode::playDifficulty3(char p){
    int random = getRandomNumber(9) + 1; // 1-10
    
    if (random <= 8) return findBestMove(p);
    return chooseRandomMove(p);
    
    // 80% best
}

int AIMode::playDifficulty4(char p){
    return findBestMove(p);
}

void AIMode::playAsBot()
{
    if (starting == 'p')
    {
        // bot places o point
        
        OPoint op;
        
        int level = -1;
        
        if (difficulty == 1) level = playDifficulty1('o');
        if (difficulty == 2) level = playDifficulty2('o');
        if (difficulty == 3) level = playDifficulty3('o');
        if (difficulty == 4) level = playDifficulty4('o');
        
        op.setToLevel(level);
        oPoints.push_back(op);
        
        soundManager.clickSound2.play();
        
    }
    
    else
    {
        // bot places x point
        
        XPoint xp;
        
        int level = -1;
        
        if (difficulty == 1) level = playDifficulty1('x');
        if (difficulty == 2) level = playDifficulty2('x');
        if (difficulty == 3) level = playDifficulty3('x');
        if (difficulty == 4) level = playDifficulty4('x');
        
        xp.setToLevel(level);
        xPoints.push_back(xp);
        
        soundManager.clickSound.play();
        
    }
}

AIMode::AIMode(std::vector<XPoint>& xps, std::vector<OPoint>& ops, std::string& b, SoundManager& sm, sf::RenderWindow& w, int d)
: Mode{xps, ops, b, sm, w}, difficulty{d}
{
    /*board = "xoxoxonnn";
    
    XPoint xp;
    XPoint xp2;
    XPoint xp3;
    
    OPoint op;
    OPoint op2;
    OPoint op3;
    
    xp.setToLevel(1);
    xp2.setToLevel(7);
    xp3.setToLevel(5);
    
    op.setToLevel(2);
    op2.setToLevel(4);
    op3.setToLevel(6);
    
    xPoints.push_back(xp);
    xPoints.push_back(xp2);
    //xPoints.push_back(xp3);
    //oPoints.push_back(op);
    oPoints.push_back(op2);
    //oPoints.push_back(op3); */
}

void AIMode::inIntersect(sf::Event& event, std::vector<sf::RectangleShape>& boardRectangles) {
    int mouseX = event.mouseButton.x;
    int mouseY = event.mouseButton.y;
    
    sf::RectangleShape rec {sf::Vector2f{1, 1}};
    
    rec.setPosition(sf::Vector2f{(float) mouseX, (float) mouseY});
    
    for (int i = 0; i < 9; i++) {
        if (rec.getGlobalBounds().intersects(boardRectangles[i].getGlobalBounds()))
        {
            int lvl = i+1;
            
            if (pointExistInLevel(xPoints, oPoints, lvl) != 'n') break;
            
            // intersect
            
            if (turn == 'p' && starting == 'p')
            {
                
                XPoint xp;
                xp.setToLevel(lvl);
                xPoints.push_back(xp);
        
                turn = 'b';
                
                board = boardInString(xPoints, oPoints);
                
                //std::cout << "fbm('x'): " << minimax("xxonooxnx", 10, false) << "jj\n\n\n";
                
                /*LightVirtualBoard vb;
                vb.strToBoard(board);
                
                for (auto e : getAvailableLevels(vb.strBoard))
                {
                    std::cout << e;
                } std::cout << '\n';*/
                
                //std::cout << minimax(board, 20, true) << '\n';
                
                soundManager.clickSound.play();
                break;
            }
            
            if (turn == 'p' && starting == 'b')
            {
                //std::cout << "fbm('o'): " << findBestMove('o') << "jj\n";
                
                OPoint op;
                op.setToLevel(lvl);
                oPoints.push_back(op);
                
                turn = 'b';
                
                board = boardInString(xPoints, oPoints);
                
                //std::cout << minimax(board, 20, false) << '\n';
                
                //findBestMove('o');
                
                soundManager.clickSound2.play();
                break;
            }
            
        }
    }
}

void AIMode::pollEvent(sf::Event&) {}

void AIMode::update() {
    static sf::Clock clock;
    static bool pointplace = false;
    
    char tttstate = checkState(board);
    
    if (turn == 'b' && tttstate == 'n')
    {
        
        if (!pointplace)
        {
            pointplace = true;
            clock.restart();
            return;
        }
        
        else if (!(clock.getElapsedTime().asSeconds() >= 0.5)) return; // waits 0.5 seconds
        
        // bot places point
        
        playAsBot();
        
        pointplace = false;
        turn = 'p';
    }
    
}

void AIMode::draw() {
    /*for (auto& e : vb.xPoints)
    {
        e.usingTexture = 'r';
        e.draw(window);
    }
    for (auto& e : vb.oPoints)
    {
        e.usingTexture = 'r';
        e.draw(window);
    }*/
}
