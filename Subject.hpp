//
//  Subject.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/13/18.
//

#ifndef Subject_hpp
#define Subject_hpp
#include <unordered_set>
#include <memory>

#include "Observer.hpp"

class Subject {
public:
    void attach(std::shared_ptr<Observer>);
    void detach(std::shared_ptr<Observer>);
    void setN(int n);
private:
    void notify() const;
    std::unordered_set<std::shared_ptr<Observer>> _observers;
    int _n;
};

#endif /* Subject_hpp */
