#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string CASE_GROUP_SEPERATOR = "/";
const string CASE_DEVICE_SEPERATOR = ":";
const string CASE_INDEX_SEPERATOR = ",";
const string CASE_INDEX_RANGE_SEPERATOR = "-";

int main(int argc, char *argv[])
{
    string str = "0,1,1,2,2,3,4,5-7,5-7,0,1,1,2,2,3,4,1,1,3,3,5-7,0,1,2,2,5-7,5-7";

    vector<string> index_vector;

    string::size_type pos = 0;
    string::size_type pos2 = 0;

    while (true) {

        pos2 = str.find(CASE_INDEX_SEPERATOR, pos);

        if (pos2 != string::npos) {

            string str2 = str.substr(pos, pos2 - pos);
            cout << "str2: " << str2 << endl;
            index_vector.push_back(str2);

            pos = pos2 + 1;

        } else {

            if (str.length() > pos) {
                string str2 = str.substr(pos, str.length() - pos);
                cout << "str2: " << str2 << endl;
                index_vector.push_back(str2);
            }

            break;
        }
    }

    cout << "index vector: " << endl;
    for (string s : index_vector) {
        cout << s << endl;
    }

   return 0;
}
