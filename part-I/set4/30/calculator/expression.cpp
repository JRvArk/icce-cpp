#include "calculator.h"

bool Calculator::expression()
{
    return number(&d_lhs, &d_lhs_isInt)
        && get_operator()
        && number(&d_rhs, &d_rhs_isInt);
}
