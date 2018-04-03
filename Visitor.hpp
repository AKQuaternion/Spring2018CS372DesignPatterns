//
//  Visitor.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/2/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#ifndef Visitor_hpp
#define Visitor_hpp

#include "Composite.hpp"

class Visitor
{
public:
    virtual void visit(const File *) const=0;
    virtual void visit(const Folder *) const=0;
    ~Visitor();
};

class RecursiveListingVisitor : public Visitor
{
public:
    virtual void visit(const File *) const override;
    virtual void visit(const Folder *) const override;
};

#endif /* Visitor_hpp */
