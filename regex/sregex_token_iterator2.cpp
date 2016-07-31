#include <iostream>
#include <iterator>
#include <string>
#include <regex>
 
using namespace std;

int main(int argc, char *argv[])
{
    string var = "KEYPAD_NUMERIC_ONLY = 0, \nKEYPAD_NUMERIC_FIRST = 1, KEYPAD_ALPHA_ONLY = 2, \nKEYPAD_ALPHA_FIRST = 3, \nKEYPAD_UNKNOWN";

    //regex wsaq_re("\\s+"); 
    regex regex_enum("/(\w+)\s*(?:=\s*(\d+)|)\s*,?\s*(?:(?:\n|$)|\/\/.*?(?:\n|$)|)/");
    copy( sregex_token_iterator(var.begin(), var.end(), regex_enum, -1),
          sregex_token_iterator(),
          ostream_iterator<string>(cout, "\n"));
    
    return 0;
}
