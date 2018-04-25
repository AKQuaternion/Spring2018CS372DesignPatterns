#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <string>
#include <memory>

class ArmorComponent {
public:
    virtual ~ArmorComponent() = default;
    virtual std::string description() const=0 ;
    virtual int getAC() const=0 ;
};

class Armor : public ArmorComponent {
public:
private:
};

class ArmorDecorator : public ArmorComponent {
public:
    ArmorDecorator(unique_ptr<ArmorComponent> wrappee)
    :_wrappee(std::move(wrappee))
    {}
    std::string description() const override {
        return _wrappee->description();
    }
    int getAC() const override {
        return _wrappee->getAC();
    }
private:
    std::unique_ptr<ArmorComponent> _wrappee;
};

class RustyDecorator : public ArmorDecorator {
public:
    using ArmorDecorator::ArmorDecorator;
    std::string description() const override {
        return "Rusty " + ArmorDecorator::description();
    }
    int getAC() const override {
        return ArmorDecorator::getAC() - 3;
    }
};

class PlateArmor : public Armor {
    virtual std::string description() const
    {
        return "Plate Mail";
    }
    
    virtual int getAC() const
    {
        return 10;
    }
};

class LeatherArmor : public Armor {
    virtual std::string description() const
    {
        return "Leather Armor";
    }
    
    virtual int getAC() const
    {
        return 3;
    }
};

#endif
