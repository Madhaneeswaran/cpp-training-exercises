#include <iostream>
#include <string>

template<typename T1, typename T2>
auto add(const T1& a, const T2& b) {
    return a + b;
}

int main () {
    std::cout << add<int,int>(4, 9) << '\n';
    std::cout << add<double,double>(5.6, 9.6) << '\n';
    std::cout << add<float,float>(5.9f, 9.8f) << '\n';
    std::cout << add<std::string,std::string>("Hello", " C++") << '\n';

    return 0;
}