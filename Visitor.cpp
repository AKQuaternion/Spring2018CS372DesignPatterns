//
//  Visitor.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/2/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include "Composite.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>

namespace {
    void tab(int n)
    {
        for(
    }
}
Visitor::~Visitor() = default;

void RecursiveListingVisitor::visit(const File *f)
{
    cout << std::setw(4*_depth) << " " << std::left << std::setw(13) << f->getName();
    cout << std::right << std::setw(10) << f->getSize() << endl;
}

void RecursiveListingVisitor::visit(const Folder *f) 
{
    cout << std::left << std::setw(13) << f->getName();
    cout << std::right << std::setw(10) << f->getSize() << endl;
    ++_depth;
    for(const auto &childPtr : f->getChildren())
        childPtr->accept(this);
    --_depth;
}

