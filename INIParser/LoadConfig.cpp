#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

/* The LoadConfig function loads the configuration file given by filename
     It returns a map of key-value pairs stored in the conifuration file */
map<string, string> LoadConfig(string filename)
{
    ifstream input(filename); //The input stream
    map<string,string> ans; //A map of key-value pairs in the file

    while (input) //Keep on going as long as the file stream is good
    {
        string key; //The key
        string value; //The value

        getline(input, key, '='); //Read up to the : delimiter into key

        cout << "key: " << key << endl;

        getline(input, value, '\n'); //Read up to the newline into value

        cout << "value: " << value << endl;

        string::size_type pos1 = value.find_first_of("\""); //Find the first quote in the value
        string::size_type pos2 = value.find_last_of("\""); //Find the last quote in the value

        if (pos1 != string::npos && pos2 != string::npos && pos2 > pos1) //Check if the found positions are all valid
        {
            value = value.substr(pos1+1,pos2-pos1-1); //Take a substring of the part between the quotes
            ans[key] = value; //Store the result in the map
        }
    }

    input.close(); //Close the file stream

    return ans; //And return the result
}

int main(int argc, char *argv[])
{
    map<string, string> pairs;

    pairs = LoadConfig("DEV_PED2.ini");

    for (auto m : pairs) {
        cout << m.first << " " << m.second << endl;
    }

    return 0;
}
