//
//  Command.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/16/18.
//

#ifndef Command_hpp
#define Command_hpp
#include <utility>
#include <iostream>
#include <memory>
#include <vector>

class Command {
public:
    virtual ~Command(){}
    virtual void execute() const = 0;
private:
    
};

class HelloCommand  : public Command {
public:
    void execute() const override {
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

class LightObject : public HomeAutomationComponent {
public:
    void on() override {
        std::cout << "light is on\n";
    }
    void off() override {
        std::cout << "light is off\n";
    }
private:
};

class StereoObject : public HomeAutomationComponent {
public:
    void on() override {
        std::cout << "stereo is on\n";
    }
    void off() override {
        std::cout << "stereo is off\n";
    }
private:
};

class HomeAutomationOnCommand : public Command {
public:
    HomeAutomationOnCommand(std::shared_ptr<HomeAutomationComponent> hac)
    :_receiver(hac)
    {}
    void execute() const override {
        _receiver->on();
    }
private:
    std::shared_ptr<HomeAutomationComponent> _receiver;
};

class HomeAutomationOffCommand : public Command {
public:
    HomeAutomationOffCommand(std::shared_ptr<HomeAutomationComponent> hac)
    :_receiver(hac)
    {}
    void execute() const override {
        _receiver->off();
    }
private:
    std::shared_ptr<HomeAutomationComponent> _receiver;
};

class MacroCommand : public Command {
public:
    MacroCommand(const std::vector<std::shared_ptr<Command>> &commands):_commands(commands)
    {}
    void execute() const override
    {
        for(auto c:_commands)
            c->execute();
    }
private:
    std::vector<std::shared_ptr<Command>> _commands;
};

class AnyCommand : public Command
{
public:
    AnyCommand(std::function<void ()> f):_f(f)
    {}
    void execute() const override{
        _f();
    }
private:
    std::function<void ()> _f;
};

class NullCommand : public Command
{
public:
    void execute() const override {
    }
};

class ThrowCommand : public Command
{
public:
    void execute() const override {
        throw 0;
    }
};

class Door {
public:
    virtual void open() =0;
    virtual void close() =0;
private:
};

class HouseDoor : public Door {
    void open() override {
        std::cout << "Turning knob to open door\n";
    }
    void close() override {
        std::cout << "Turning knob to close door\n";
    }
};

class GarageDoor : public Door {
    void open() override {
        std::cout << "Pushing button to open door\n";
    }
    void close() override {
        std::cout << "Pushing button to close door\n";
    }
};
#endif /* Command_hpp */
