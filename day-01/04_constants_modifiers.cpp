#include <iostream>

#define PI_MACRO 3.14159        // preprocessor #define: pure text substitution
const double PI_CONST = 3.14159; // real, typed constant (compiler-checked)

int main() {
    std::cout << "--- const vs #define ---\n";
    std::cout << "PI_MACRO: " << PI_MACRO << "\n";
    std::cout << "PI_CONST: " << PI_CONST << "\n";

    // TODO: try un-commenting this line. #define has NO type, so the
    // preprocessor just pastes "3.14159" wherever PI_MACRO appears —
    // it will still compile even in silly contexts. Try:
   
    // this is a trap, think about why. not sure
    std::cout << "PI_MACRO :- " << (PI_MACRO == 3.14159 ? "pi-macro changed" : "pi-macro not changed") << "\n"; // this is a trap, think about why

    // TODO: try `PI_CONST = 3;` here. It must FAIL to compile — that's the
    // whole point of `const`: the compiler enforces it, #define does not.
    // PI_CONST = 3;

    std::cout << "\n--- literal suffixes ---\n";
    auto a = 10;      // int
    auto b = 10u;     // unsigned int // what is unsigned int? It's a type that can only hold non-negative values (0 and up). It has the same size as a regular int, but its range is shifted to be all positive. For example, on a 32-bit machine, an int can hold -2,147,483,648 to 2,147,483,647, while an unsigned int can hold 0 to 4,294,967,295.
    auto c = 10L;     // long // what is auto?
    auto d = 10.0f;   // float
    auto e = 10.0;    // double
    auto f = '$';     // what data type? // change it to rupee symbol
    std::cout << "sizeof(10)    = " << sizeof(a) << "  (int)\n";
    std::cout << "sizeof(10u)   = " << sizeof(b) << "  (unsigned int)\n";
    std::cout << "sizeof(10L)   = " << sizeof(c) << "  (long)\n";
    std::cout << "sizeof(10.0f) = " << sizeof(d) << "  (float)\n";
    std::cout << "sizeof(10.0)  = " << sizeof(e) << "  (double)\n";

    std::cout << "\n--- signed vs unsigned overflow ---\n";
    // PREDICT: what happens when a small unsigned type goes below 0?
    unsigned short u = 0;
    std::cout << "unsigned short u = 0\n";
    std::cout << "u - 1 = " << (unsigned short)(u - 2) << "  <-- PREDICT before running!\n"; // it will crash

    signed char sc = 127; // max for a signed 8-bit type
    sc = sc + 1;
    std::cout << "signed char 127 + 1 = " << (int)sc << "  <-- PREDICT: does it become 128, or wrap negative?\n"; // wraps negative

    std::cout << "\n--- short vs long range demo ---\n";
    std::cout << "sizeof(short): " << sizeof(short) << ", sizeof(long): " << sizeof(long)
              << ", sizeof(long long): " << sizeof(long long) << "\n";
    std::cout << "(On this Windows/MinGW compiler, `long` is only 4 bytes even though\n"
              << " you're on a 64-bit machine -- Windows uses the 'LLP64' model. On\n"
              << " Linux/macOS 'LP64' machines, `long` is 8 bytes. `long long` is\n"
              << " always at least 8 bytes on both -- that's why it exists.)\n";

    return 0;
}

/*
   WHY THIS MATTERS: unsigned overflow is a real, common source of bugs
   (e.g. looping `for (unsigned i = size; i >= 0; i--)` never ends,
   because when i hits 0 and decrements again it wraps to a huge number
   instead of going negative). Keep this file — you'll recognize this bug
   pattern again in real code.
*/
