#include "parser.h"

bool Parser::pureDouble(double *dest, std::string const &str)
{
    size_t end;
    double value = stod(str, &end); // convert to double

    if (end != str.length()) // non-value characters found
        return false;

    d_isIntegral = str.find_first_of(".eE") == std::string::npos;

    *dest = value; // conversion OK
    return true;
}