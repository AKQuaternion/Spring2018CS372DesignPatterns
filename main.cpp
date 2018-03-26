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
int main() {
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

    return 0;
}
