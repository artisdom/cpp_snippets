#include <iostream>
#include <string>
#include "enum_map_test.h"

using namespace std;

int main(int argc, char *argv[])
{

    for (map<string, int>::iterator it = SocketTalEnumMap.begin(); it != SocketTalEnumMap.end(); ++it) {

        cout << it->first << " => " << it->second << '\n';

    }

    return 0;
}
