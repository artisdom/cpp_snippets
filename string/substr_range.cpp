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
    //string str = "5-7";
    string str = "5-20";
    //string str = "2";

    string::size_type pos = 0;
    string::size_type pos2 = 0;

    pos = str.find(CASE_INDEX_RANGE_SEPERATOR);

    string str2 = str.substr(0, pos);
    cout << "str2: " << str2 << endl;

    string str3 = str.substr(pos + 1);
    cout << "str3: " << str3 << endl;

    int start = stoi(str2);
    cout << "start: " << start << endl;

    int end = stoi(str3);
    cout << "end: " << end << endl;

    for (int i = start; i <= end; i++) {
        cout << i << ", ";
    }
    cout << endl;

   return 0;
}
