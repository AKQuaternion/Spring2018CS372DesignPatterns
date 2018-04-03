//
//  Composite.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/26/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#ifndef Composite_hpp
#define Composite_hpp
#include <vector>
#include <memory>
#include <string_view>
#include <string>

class Visitor;

class Component {
public:
    Component(std::string_view name);
    ~Component();
    virtual void print()  const=0;
    virtual int getSize() const=0;
    virtual void accept(const Visitor *) const=0;
    std::string getName() const;
private:
    const std::string _name;
};

class File : public Component
{
public:
    File(std::string_view name, int size);
    virtual void print()  const override;
    virtual int getSize() const override;
    virtual void accept(const Visitor *) const override;
private:
    int _size;
};

class Folder : public Component
{
public:
    using Component::Component;
    using ChildContainer = std::vector<std::unique_ptr<Component>>;
    virtual void print()  const override;
    virtual int getSize() const override;
    virtual void accept(const Visitor *) const override;
    void add(std::unique_ptr<Component>);
    void remove(std::string_view name);
    const ChildContainer & getChildren() const;
private:
    ChildContainer _children;
};

#endif /* Composite_hpp */
