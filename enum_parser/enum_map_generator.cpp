#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;

const string enum_value_seperator = "=";

const string map_file_header =
    "#ifndef SOCKETTALENUMMAP_H\n"
    "#define SOCKETTALENUMMAP_H\n"
    "\n"
    "#include <map>\n"
    "#include <string>\n"
    "\n"
    "std::map<std::string, int> SocketTalEnumMap\n"
    "{\n";

const string map_file_trailer =
    "};\n"
    "\n"
    "#endif /* SOCKETTALENUMMAP_H */\n";

static inline string& ltrim(string& s) {
    s.erase(s.begin(), find_if_not(s.begin(), s.end(), ptr_fun<int, int>(::isspace)));
    return s;
}

static inline string& rtrim(string& s) {
    s.erase(find_if_not(s.rbegin(), s.rend(), ptr_fun<int, int>(::isspace)).base(), s.end());
    return s;
}

static inline string trim(string& s) {
    return ltrim(rtrim(s));
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: \n");
        printf("       ./main <SocketTal_Protobuf_header_file> \n");
        printf("eg:    ./main ./Cpp/SocketTAL.pb.h \n");
        return -1;
    }

    string inFilename = argv[1];
    string outFilename = "./SocketTalEnumMap.h";
    ifstream in(inFilename);
    ofstream out(outFilename);

    out << map_file_header;

    auto ss = ostringstream{};
    ss << in.rdbuf();
    auto str = ss.str();

    string enum_pattern = "enum\\s+\\w+\\s*\\{[^{}]*\\}\\s*;";
    regex reg(enum_pattern);

    sregex_iterator it(str.begin(), str.end(), reg);
    sregex_iterator it_end;

    while (it != it_end) {

        string enum_str = it->str();

        //cout << "enum_str: " << endl;
        //cout << enum_str << endl;

        string enum_value_pattern = "\\s*\\w+\\s*=\\s*\\w+";
        regex reg2(enum_value_pattern);

        sregex_iterator it2(enum_str.begin(), enum_str.end(), reg2);
        sregex_iterator it_end2;

        while (it2 != it_end2) {

            string enum_value_str = it2->str();
            //cout << enum_value_str << endl;

            string::size_type pos = 0;

            pos = enum_value_str.find(enum_value_seperator, 0);
            if (pos != string::npos) {

                string str = enum_value_str.substr(0, pos);
                string str2 = enum_value_str.substr(pos + 1, enum_value_str.length() - pos - 1);

                str = trim(str);
                str2 = trim(str2);

                //cout << "str: " << str << endl;
                //cout << "str2: " << str2 << endl;

                out << "    { \"" << str << "\", " << str2 << " },\n";

            }

            ++it2;
        }

        ++it;
    }

    out << map_file_trailer;

    cout << "output wrote to file: " << outFilename << "\n";

    in.close();
    out.close();
    return 0;
}
