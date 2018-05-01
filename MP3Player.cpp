//
//  MP3Player.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/25/18.
//

#include "MP3Player.hpp"

void MP3Player::setState(std::unique_ptr<MP3PlayerState> newState) {
    _state = std::move(newState);
}

MP3Player::MP3Player(std::unique_ptr<MP3PlayerState> newState)
:_state(std::move(newState))
{}

void MP3Player::pushSourceButton() {
    _state->pushSourceButton(*this);
}

void MP3Player::pushNextButton() {
    _state->pushNextButton(*this);
}
