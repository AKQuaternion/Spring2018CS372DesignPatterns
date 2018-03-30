//
//  main.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;
#include "Expression.hpp"
using std::map;
using std::string;
#include "Composite.hpp"
void testExpression() {
    unique_ptr<Expression> pi = make_unique<Number>(3.14159);
    cout << pi->evaluate({}) << endl;
    unique_ptr<Term> two = make_unique<Number>(2.0);
    auto sum = make_unique<Sum>(move(pi),move(two));
    cout << sum->evaluate({}) << endl;
    cout << sum->toString() << endl;
    
    unique_ptr<Expression> diff = make_unique<Difference>(std::move(sum),make_unique<Variable>("x"));
    cout << diff->toString() << endl;
    map<string,double> context;
    context["x"] = 5.14159;
    cout << diff->evaluate(context) << endl;
    context["x"] = 13;
    cout << diff->evaluate(context) << endl;
}

int main() {
    auto f1 = make_unique<File>("f1",1);
    cout << f1->getName() << " " << f1->getSize() << endl;
    auto folder1 = make_unique<Folder>("folder1");
    folder1->add(move(f1));
    cout << folder1->getName() << " " << folder1->getSize() << endl;
    folder1->add(make_unique<File>("f2",2));
    folder1->add(make_unique<File>("f3",3));
    cout << folder1->getName() << " " << folder1->getSize() << endl;
    folder1->remove("f2");
    cout << folder1->getName() << " " << folder1->getSize() << endl;

    return 0;
}
