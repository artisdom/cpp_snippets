#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string str = "0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7";
    string::size_type pos = 16;
    string::size_type pos2 = 31;

    string str2 = str.substr(pos, pos2 - pos);
    cout << "str2: " << str2 << endl;

    return 0;
}
