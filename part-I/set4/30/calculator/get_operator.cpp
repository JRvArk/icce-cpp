#include "calculator.h"

bool Calculator::get_operator()
{
    std::string op = d_parser.next();
    if      (op == "+") d_operator = Operator::ADDITION;
    else if (op == "-") d_operator = Operator::SUBTRACTION;
    else if (op == "*") d_operator = Operator::MULTIPLICATION;
    else if (op == "/") d_operator = Operator::DIVISION;
    else if (op == "%") d_operator = Operator::MODULO;
    else                return false;
    return true;
}
