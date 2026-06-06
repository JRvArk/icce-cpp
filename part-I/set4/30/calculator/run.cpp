#include "calculator.h"

void Calculator::run()
{
    std::cout << "? ";
    while (d_parser.reset())
    {
        if (expression())
            process();
        else
            print_usage_message();
        std::cout << "? ";
    }
}
