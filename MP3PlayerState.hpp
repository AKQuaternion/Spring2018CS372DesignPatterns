//
//  MP3PlayerState.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/25/18.
//

#ifndef MP3PlayerState_hpp
#define MP3PlayerState_hpp

class MP3Player;

class MP3PlayerState {
public:
    virtual void pushNextButton(MP3Player &mp3)=0;
    virtual void pushSourceButton(MP3Player &mp3)=0;
private:
    
};

class PlayingMP3 : public MP3PlayerState {
public:
    void pushNextButton(MP3Player &mp3) override;
    void pushSourceButton(MP3Player &mp3) override;
private:
};

class PlayingRadio : public MP3PlayerState {
public:
    void pushNextButton(MP3Player &mp3) override;
    void pushSourceButton(MP3Player &mp3) override;
private:
};

class Off : public MP3PlayerState {
public:
    void pushNextButton(MP3Player &mp3) override;
    void pushSourceButton(MP3Player &mp3) override;
private:
};
#endif /* MP3PlayerState_hpp */
