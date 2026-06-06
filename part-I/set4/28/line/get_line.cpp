#include "line.h"

bool Line::getLine()
{
    d_current_line.clear();
    std::getline(std::cin, d_current_line);
    if (d_current_line.find_first_not_of(" \t") == std::string::npos)
    {
        return false;
    }
    d_position = 0;
    return true;
}