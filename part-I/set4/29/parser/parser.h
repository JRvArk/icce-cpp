#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include "../../28/line/line.h"
class Parser
{
    Line d_line;
    bool d_isIntegral = false;

public:
    enum class Return
    {
        NUMBER,
        NO_NUMBER,
        EOLN,
    };

    bool reset();
    Return number(double *dest);
    bool isIntegral() const;
    std::string next();

private:
    Return convert(double *dest, std::string const &str);
    bool pureDouble(double *dest, std::string const &str);
};

#endif