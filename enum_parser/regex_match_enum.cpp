#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

void test_regex_search(const string& input)
{
    //string enum_pattern = "enum\\s+([a-zA-Z0-9_]+)\\s*{[^{}]*}\\s*([a-zA-Z0-9_]+)\\s*;";
    //string enum_pattern = "enum\\s+[:alnum:]";
    string enum_pattern = "enum\\s+\\w+\\s*\\{[^{}]*\\}\\s*;";
    regex rgx(enum_pattern);
    smatch match;

    if (regex_search(input.begin(), input.end(), match, rgx))
    {
        cout << "Match\n";

        for (auto m : match)
            cout << "  submatch " << m << '\n';

        cout << "match[1] = " << match[1] << '\n';
        cout << "match[4] = " << match[4] << '\n';
        cout << "match[5] = " << match[5] << '\n';
    }
    else
        cout << "No match\n";
}

int main(int argc, char *argv[])
{
    ifstream in("./Cpp/SocketTAL.pb.h");

    auto ss = ostringstream{};
    ss << in.rdbuf();
    auto s = ss.str();

    //cout << s << endl;

    test_regex_search(s);

/*
    try {

        regex reg(enum_pattern);
        if (regex_match(s, reg)) {
            results.emplace(s);
            found = true;
        }

    } catch (const regex_error& e) {
        logger.log(Log::LEVEL::ERROR, (string)"regex_match exception: " + e.what() + ", Key: " + key);
    }

*/

    return 0;
}

//pattern = 'enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;'

//pattern = 'typedef\s+enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;'
//pattern = re.compile(r'enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;')
//input=open("./Cpp/SocketTAL.pb.h", 'r')
