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
