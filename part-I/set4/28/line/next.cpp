#include "line.h"

std::string Line::next()
{
    size_t start = d_current_line.find_first_not_of(" \t", d_position);
    if (start == std::string::npos)
        return "";

    size_t end = d_current_line.find_first_of(" \t", start);
    d_position = (end == std::string::npos) ? d_current_line.size() : end;
    return d_current_line.substr(start, end - start);
}
