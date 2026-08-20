#include <iostream>

template <typename T>
void compute(int a, int b, T func) {
    int result = func(a, b);
    std::cout << "Result :- " << result << "\n";
}

int main() {
    auto add = [](const int a, const int b) {
        return a + b;
    };

    compute(50, 700, add);

    return 0;
}