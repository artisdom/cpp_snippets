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
    string str = "0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7";
    vector<string> case_vector;

    string::size_type pos = 0;
    string::size_type pos2 = 0;

    //while (true) {

        pos2 = str.find(CASE_GROUP_SEPERATOR, pos);

        if (pos2 != string::npos) {
            string str2 = str.substr(pos, pos2 - pos);
            cout << "str2: " << str2 << endl;
            case_vector.push_back(str2);

            pos = pos2 + 1;
        } else {
            //break;
        }

        pos2 = str.find(CASE_GROUP_SEPERATOR, pos);

        cout << "pos: " << pos << endl;
        cout << "pos2: " << pos2 << endl;
        
        if (pos2 != string::npos) {
            string str2 = str.substr(pos, pos2 - pos);
            cout << "str2: " << str2 << endl;
            case_vector.push_back(str2);

            pos = pos2;
        } else {
            //break;
        }

        
        //}
    return 0;
}
