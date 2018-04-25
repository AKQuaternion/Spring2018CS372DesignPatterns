//
//  MP3Player.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/25/18.
//

#ifndef MP3Player_hpp
#define MP3Player_hpp
#include <iostream>
#include "MP3PlayerState.hpp"

class MP3Player {
public:
    void pushNextButton();
    void pushSourceButton();
    
    void playRadio() {
        std::cout << "Playing the radio.\n";
    }
    void stopRadio() {
        std::cout << "Stopping the radio.\n";
    }
    
    void nextRadioStation() {
        std::cout << "Next radio station.\n";
    }
    
    void playMp3() {
        std::cout << "Playing MP3.\n";
    }
    
    void stopMp3() {
        std::cout << "Stopping MP3.\n";
    }
    
    void nextMp3() {
        std::cout << "Next MP3.\n";
    }
};

#endif /* MP3Player_hpp */
