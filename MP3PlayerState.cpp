//
//  MP3PlayerState.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/25/18.
//

#include "MP3PlayerState.hpp"
#include "MP3Player.hpp"

void PlayingMP3::pushNextButton(MP3Player &mp3) {
    mp3.nextMp3();
}

void PlayingMP3::pushSourceButton(MP3Player &mp3){
    
}

void PlayingRadio::pushNextButton(MP3Player &mp3){
    mp3.nextRadioStation();
}

void PlayingRadio::pushSourceButton(MP3Player &mp3){
    
}

void Off::pushNextButton(MP3Player & /*mp3*/){
}

void Off::pushSourceButton(MP3Player &mp3){
    
}

