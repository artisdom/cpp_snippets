#include <iostream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    string seq = "foo@helloworld.com";
    regex rgx("(.*)@(.*)");
    smatch result;

    regex_search(seq, result, rgx);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
