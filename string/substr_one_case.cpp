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
    string str = "10:0,1,1,2,2,3,4";
    string::size_type pos = 0;
    string::size_type pos2 = 0;

    pos = str.find(CASE_DEVICE_SEPERATOR);

    string str2 = str.substr(0, pos);
    cout << "str2: " << str2 << endl;

    string str3 = str.substr(pos + 1);
    cout << "str3: " << str3 << endl;

    int device_id = stoi(str2);
    cout << "device_id: " << device_id << endl;

   return 0;
}
