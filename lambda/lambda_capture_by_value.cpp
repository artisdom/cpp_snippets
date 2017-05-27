#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    auto foo = [i](){ cout << i << endl; };
    auto bar = [&i](){ cout << i << endl; };

    i = 10;

    foo();
    bar();

    return 0;
}
