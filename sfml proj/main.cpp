// 22/6/24

#include "Xpoint.hpp"
#include "OPoint.hpp"
#include "PointClass.hpp"
#include "Functions.hpp"
#include "Game.hpp"
#include <iostream>
#include <sstream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    
    Game game;
    
    sf::RenderWindow& window = game.window;
    
    
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            game.pollEvent(event);
        } // pollEvent
        //--Update--//

        game.update();
        
        // havent implemented what happens when you lose/draw/win, startscreen and menu.
        
        
        //--Update--//
        window.clear(sf::Color::White);
        // drawing
        
        game.draw();
        
        
        window.display();
    }
    
    return 0;
}
