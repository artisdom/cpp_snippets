#ifndef INIPARSER_H
#define INIPARSER_H

#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct KeyValueEntry {
    string key;
    string value;
};

struct Section {
    string sectionName;
    vector <struct KeyValueEntry> keyValueEntry;
};

class INIParser {

private:

    vector<struct Section> sections;

public:

    INIParser() {}

    INIParser(const string& filename) {

        parse(filename);

    }

    ~INIParser() {}

    int parse(const string& filename) {

        struct Section section;

        ifstream fs;
        fs.open(filename);

        if (!fs) {
            cout << "Open file " << filename << " failed.\n";
            return -1;
        }

        string line;

        while (getline(fs, line)) {

            if (line.endif)
        }
    }

}

#endif /* INIPARSER_H */
