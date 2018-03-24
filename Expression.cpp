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

std::string SumExpression::toString()
{
    return "("+ _lhs->toString() + "+" + _rhs->toString()+")";
}

SumExpression::SumExpression(unique_ptr<Expression> lhs, unique_ptr<Expression> rhs)
:_rhs(std::move(rhs)),_lhs(std::move(lhs))
{}

double SumExpression::evaluate()
{
    return _lhs->evaluate() + _rhs->evaluate();
}
