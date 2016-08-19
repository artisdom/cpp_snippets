#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Tokenizer.h"

#define debug_print printf

int main(int argc, char *argv[])
{
    vector<string> tones;

    //string data = "880,400"; //"880,200; -,150; 880,200; -; 880,200"
    string data = "880,200; -,150; 880,200; -; 880,200";
    string tonesDelim = ";";

    Tokenizer tokens(data, tonesDelim);

    while (tokens.nextToken()) {
        debug_print("tokens.getToken(): %s\n", tokens.getToken().c_str());
        tones.push_back(tokens.getToken());
    }

    debug_print("tones.size(): %lu\n", tones.size());

    for (auto t : tones) {
        cout << t << '\n';
    }

    return 0;
}
