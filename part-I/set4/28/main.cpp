#include "./line/line.h"

int main()
{
    Line line;

    while (line.getLine())
    {
        std::cout << line.next() << '\n';
    }
}