
#include <iosfwd>

enum class Hallo
{
    First = 5,
    Second = 6,
    Third = 7,
    Fourth = 8,
    Fifth = 11
};

std::ostream & operator << (std::ostream &, const Hallo&);

