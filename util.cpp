#include "util.h"
#include <stdexcept>
#include <string>

std::istream &operator>>(std::istream &in, Direction &direction)
{
    std::string s;
    in >> s;
    if (s == "up" || s == "u")
        direction = Direction::up;
    else if (s == "down" || s == "d")
        direction = Direction::down;
    else if (s == "left" || s == "l")
        direction = Direction::left;
    else if (s == "right" || s == "r")
        direction = Direction::right;
    else
        throw std::runtime_error{"Error: Unrecognized direction."};
    return in;
}

std::ostream &operator<<(std::ostream &out, const Direction &direction)
{
    switch (direction)
    {
    case Direction::up:
        out << "up";
    case Direction::down:
        out << "down";
    case Direction::left:
        out << "left";
    case Direction::right:
        out << "right";
    }
    return out;
}
