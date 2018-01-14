#include <iostream>

using namespace std;

class Group {
private:
    int id;

public:
    void set_id(int);
    int get_id();
    bool operator==(const Group&);
};

void Group::set_id(int v) {
    id = v;
}

int Group::get_id() {
    return id;
}

bool Group::operator==(const Group& g) {
    if(g.id == this->id) {  /* id is private? */
        return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    Group a, b;

    a.set_id(1);
    b.set_id(2);

    if (a == b) {
        std::cout << "a equals to b" << std::endl;
    } else {
        std::cout << "a not equals to b" << std::endl;
    }

    a.set_id(3);
    b.set_id(3);

    if (a == b) {
        std::cout << "a equals to b" << std::endl;
    } else {
        std::cout << "a not equals to b" << std::endl;
    }

    return 0;
}
