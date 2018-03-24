//
//  Expression.hpp
//  DesignPatterns
//
//  Created by Chris Hartman on 3/19/18.
//  Copyright © 2018 Chris Hartman. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp
#include <memory>
#include <string>
class Expression {
public:
    virtual ~Expression();
    virtual double evaluate() = 0;
    virtual std::string toString() = 0;
private:
};

class Number : public Expression
{
public:
    Number(double);
    virtual double evaluate() override;
    virtual std::string toString() override;
private:
    double _value;
};

class SumExpression : public Expression
{
public:
    SumExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);
    virtual double evaluate() override;
    virtual std::string toString() override;
private:
    std::unique_ptr<Expression> _lhs;
    std::unique_ptr<Expression> _rhs;
};

#endif /* Expression_hpp */
