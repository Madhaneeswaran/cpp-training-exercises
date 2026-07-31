#include <iostream>

// FUNCTION PROTOTYPE (declaration): tells the compiler this function exists
// before main() uses it, so it doesn't need to be defined above main().
int square(int n);

// Function with a parameter and a return value.
int square(int n) {
    return n * n;
}

bool isEven(int n) {
    return n % 2 == 0;
}

// Function with NO return value (void) -- it does something, returns nothing.
void printSeparator() {
    std::cout << "------------------------\n";
}

// PASS BY VALUE: the function gets a COPY of the argument.
// Changing `n` inside here does NOT affect the caller's variable.
void tryToDouble(int n) {
    n = n * 2;
    std::cout << "  inside tryToDouble, n = " << n << "\n";
}

// Default parameter value.
int addWithDefault(int a, int b = 10) {
    return a + b;
}

int main() {
    printSeparator();
    std::cout << "square(5) = " << square(5) << "\n";
    printSeparator();

    int original = 7;
    std::cout << "before tryToDouble: original = " << original << "\n";
    tryToDouble(original);
    std::cout << "after tryToDouble:  original = " << original
              << "  <-- PREDICT: did it become 14, or stay 7?\n";

    printSeparator();
    std::cout << "addWithDefault(5)     = " << addWithDefault(5) << "  (uses default b=10)\n";
    std::cout << "addWithDefault(5, 20) = " << addWithDefault(5, 20) << "  (overrides default)\n";

    printSeparator();
    std::cout << "isEven(4) = " << isEven(4) << "\n";
    std::cout << "isEven(7) = " << isEven(7) << "\n";

    return 0;
}

/*
   CHALLENGE: write a new function `bool isEven(int n)` below square(),
   declare its prototype near the top, call it from main() for a few
   numbers, and print the results. This mirrors what Assignment 1's
   "function call counter" problem will ask you to build on.
*/
