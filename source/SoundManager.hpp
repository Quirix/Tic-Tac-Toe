//
//  SoundManager.hpp
//  sfml proj
//
//  Created by Quirix Wastaken on 8/7/24.
//

#pragma once

#include <SFML/Audio.hpp>

class SoundManager {
public:
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer2;
    sf::SoundBuffer buffer3;
    sf::SoundBuffer buffer4;
    sf::SoundBuffer buffer5;
    
    sf::Sound clickSound{};
    sf::Sound clickSound2{};
    sf::Sound lwdsound{};
    sf::Sound onreplaysound{};
    sf::Sound releaseSound{};
    
public:
    
    SoundManager();
    
};
