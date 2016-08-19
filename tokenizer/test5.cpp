#include <sstream>
#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    stringstream converter;
    istringstream ss( "13 00 0A 1B CA 00" );
    vector<uint8_t> bytes;

    string word;

    while ( ss >> word ) {
        uint8_t temp;
        converter << hex << word;
        converter >> temp;
        bytes.push_back( temp );
    }

    for (auto b : bytes) {
        cout << b << '\n';
    }
    return 0;
}
