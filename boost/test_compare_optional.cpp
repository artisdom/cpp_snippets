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

bool operator==(const struct test& a, const struct test& b);
bool operator!=(const struct test& a, const struct test& b);

bool operator==(const struct test& a, const struct test& b)
{
    return ((a.a == b.a) && (a.b == b.b) && (a.c == b.c) && (a.d == b.d) && (a.e == b.e));
}

bool operator!=(const struct test& a, const struct test& b)
{
    return !(a == b);
}

int main(int argc, char *argv[])
{
    struct test t = { 1, 2, 3, 4, 5 };
    struct test tt = { 1, 2, 3, 4, 5 };
    struct test ttt = { 2, 3, 4, 5, 6 };
    struct test tttt = { 1, 2, 3, 4, 5 };

    boost::optional<struct test> t2 = boost::none;
    boost::optional<struct test> t3 = t;
    boost::optional<struct test> t4 = tt;
    boost::optional<struct test> t5 = ttt;

    boost::optional<struct test> t6 = tttt;

    cout << "t2 == t3: " << (t2 == t3)  << endl;
    cout << "t3 == t4: " << (t3 == t4)  << endl;
    cout << "t4 == t5: " << (t4 == t5)  << endl;

    cout << "t3 == t5: " << (t3 == t5)  << endl;
    cout << "t3 == t6: " << (t3 == t6)  << endl;
    cout << "t4 == t6: " << (t4 == t6)  << endl;
    return 0;
}
