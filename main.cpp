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
#include "Visitor.hpp"

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

void testComposite()
{
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
    
    auto nameFiles = make_unique<Folder>("nameFiles");
    nameFiles->add(make_unique<File>("Joe",20));
    nameFiles->add(make_unique<File>("Eliza",40));
    nameFiles->add(make_unique<File>("Chris",10));
    nameFiles->add(make_unique<File>("Samantha",30));
    auto fruitFiles = make_unique<Folder>("fruitFiles");
    fruitFiles->add(make_unique<File>("Banana",69));
    fruitFiles->add(make_unique<File>("Apple",131));
    fruitFiles->add(make_unique<File>("Orange",123));
    fruitFiles->add(make_unique<File>("Plum",577));
    auto onionFiles = make_unique<Folder>("Onions");
    onionFiles->add(make_unique<File>("Walla Walla",1000));
    onionFiles->add(make_unique<File>("Vidalia",1000));
    onionFiles->add(make_unique<File>("Yellow",1000));
    onionFiles->add(make_unique<File>("White",1000));
    onionFiles->add(make_unique<File>("Red",1000));
    auto veggieFiles = make_unique<Folder>("Veggies");
    veggieFiles->add(move(onionFiles));
    veggieFiles->add(make_unique<File>("Asparagus",1));
    veggieFiles->add(make_unique<File>("Broccoli",2));
    veggieFiles->add(make_unique<File>("Zucchini",3));
    auto allFiles = make_unique<Folder>("Files");
    allFiles->add(move(nameFiles));
    allFiles->add(move(fruitFiles));
    allFiles->add(move(veggieFiles));
    allFiles->add(make_unique<File>("A lone file",3994));
    cout << allFiles->getName() << " " << allFiles->getSize() << endl;

    RecursiveListingVisitor v;
    allFiles->accept(&v);
}

int main() {
    testComposite();
    return 0;
}
