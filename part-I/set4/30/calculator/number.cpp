#include "calculator.h"

bool Calculator::number(double *dest, bool *isInt)
{
    Parser::Return result = d_parser.number(dest);
    *isInt = d_parser.isIntegral();
    return result == Parser::Return::NUMBER;
}
