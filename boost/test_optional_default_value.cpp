#include <iostream>
#include <boost/optional.hpp>

using namespace std;

struct test {
    int a;
    int b;
    int c;
    int d;
    int e;
};

int main(int argc, char *argv[])
{
    struct test t;
    struct test tt = { 1, 2, 3, 4, 5 };
    boost::optional<struct test> t2 = boost::none;
    boost::optional<struct test> t3;
    boost::optional<struct test> t4 = tt;

    cout << "sizeof(struct test): " << sizeof(t) << endl;
    cout << "sizeof(struct test): " << sizeof(tt) << endl;
    cout << "sizeof(boost::optional<struct test> = boost::none): " << sizeof(t2) << endl;
    cout << "sizeof(boost::optional<struct test>): " << sizeof(t3) << endl;
    cout << "sizeof(boost::optional<struct test>) = struct test: " << sizeof(t4) << endl;
    return 0;
}
