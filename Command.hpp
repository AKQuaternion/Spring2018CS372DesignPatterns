//
//  Command.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/16/18.
//

#ifndef Command_hpp
#define Command_hpp
#include <iostream>
#include <memory>

class Command {
public:
    virtual ~Command(){}
    virtual void execute() = 0;
private:
    
};

class HelloCommand  : public Command {
public:
    void execute() {
        std::cout << "Hello\n";
    }
};

class HomeAutomationComponent {
public:
    virtual ~HomeAutomationComponent(){}
    virtual void on()=0;
    virtual void off()=0;
private:
};

class Fan : public HomeAutomationComponent {
public:
    virtual void on() {
        std::cout << "Fan is on.\n";
    }
    virtual void off(){
        std::cout << "Fan is off.\n";
    }
};

class HomeAutomationOnCommand : public Command {
public:
    HomeAutomationOnCommand(std::shared_ptr<HomeAutomationComponent> hac)
    :_hac(hac)
    {}
    void execute() {
        _hac->on();
    }
private:
    std::shared_ptr<HomeAutomationComponent> _hac;
};
#endif /* Command_hpp */
