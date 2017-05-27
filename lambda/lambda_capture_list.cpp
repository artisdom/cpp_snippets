#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i = 0, j = 1;

    auto func = [i, &j] (bool b, float f) { ++j; cout << i << ", " << j << ", " << b << ", " << f << endl; };

    func(true, 1.0f);

    return 0;
}
