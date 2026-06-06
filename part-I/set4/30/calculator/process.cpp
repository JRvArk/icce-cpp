#include "calculator.h"
#include <cmath>

void Calculator::process()
{
    bool rhsIsZero = std::abs(d_rhs) < 1e-8;
    switch (d_operator)
    {
    case Operator::ADDITION:
        std::cout << (d_lhs + d_rhs) << '\n';
        break;
    case Operator::SUBTRACTION:
        std::cout << (d_lhs - d_rhs) << '\n';
        break;
    case Operator::MULTIPLICATION:
        std::cout << (d_lhs * d_rhs) << '\n';
        break;
    case Operator::DIVISION:
        if (rhsIsZero)
        {
            std::cout << "Error: division by zero\n";
            break;
        }
        std::cout << (d_lhs / d_rhs) << '\n';
        break;
    case Operator::MODULO:
        if (rhsIsZero)
        {
            std::cout << "Error: modulo by zero\n";
            break;
        }
        if (!d_lhs_isInt || !d_rhs_isInt || d_lhs < 0 || d_rhs < 0)
        {
            std::cout << "Error: modulo requires non-negative integers\n";
            break;
        }
        std::cout << (static_cast<long long>(d_lhs) % static_cast<long long>(d_rhs)) << '\n';
        break;
    }
}
