#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
    string str = "KEYPAD_NUMERIC_ONLY = 0, \
  KEYPAD_NUMERIC_FIRST = 1, \
  KEYPAD_ALPHA_ONLY = 2, \
  KEYPAD_ALPHA_FIRST = 3";

    regex regex_enum("/(\w+)\s*(?:=\s*(\d+)|)\s*,?\s*(?:(?:\n|$)|\/\/.*?(?:\n|$)|)/");
    if (regex_match(str, regex_enum)) {
        cout << "enum" << endl;
    } else {
        cout << "not match" << endl;
    }
    
    return 0;
}
