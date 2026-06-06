#include "parser.h"

Parser::Return Parser::number(double *dest)
{
    std::string str{this->next()}; // get the next string

    if (str.empty())
        return Return::EOLN; // no string available

    return convert(dest, str); // try to convert to number
}