#include <iostream>

using namespace std;

class A                     { public: void eat(){ cout<<"A" << endl;} };
class B: virtual public A   { public: void eat(){ cout<<"B" << endl;} };
class C: virtual public A   { public: void eat(){ cout<<"C" << endl;} };
class D: public         B,C { public: void eat(){ cout<<"D" << endl;} };

int main()
{
    A *a = new D();
    a->eat();
}
