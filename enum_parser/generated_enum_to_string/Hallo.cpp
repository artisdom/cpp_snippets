
#include <ostream>

#include "Hallo.h"

std::ostream & operator << (std::ostream &out, const Hallo&value)
{
    switch(value)
    {
    case Hallo::First:
        out << "First";
        break;
    case Hallo::Second:
        out << "Second";
        break;
    case Hallo::Third:
        out << "Third";
        break;
    case Hallo::Fourth:
        out << "Fourth";
        break;
    case Hallo::Fifth:
        out << "Fifth";
        break;
    default:
        out << "<unknown>";
    }

    return out;
}

