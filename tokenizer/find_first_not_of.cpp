#include <iostream>

using namespace std;

int char2int(char c)
{
    static const string HEX_CHARS = "0123456789abcdef";

    const char lowerC = tolower(c);

    const string::size_type pos = HEX_CHARS.find_first_of(lowerC);

    if (pos == string::npos) {
        throw runtime_error(string("Not a hex digit: ") + c);
    }
    return pos;
}

int main(int argc, char *argv[])
{
    find_first_of
    return 0;
}
