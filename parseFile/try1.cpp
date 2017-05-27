#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    string line, name, age, salary, hoursWorked, randomText;
    ifstream readFile("textfile.txt");

    while (getline(readFile, line)) {
        stringstream iss(line);
        getline(iss, name, ':');
        getline(iss, age, '-');
        getline(iss, salary, ',');
        getline(iss, hoursWorked, '[');
        getline(iss, randomText, ']');

        cout << "name: " << name << '\n';
        cout << "age: " << age << '\n';
        cout << "salary: " << salary << '\n';
        cout << "hoursWorked: " << hoursWorked << '\n';
        cout << "randomText: " << randomText << '\n';
    }

    readFile.close();

    return 0;
}
