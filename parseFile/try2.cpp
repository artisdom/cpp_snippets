#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

struct Person
{
    std::string name;
    std::string age;
    std::string salary;
    std::string hoursWorked;
    std::string randomText;

    friend std::istream& operator>>(std::istream& str, Person& data)
    {
        std::string line;
        Person tmp;
        if (std::getline(str,line))
        {
            std::stringstream iss(line);

            if ( std::getline(iss, tmp.name, ':')        &&
                 std::getline(iss, tmp.age, '-')         &&
                 std::getline(iss, tmp.salary, ',')      &&
                 std::getline(iss, tmp.hoursWorked, '[') &&
                 std::getline(iss, tmp.randomText, ']'))
             {
                 /* OK: All read operations worked */
                 data.swap(tmp);  // C++03 as this answer was written a long time ago.
             }
             else
             {
                 // One operation failed.
                 // So set the state on the main stream
                 // to indicate failure.
                 str.setstate(std::ios::failbit);
             }
        }
        return str;
    }

    void swap(Person& other) {

        name.swap(other.name);
        age.swap(other.age);
        salary.swap(other.salary);
        hoursWorked.swap(other.hoursWorked);
        randomText.swap(other.randomText);

    }

/*
    void swap(Person& other)
    {
        swap(name,        other.name);
        swap(age,         other.age);
        swap(salary,      other.salary);
        swap(hoursWorked, other.hoursWorked);
        swap(randomText,  other.randomText)
    }
*/
};

int main(int argc, char *argv[])
{
    Person   data;
    ifstream readFile("textfile.txt");

    while (readFile >> data)
    {

        cout << "name: " << data.name << '\n';
        cout << "age: " << data.age << '\n';
        cout << "salary: " << data.salary << '\n';
        cout << "hoursWorked: " << data.hoursWorked << '\n';
        cout << "randomText: " << data.randomText << '\n';
    }

    return 0;
}
