//
//  SoundManager.cpp
//  sfml proj
//
//  Created by Quirix Wastaken on 8/7/24.
//

#include "SoundManager.hpp"

#include <iostream>

SoundManager::SoundManager() {
    if (!buffer.loadFromFile("Sounds/clicksound5.wav"))
        std::cerr << "(GameRunning.cpp) error in constructor GameRun::GameRun(), sound buffer cannot load\n";
    
    if (!buffer2.loadFromFile("Sounds/clicksound6.wav"))
        std::cerr << "(GameRunning.cpp) error in constructor GameRun::GameRun(), sound buffer cannot load\n";
    
    if (!buffer3.loadFromFile("Sounds/winsound.wav"))
        std::cerr << "(GameRunning.cpp) error in constructor GameRun::GameRun(), sound buffer cannot load\n";
    
    if (!buffer4.loadFromFile("Sounds/replaysound.wav"))
        std::cerr << "(GameRunning.cpp) error in constructor GameRun::GameRun(), sound buffer cannot load\n";
    
    if (!buffer5.loadFromFile("Sounds/releaseclick.mp3"))
        std::cerr << "(GameRunning.cpp) error in constructor GameRun::GameRun(), sound buffer cannot load\n";
    
    clickSound.setBuffer(buffer);
    clickSound.setVolume(5000);
    
    clickSound2.setBuffer(buffer2);
    clickSound2.setVolume(5000);
    
    lwdsound.setBuffer(buffer3);
    lwdsound.setVolume(5000);
    
    onreplaysound.setBuffer(buffer4);
    onreplaysound.setVolume(5000);
    
    releaseSound.setBuffer(buffer5);
    releaseSound.setVolume(15);
}
