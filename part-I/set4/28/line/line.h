#ifndef LINE_H_
#define LINE_H_

#include <string>
#include <iostream>

class Line
{
public:
    bool getLine();
    std::string next();

private:
    std::string d_current_line;
    size_t d_position = 0;
};

#endif // LINE_H_