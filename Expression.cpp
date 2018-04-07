//
//  Expression.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include "Expression.hpp"
using std::unique_ptr;
#include <map>

Expression::~Expression() = default;

Sum::Sum(unique_ptr<Expression> lhs, unique_ptr<Term> rhs)
:_lhs(std::move(lhs)),_rhs(std::move(rhs))
{}

std::string Sum::toString()
{
    return _lhs->toString() + "+" + _rhs->toString();
}

double Sum::evaluate(const std::map<std::string,double> &context)
{
    return _lhs->evaluate(context) + _rhs->evaluate(context);
}

Difference::Difference(unique_ptr<Expression> lhs, unique_ptr<Term> rhs)
:_lhs(std::move(lhs)),_rhs(std::move(rhs))
{}

std::string Difference::toString()
{
    return _lhs->toString() + "-" + _rhs->toString();
}

double Difference::evaluate(const std::map<std::string,double> &context)
{
    return _lhs->evaluate(context) - _rhs->evaluate(context);
}

Product::Product(unique_ptr<Term> lhs, unique_ptr<Factor> rhs)
:_lhs(std::move(lhs)),_rhs(std::move(rhs))
{}

std::string Product::toString()
{
    return _lhs->toString() + "*" + _rhs->toString();
}

double Product::evaluate(const std::map<std::string,double> &context)
{
    return _lhs->evaluate(context) * _rhs->evaluate(context);
}

Quotient::Quotient(unique_ptr<Term> lhs, unique_ptr<Factor> rhs)
:_lhs(std::move(lhs)),_rhs(std::move(rhs))
{}

std::string Quotient::toString()
{
    return _lhs->toString() + "/" + _rhs->toString();
}

double Quotient::evaluate(const std::map<std::string,double> &context)
{
    return _lhs->evaluate(context) / _rhs->evaluate(context);
}

Number::Number(double value) :_value(value)
{}

double Number::evaluate(const std::map<std::string,double> &context)
{
    return _value;
}

std::string Number::toString()
{
    return std::to_string(_value);
}

Variable::Variable(std::string name):_name(name)
{}

double Variable::evaluate(const std::map<std::string,double> &context)
{
    return context.at(_name);
}

std::string Variable::toString()
{
    return _name;
}

Parenthetical::Parenthetical(unique_ptr<Expression> expression)
:_expression(std::move(expression))
{}

std::string Parenthetical::toString()
{
    return "("+ _expression->toString() + ")";
}

double Parenthetical::evaluate(const std::map<std::string,double> &context)
{
    return _expression->evaluate(context);
}
