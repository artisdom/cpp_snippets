#include <iostream>
#include <iterator>
#include <string>
#include <regex>
 
using namespace std;

int main(int argc, char *argv[])
{
    string var = "first second third forth";

    regex wsaq_re("\\s+"); 
    copy( sregex_token_iterator(var.begin(), var.end(), wsaq_re, -1),
          sregex_token_iterator(),
          ostream_iterator<string>(cout, "\n"));
    
    return 0;
}
