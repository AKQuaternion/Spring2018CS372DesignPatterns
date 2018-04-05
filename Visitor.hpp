//
//  Visitor.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 4/2/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#ifndef Visitor_hpp
#define Visitor_hpp

class File;
class Folder;

class Visitor
{
public:
    virtual void visit(const File *) =0;
    virtual void visit(const Folder *) =0;
    ~Visitor();
};

class RecursiveListingVisitor : public Visitor
{
public:
    virtual void visit(const File *) override;
    virtual void visit(const Folder *) override;
private:
    int _depth=0;
};

#endif /* Visitor_hpp */
