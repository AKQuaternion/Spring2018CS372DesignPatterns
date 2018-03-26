//
//  Expression.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//
//  E -> T | E+T | E-T
//  T -> F | T*F | T/F
//  F -> variable | number | (E)

#ifndef Expression_hpp
#define Expression_hpp
#include <memory>
#include <string>
#include <map>

class Expression {
public:
    virtual ~Expression();
    virtual double evaluate(const std::map<std::string,double> &context) = 0;
    virtual std::string toString() = 0;
private:
};

class Term : public Expression
{};

class Sum : public Expression
{
public:
    Sum(std::unique_ptr<Expression> lhs, std::unique_ptr<Term> rhs);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Expression> _lhs;
    std::unique_ptr<Term> _rhs;
};

class Difference : public Expression
{
public:
    Difference(std::unique_ptr<Expression> lhs, std::unique_ptr<Term> rhs);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Expression> _lhs;
    std::unique_ptr<Term> _rhs;
};

class Factor : public Term
{};

class Product : public Term
{
public:
    Product(std::unique_ptr<Term> lhs, std::unique_ptr<Factor> rhs);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Term> _lhs;
    std::unique_ptr<Factor> _rhs;
};

class Quotient : public Term
{
public:
    Quotient(std::unique_ptr<Term> lhs, std::unique_ptr<Factor> rhs);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Term> _lhs;
    std::unique_ptr<Factor> _rhs;
};

class Number : public Factor
{
public:
    Number(double);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    double _value;
};

class Variable : public Factor
{
public:
    Variable(std::string name);
    virtual double evaluate(const std::map<std::string,double> &context);
    virtual std::string toString();
private:
    std::string _name;
};

class Parenthetical : public Factor
{
public:
    Parenthetical(std::unique_ptr<Expression>);
    virtual double evaluate(const std::map<std::string,double> &context) override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Expression> _expression;
};

#endif /* Expression_hpp */
