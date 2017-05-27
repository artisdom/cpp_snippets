#include <map>
#include <iostream>

struct MyClass
{
    enum class MyEnum : char {
        AAA = -8,
            BBB = '8',
            CCC = AAA + BBB
            };
};

// Replace magic() by some faster compile-time generated code
auto magic (MyClass::MyEnum e)
{
    const std::map<MyClass::MyEnum,const char*> MyEnumStrings {
        { MyClass::MyEnum::AAA, "MyClass::MyEnum::AAA" },
        { MyClass::MyEnum::BBB, "MyClass::MyEnum::BBB" },
        { MyClass::MyEnum::CCC, "MyClass::MyEnum::CCC" }
    };
    auto   it  = MyEnumStrings.find(e);
    return it == MyEnumStrings.end() ? "Out of range" : it->second;
}

int main()
{
    std::cout << magic(MyClass::MyEnum::AAA) <<'\n';
    std::cout << magic(MyClass::MyEnum::BBB) <<'\n';
    std::cout << magic(MyClass::MyEnum::CCC) <<'\n';
}
