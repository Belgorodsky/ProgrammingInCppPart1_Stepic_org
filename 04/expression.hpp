#pragma once
#include <cmath>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    double evaluate() const { return value; }
private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), right(right), op(op)
    { }

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

    double evaluate() const
    {
        double actual_l = left->evaluate();
        double actual_r = right->evaluate();
        switch(op)
        {
            case '*':
                return actual_l * actual_r;
            case '+':
                return actual_l + actual_r;
            case '-':
                return actual_l - actual_r;
            case '/':
                return actual_l / actual_r;
            default:
                return FP_NAN;
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
