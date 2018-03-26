//
//  Expression.cpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#include "Expression.hpp"
using std::unique_ptr;

Expression::~Expression() = default;

Sum::Sum(unique_ptr<Expression> lhs, unique_ptr<Term> rhs)
:_rhs(std::move(rhs)),_lhs(std::move(lhs))
{}

std::string Sum::toString()
{
    return _lhs->toString() + "+" + _rhs->toString();
}

double Sum::evaluate()
{
    return _lhs->evaluate() + _rhs->evaluate();
}

Difference::Difference(unique_ptr<Expression> lhs, unique_ptr<Term> rhs)
:_rhs(std::move(rhs)),_lhs(std::move(lhs))
{}

std::string Difference::toString()
{
    return _lhs->toString() + "+" + _rhs->toString();
}

double Difference::evaluate()
{
    return _lhs->evaluate() - _rhs->evaluate();
}

Product::Product(unique_ptr<Term> lhs, unique_ptr<Factor> rhs)
:_rhs(std::move(rhs)),_lhs(std::move(lhs))
{}

std::string Product::toString()
{
    return _lhs->toString() + "*" + _rhs->toString();
}

double Product::evaluate()
{
    return _lhs->evaluate() * _rhs->evaluate();
}

Quotient::Quotient(unique_ptr<Term> lhs, unique_ptr<Factor> rhs)
:_rhs(std::move(rhs)),_lhs(std::move(lhs))
{}

std::string Quotient::toString()
{
    return _lhs->toString() + "/" + _rhs->toString();
}

double Quotient::evaluate()
{
    return _lhs->evaluate() / _rhs->evaluate();
}

Number::Number(double value) :_value(value)
{}

double Number::evaluate()
{
    return _value;
}

std::string Number::toString()
{
    return std::to_string(_value);
}

Parenthetical::Parenthetical(unique_ptr<Expression> expression)
:_expression(std::move(expression))
{}

std::string Parenthetical::toString()
{
    return "("+ _expression->toString() + ")";
}

double Parenthetical::evaluate()
{
    return _expression->evaluate();
}
