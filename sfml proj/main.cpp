// github: @quirix

// created 22/6/24

// 25/6/24
//* havent implemented what happens when you lose/draw/win, startscreen and menu.

// 26/7/24
//* fully finished the game

#include "Xpoint.hpp"
#include "OPoint.hpp"
#include "PointClass.hpp"
#include "Functions.hpp"
#include "GameRunning.hpp"
#include "StartMenu.hpp"
#include "GameState.hpp"

#include <iostream>
#include <sstream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window {sf::VideoMode{WinWidth, WinHeight}, "Tic Tac Toe", sf::Style::Close};
    GameState state = STARTMENU;
    
    int modeGameRunning = -1;
    // -1 = normal mode, 1 = 1 ai mode difficulty, 2 = 2 ai mode difficulty and ..
    
    SoundManager soundManager;
    
    StartMenu* startMenu = new StartMenu{window, state, soundManager, modeGameRunning};
    GameRun* gameRun = nullptr;
    
    std::vector<Game*> States {startMenu, gameRun};
    
    while (window.isOpen()) {
        
        Game* currentState = returnCorrectState(States, state);
        
        if (!currentState) {
            if (state == RUNNING)
            {
                if (modeGameRunning == -1) States[1] = new GameRun{window, state, soundManager};
                else States[1] = new GameRun{window, state, soundManager, 'a', modeGameRunning};
                
                currentState = States[1];
            }
            
            if (state == STARTMENU) {
                States[0] = new StartMenu{window, state, soundManager, modeGameRunning};
                currentState = States[0];
            }
        }
        
        sf::Event event;
        while (window.pollEvent(event)) {
            
            currentState->pollEvent(event);
            
        } // pollEvent
        //--Update--//

        currentState = returnCorrectState(States, state);
        if (currentState) currentState->update();
        
        //--Update--//
        window.clear(sf::Color::White);
        
        currentState = returnCorrectState(States, state);
        if (currentState) currentState->draw();
    
        window.display();
    }
    
    return 0;
}
