//
//  Composite.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/26/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include "Composite.hpp"
#include "Visitor.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::move;

Component::Component(std::string_view name):_name(name)
{}

Component::~Component() = default;

std::string Component::getName() const
{
    return _name;
}

File::File(std::string_view name, int size):Component(name),_size(size)
{}

void File::print() const
{
    cout << getName() << "   " << _size;
}

int File::getSize() const
{
    return _size;
}

void File::accept(const Visitor *vPtr) const
{
    vPtr->visit(this);
}

void Folder::print() const
{
    cout << "Folder: " << getName() << "   " << getSize() << endl;
}


int Folder::getSize() const
{
    int total = 0;
    for(const auto &c :_children)
        total += c->getSize();
    return total;
}

void Folder::accept(const Visitor *vPtr) const
{
    vPtr->visit(this);
}

void Folder::add(std::unique_ptr<Component> child)
{
    _children.push_back(move(child));
}


void Folder::remove(std::string_view name)
{
    for(auto i = _children.begin(); i != _children.end(); ++i)
        if ((*i)->getName() == name){
            _children.erase(i);
            return;
        }
}


const Folder::ChildContainer & Folder::getChildren() const
{
    return _children;
}


