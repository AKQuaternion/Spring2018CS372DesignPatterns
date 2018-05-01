//
//  MP3PlayerState.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/25/18.
//

#include "MP3PlayerState.hpp"
#include "MP3Player.hpp"
#include <memory>
using std::make_unique;


void MP3PlayerState::setState(MP3Player &mp3, std::unique_ptr<MP3PlayerState> newState) {
    mp3.setState(std::move(newState));
}

void MP3PlayerState::playRadio(MP3Player &mp3) {
    mp3.playRadio();
}

void MP3PlayerState::stopRadio(MP3Player &mp3) {
    mp3.stopRadio();
}

void MP3PlayerState::nextRadioStation(MP3Player &mp3) {
    mp3.nextRadioStation();
}

void MP3PlayerState::playMp3(MP3Player &mp3) {
    mp3.playMp3();
}

void MP3PlayerState::stopMp3(MP3Player &mp3) {
    mp3.stopMp3();
}

void MP3PlayerState::nextMp3(MP3Player &mp3) {
    mp3.nextMp3();
}

void PlayingMP3::pushNextButton(MP3Player &mp3) {
    nextMp3(mp3);
}

void PlayingMP3::pushSourceButton(MP3Player &mp3){
    stopMp3(mp3);
    setState(mp3,make_unique<Off>());
}

void PlayingRadio::pushNextButton(MP3Player &mp3){
    nextRadioStation(mp3);
}

void PlayingRadio::pushSourceButton(MP3Player &mp3){
    stopRadio(mp3);
    setState(mp3,make_unique<PlayingMP3>());
    playMp3(mp3);
}

void Off::pushNextButton(MP3Player & /*mp3*/){
}

void Off::pushSourceButton(MP3Player &mp3){
    setState(mp3,make_unique<PlayingRadio>());
    playRadio(mp3);
}

