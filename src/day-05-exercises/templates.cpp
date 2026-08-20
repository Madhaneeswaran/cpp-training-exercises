#include <iostream>

template<typename T1, typename T2>
auto add(const T1& a, const T2& b) {
    return a + b;
}

int main () {
    std::cout << add(4, 9) << '\n';
    std::cout << add(5.6, 9.6) << '\n';
    std::cout << add(5.9f, 9.8f) << '\n';

    std::cout << add<std::string, std::string>("Hello ", "World!") << '\n';
    return 0;
}