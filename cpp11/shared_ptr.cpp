#include <iostream>
#include <memory>

struct Snitch {
public:
    Snitch() { std::cout << "c'tor" << std::endl; }
    ~Snitch() { std::cout << "d'tor" << std::endl; }
    Snitch(Snitch const&) { std::cout << "copy c'tor" << std::endl; }
    Snitch(Snitch&&) { std::cout << "move c'tor" << std::endl; }
};

int main() {
    auto snitch = std::make_shared<Snitch>();
    auto another_snitch = snitch;
    std::cout << "Equal?: " << (snitch == another_snitch) << std::endl;

    {
        auto scoped_snitch = snitch;
        auto another_scoped_snitch = scoped_snitch;
    }

    // destroy 'another_scoped_snitch' and 'scoped_snitch'

}

// destroy 'snother_snitch' and 'snitch'
