#include <iostream>

struct Foo {
    unsigned long long i;
    constexpr Foo& operator+=(const Foo& d) { return *this; }
};

constexpr Foo operator"" _Foo (unsigned long long i) {
    return Foo{i};
}

int main() {
    1_Foo += 2_Foo;
    std::cout << std::endl;

    std::cin.get();
    return 0;
}