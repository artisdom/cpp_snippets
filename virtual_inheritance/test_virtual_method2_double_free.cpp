#include <iostream>

using namespace std;

class Base {

public:
    Base() { a = new int [10]; }
    virtual ~Base() {method(); delete [] a; }
    void baseMethod() {method();}

private:
    int *a;
    virtual void method() {std::cout << "from Base" << std::endl;}

};

class A : public Base {

public:
    A() { b = new int [10]; }
    ~A() { method(); delete [] b; }

private:
    int *b;
    void method() {std::cout << "from A" << std::endl;}

};

int main(void) {

    Base* base = new A;
    base->baseMethod();
    base->~Base();
    delete base;

    return 0;
}
