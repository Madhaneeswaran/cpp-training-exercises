#include <iostream>

void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    std::cout << "Enter two numbers to swap: ";
    std::cin >> x >> y;

    swapNumbers(x, y);

    std::cout << "After swapping :- " << x << '\t' << y << "\n";

    return 0;
}