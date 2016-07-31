#include <iostream>
#include <iterator>
#include <string>
#include <regex>
 
using namespace std;

int main(int argc, char *argv[])
{
    string s = "KEYPAD_NUMERIC_ONLY = 0,";

    regex enum_regex("/(\w+)\s*(?:=\s*(\d+)|)\s*,?\s*(?:(?:\n|$)|\/\/.*?(?:\n|$)|)/");
    
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), enum_regex);
    auto words_end = std::sregex_iterator();

    //const int N = 6;
    //std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        //if (match_str.size() > N) {
        cout << "  " << match_str << '\n';
            //}
    }
    
    return 0;
}
