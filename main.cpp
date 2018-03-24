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

int main() {
    unique_ptr<Expression> pi = make_unique<Number>(3.14159);
    cout << pi->evaluate() << endl;
    unique_ptr<Expression> two = make_unique<Number>(2.0);
    auto sum = make_unique<SumExpression>(move(pi),move(two));
    cout << sum->evaluate() << endl;
    cout << sum->toString() << endl;
    return 0;
}
