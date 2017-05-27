#include <iostream>
#include <functional>

using namespace std;

struct MyStruct {

    MyStruct() { cout << "Constructed" << endl; }
    MyStruct(MyStruct const&) { cout << "Copy-Constructed" << endl; }
    ~MyStruct() { cout << "Destructed" << endl; }

};

int main()
{
    cout << "Creating MyStruct..." << endl;
    MyStruct ms;

    {
        cout << "Creating lambda..." << endl;
        auto f = [ms](){}; // note 'ms' is captured by-value
        cout << "Destroying lambda..." << endl;
    }

    cout << "Destroying MyStruct..." << endl;
}
