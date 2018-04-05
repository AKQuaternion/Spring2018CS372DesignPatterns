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

#include "Visitor.hpp"

class ComponentBase
{
public:
    ComponentBase(std::string_view name);
    virtual ~ComponentBase();
    virtual void print()  const=0;
    virtual int getSize() const=0;
    virtual void accept(Visitor *) const=0;
    std::string getName() const;
private:
    const std::string _name;
};

template <typename Derived>
class Component : public ComponentBase {
public:
    using ComponentBase::ComponentBase;
    virtual void accept(Visitor *) const override final;
};

template<typename T>
void Component<T>::accept(Visitor *v) const
{
    v->visit(static_cast<const T *>(this));
}

class File : public Component<File>
{
public:
    File(std::string_view name, int size);
    virtual void print()  const override;
    virtual int getSize() const override;
private:
    int _size;
};

class Folder : public Component<Folder>
{
public:
    using Component::Component;
    using ChildContainer = std::vector<std::unique_ptr<ComponentBase>>;
    virtual void print()  const override;
    virtual int getSize() const override;
    void add(std::unique_ptr<ComponentBase>);
    void remove(std::string_view name);
    const ChildContainer & getChildren() const;
private:
    ChildContainer _children;
};

#endif /* Composite_hpp */
