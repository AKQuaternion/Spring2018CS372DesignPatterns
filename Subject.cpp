//
//  Subject.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/13/18.
//

#include "Subject.hpp"
#include <algorithm>

void Subject::attach(std::shared_ptr<Observer> o){
    _observers.insert(o);
}

void Subject::detach(std::shared_ptr<Observer> o){
    _observers.erase(std::find(_observers.begin(),_observers.end(),o));
}

void Subject::notify() const{
    for (const auto &o:_observers)
        o->update(_n);
}

void Subject::setN(int n)
{
    _n = n;
    notify();
}

