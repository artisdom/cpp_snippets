#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include "Tokenizer.h"

#define debug_print printf
#define error_print printf

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

vector<char> hexToBytes(const string& hex) {

    vector<char> bytes;

    for (unsigned int i = 0; i < hex.length(); i += 2) {

        string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);

    }

    return bytes;
}

void hexToBytes(const string& hex, vector<char>& bytes) {

    for (unsigned int i = 0; i < hex.length(); i += 2) {

        string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);

    }

}

struct ledPattern {
    string color_s;
    vector<char> colorVector;
    string duration_s;
    int duration;
};

int main(int argc, char *argv[])
{
    vector<string> ledData;
    string data = "#00FF00,200; #000000,; #0000FF,300; #000000,; #FF0000,400; #000000,1000";
    string patternDelim = ";";

    Tokenizer tokens(data, patternDelim);

    while (tokens.nextToken()) {
        debug_print("tokens.getToken(): %s\n", tokens.getToken().c_str());
        ledData.push_back(tokens.getToken());
    }

    debug_print("ledData.size(): %lu\n", ledData.size());

    for (auto t : ledData) {
        cout << t << '\n';
    }

    vector<struct ledPattern> ledPatterns;
    string default_duration = "500";

    for (unsigned int index = 0; index < ledData.size(); index++) {

        string color_s;
        string duration_s;
        string toneDelim = ",";
        struct ledPattern led;

        debug_print("index: %d, ledData[index]: %s\n", index, ledData[index].c_str());

        Tokenizer token(ledData[index], toneDelim);

        if (token.nextToken()) {

            color_s = token.getToken();
            debug_print("color: %s\n", color_s.c_str());

        }

        if (token.nextToken()) {

            duration_s = token.getToken();
            default_duration = duration_s;

        } else {

            duration_s = default_duration;

        }

        debug_print("duration: %s\n", duration_s.c_str());

        led.color_s = trim(color_s);
        led.duration_s = trim(duration_s);

        if (led.color_s[0] != '#') {
            error_print("invalid color data: %s\n", led.color_s.c_str());
        }
        led.color_s = led.color_s.substr(1);

        hexToBytes(led.color_s, led.colorVector);
        led.duration = atoi(led.duration_s.c_str());
        //debug_print("color: %s, duration: %s\n", color_s.c_str(), duration_s.c_str());

        ledPatterns.push_back(led);

    }


    for (auto l : ledPatterns) {

        cout << l.color_s << ' ' << l.duration_s << ' ' << l.duration << '\n';

        cout << "\n";
        for (auto c : l.colorVector) {
            cout << (int)c << ' ';
        }
        cout << "\n";

        for (auto c : l.colorVector) {
            cout << hex << static_cast<int>(c) << ' ';
        }
        cout << "\n";

        for (auto c : l.colorVector) {
            cout << hex << +c << ' ';
        }
        cout << "\n\n";

    }

    return 0;
}
