#include "parser.h"

Parser::Return Parser::convert(double *dest, std::string const &str)
try
{
    return pureDouble(dest, str) ? Return::NUMBER : Return::NO_NUMBER;
}
catch (...) // conversion failed
{
    return Return::NO_NUMBER;
}
