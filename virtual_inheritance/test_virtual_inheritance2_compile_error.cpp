#include <iostream>

class D {
public:
    void foo() {
        std::cout << "Foooooo" << std::endl;
    }
};


class C:  public D {
};

class B:  public D {
};

class A: public B, public C {
};

int main(int argc, const char * argv[]) {
    A a;
    a.foo();
}
