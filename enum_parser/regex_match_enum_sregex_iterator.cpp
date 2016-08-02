#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("./Cpp/SocketTAL.pb.h");

    auto ss = ostringstream{};
    ss << in.rdbuf();
    auto str = ss.str();

    //cout << str << endl;

    string enum_pattern = "enum\\s+\\w+\\s*\\{[^{}]*\\}\\s*;";
    regex reg(enum_pattern);

    sregex_iterator it(str.begin(), str.end(), reg);
    sregex_iterator it_end;

    while (it != it_end) {
        smatch result = *it;

        cout << "result.size(): " << result.size() << endl;
        cout << it->str() << endl;
        cout << "(*it)[0]: " << (*it)[0]<< endl;
        cout << "(*it)[1]: " << (*it)[1]<< endl;
        cout << "(*it)[2]: " << (*it)[2]<< endl;

        ++it;
        break;
    }

    return 0;
}

//pattern = 'enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;'

//pattern = 'typedef\s+enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;'
//pattern = re.compile(r'enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;')
//input=open("./Cpp/SocketTAL.pb.h", 'r')
