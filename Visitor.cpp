//
//  Visitor.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/2/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include "Visitor.hpp"
#include <iostream>
using std::cout;
using std::endl;

Visitor::~Visitor() = default;

void RecursiveListingVisitor::visit(const File *f) const
{
    cout << f->getName() << "   " << f->getSize() << endl;
}

void RecursiveListingVisitor::visit(const Folder *f) const
{
    cout << f->getName() << "   " << f->getSize() << endl;
    for(const auto &childPtr : f->getChildren())
        childPtr->accept(this);
}

