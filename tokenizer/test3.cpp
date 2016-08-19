#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include "Tokenizer.h"

#define debug_print printf

static inline string& ltrim(string& s) {
    s.erase(s.begin(), find_if_not(s.begin(), s.end(), ptr_fun<int, int>(::isspace)));
    return s;
}

static inline string&& ltrim(string&& s) {
    s.erase(s.begin(), find_if_not(s.begin(), s.end(), ptr_fun<int, int>(::isspace)));
    return move(s);
}

static inline string& rtrim(string& s) {
    s.erase(find_if_not(s.rbegin(), s.rend(), ptr_fun<int, int>(::isspace)).base(), s.end());
    return s;
}

static inline string&& rtrim(string&& s) {
    s.erase(find_if_not(s.rbegin(), s.rend(), ptr_fun<int, int>(::isspace)).base(), s.end());
    return move(s);
}

static inline string trim(string& s) {
    return ltrim(rtrim(s));
}

static inline string trim(string&& s) {
    return ltrim(rtrim(s));
}


int main(int argc, char *argv[])
{
    vector<string> tones;

    //string data = "880,400"; //"880,200; -,150; 880,200; -; 880,200"
    //string data = "880,200; -,150; 880,200; -; 880,200";
    string data = "#00FF00,200";
    string tonesDelim = ",";

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
