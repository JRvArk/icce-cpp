#include "calculator.h"

void Calculator::print_usage_message()
{
    std::cout << "Usage: number operator number\n"
                 "Operators: + - * / %\n"
                 "% requires non-negative integers on both sides\n";
}
