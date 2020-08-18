#ifndef UTIL_H
#define UTIL_H
#include <iostream>

enum class Direction
{
    up,
    down,
    left,
    right
};

std::istream &operator>>(std::istream &in, Direction &direction);
std::ostream &operator<<(std::ostream &out, const Direction &direction);

#endif
