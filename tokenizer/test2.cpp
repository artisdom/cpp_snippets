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


struct ledPattern {
    string period;
    string duration;
};

int main(int argc, char *argv[])
{
    vector<string> tones;

    //string data = "880,400"; //"880,200; -,150; 880,200; -; 880,200"
    //string data = "880,200; -,150; 880,200; -; 880,200";
    string data = "#00FF00,200; #000000,; #0000FF,; #000000,; #FF0000,; #000000,1000";
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

    vector<struct ledPattern> ledPatterns;
    string default_duration = "500";

    for (unsigned int index = 0; index < tones.size(); index++) {

        string period_s;
        string duration_s;
        uint32_t period = 0;
        uint32_t duration = 0;
        string toneDelim = ",";
        struct ledPattern led;

        debug_print("index: %d, tones[index]: %s\n", index, tones[index].c_str());

        Tokenizer token(tones[index], toneDelim);

        if (token.nextToken()) {
            period_s = token.getToken();
            //period = atol(token.getToken().c_str());
            //debug_print("atol period: %d\n", period);
            debug_print("period: %s\n", period_s.c_str());
            //period = hz_to_micro_seconds(period);

        }

        if (token.nextToken()) {
            duration_s = token.getToken();
            //duration = atol(token.getToken().c_str());
            //duration = beep_check_duration(duration);

            default_duration = duration_s;

        } else {

            duration_s = default_duration;

        }

        debug_print("duration: %s\n", duration_s.c_str());

        led.period = trim(period_s);
        led.duration = trim(duration_s);

        //debug_print("period: %s, duration: %s\n", period_s.c_str(), duration_s.c_str());

        //Message* beepRequest = G7DeviceConnectorMessageFactory::createBeepCommand(period, duration);
        //beepRequests.push_back(beepRequest);

        ledPatterns.push_back(led);

    }

    for (auto l : ledPatterns) {
        cout << l.period << ' ' << l.duration << '\n';
    }

    return 0;
}
