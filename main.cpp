//
//  main.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;
using std::move;
#include "Expression.hpp"
using std::map;
using std::string;
#include "Composite.hpp"
#include "Visitor.hpp"
#include "Subject.hpp"
#include "Observer.hpp"
#include "Armor.hpp"
#include "Command.hpp"
using std::vector;

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
//    auto f1 = make_unique<File>("f1",1);
//    cout << f1->getName() << " " << f1->getSize() << endl;
//    auto folder1 = make_unique<Folder>("folder1");
//    folder1->add(move(f1));
//    cout << folder1->getName() << " " << folder1->getSize() << endl;
//    folder1->add(make_unique<File>("f2",2));
//    folder1->add(make_unique<File>("f3",3));
//    cout << folder1->getName() << " " << folder1->getSize() << endl;
//    folder1->remove("f2");
//    cout << folder1->getName() << " " << folder1->getSize() << endl;
    
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

void testObserver() {
    Subject s;
    
    auto co = make_shared<CoutObserver>();
    auto co2 = make_shared<CoutObserver>();
    auto bo = make_shared<BarGraphObserver>();
    s.attach(co);
    s.attach(co);
    s.attach(co2);
    s.attach(bo);
    
    s.setN(13);
    s.detach(co2);
    s.setN(67);
    s.detach(co);
    s.setN(1);
    
    unique_ptr<ArmorComponent> plate = make_unique<PlateArmor>();
    cout << plate->description() << endl;
    unique_ptr<ArmorComponent> rustyPlate = make_unique<RustyDecorator>(move(plate));
    cout << rustyPlate->description() << endl;
    unique_ptr<ArmorComponent> rustyrustyPlate = make_unique<RustyDecorator>(move(rustyPlate));
    cout << rustyrustyPlate->description() << endl;
}

void foo() {
    cout << "Foo!\n";
}

void testCommand() {
    vector<unique_ptr<Command>> buttons(10);
    for(auto &b:buttons)
        b = make_unique<NullCommand>();
    
    buttons[0] = make_unique<ThrowCommand>();
    buttons[1] = make_unique<HelloCommand>();
    
    shared_ptr<HomeAutomationComponent> light = make_shared<LightObject>();
    shared_ptr<HomeAutomationComponent> stereo = make_shared<StereoObject>();
    
    buttons[3] = make_unique<HomeAutomationOnCommand>(light);
    buttons[4] = make_unique<HomeAutomationOffCommand>(light);
    buttons[5] = make_unique<HomeAutomationOnCommand>(stereo);
    buttons[6] = make_unique<HomeAutomationOffCommand>(stereo);
    
    buttons[7] = make_unique<MacroCommand>(vector<shared_ptr<Command>>{make_shared<HomeAutomationOnCommand>(light),
        make_shared<HomeAutomationOnCommand>(stereo),
        make_shared<AnyCommand>([](){cout << "We're done!\n";}),
        make_shared<AnyCommand>(foo)
    });
    
    while (1) {
        cout << "Which button? " << endl;
        int b;
        cin >> b;
        if (b==-1)
            return;
        buttons[b]->execute();
    }
}

int main() {
//    testComposite();
    testCommand();
    
    return 0;
}
