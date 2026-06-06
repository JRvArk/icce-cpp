#include <iostream>
#include "parser/parser.h"

int main()
{
    Parser parser;

    while (parser.reset())
    {
        double value;
        Parser::Return result;

        while ((result = parser.number(&value)) != Parser::Return::EOLN)
        {
            if (result == Parser::Return::NUMBER)
                std::cout << value
                          << (parser.isIntegral() ? " (integral)\n" : " (float)\n");
            else
                std::cout << "not a number\n";
        }
    }
}
