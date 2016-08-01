#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("./Cpp/SocketTAL.pb.h");    

    auto ss = std::ostringstream{};
    ss << in.rdbuf();
    auto s = ss.str();

    cout << s << endl;
    return 0;
}
