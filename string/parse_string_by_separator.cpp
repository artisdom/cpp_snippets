#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool parse_string_by_seperator(vector<string>& str_output_vector, string str, string str_seperator)
{
    string::size_type pos = 0;
    string::size_type pos2 = 0;

    while (true) {

        pos2 = str.find(str_seperator, pos);

        cout << "pos2: " << pos2 << endl;

        if (pos2 != string::npos) {

            string str2 = str.substr(pos, pos2 - pos);
            str_output_vector.push_back(str2);

            cout << "str2: " << str2 << endl;

            pos = pos2 + str_seperator.size();

        } else {

            if (str.length() > pos) {
                string str2 = str.substr(pos, str.length() - pos);
                str_output_vector.push_back(str2);
            }

            break;
        }
    }

    return true;    
}

int main(int argc, char *argv[])
{
    string str = "0,,//1,,//1,,//2,,//2,,//3,,//4,,//5-7,,//5-7,,//0,,//1,,//1,,//2,,//2,,//3,,//4,,//1,,//1,,//3,,//3,,//5-7,,//0,,//1,,//2,,//2,,//5-7,,//5-7";
    vector<string> str_output_vector;
    string str_seperator = ",,//";

    parse_string_by_seperator(str_output_vector, str, str_seperator);

    cout << "str: " << endl;
    cout << str << endl;

    for (string s : str_output_vector) {
        cout << s << "    ";
    }
    cout << endl;

    return 0;
}
