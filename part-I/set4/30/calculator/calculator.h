#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../../29/parser/parser.h"

#include <iostream>
#include <string>

class Calculator
{
    enum class Operator
    {
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        MODULO,
    };

    Parser d_parser;
    bool d_lhs_isInt = false;
    bool d_rhs_isInt = false;
    double d_lhs = 0.0;
    double d_rhs = 0.0;
    Operator d_operator = Operator::ADDITION;

public:
    void run();

private:
    bool expression();
    void process();
    bool number(double *dest, bool *isInt);
    bool get_operator();
    void print_usage_message();
};

#endif