#include <iostream>

int main() {
    std::cout << "--- arithmetic ---\n";
    int a = 17, b = 5;
    std::cout << a << " + " << b << " = " << (a + b) << "\n";
    std::cout << a << " - " << b << " = " << (a - b) << "\n";
    std::cout << a << " * " << b << " = " << (a * b) << "\n";
    std::cout << a << " / " << b << " = " << float(a / b) << "  <-- PREDICT: is this 3.4 or 3?\n";
    std::cout << a << " % " << b << " = " << (a % b) << "  (remainder / modulo)\n";

    std::cout << "\n--- relational & logical ---\n";
    std::cout << std::boolalpha; // print bools as true/false instead of 1/0
    std::cout << "(a > b): " << (a > b) << "\n";
    std::cout << "(a > b) && (b > 0): " << ((a > b) && (b > 0)) << "\n";
    std::cout << "(a < b) || (b > 0): " << ((a < b) || (b > 0)) << "\n";

    std::cout << "\n--- PRECEDENCE TRAPS: predict each result BEFORE running ---\n";
    int r1 = 2 + 3 * 4;
    int r2 = (2 + 3) * 4;
    int r3 = 10 - 2 - 3;         // is subtraction left-to-right or right-to-left?
    bool r4 = 1 < 2 == 2 < 1;    // sneaky: what does this even mean?
    // ^ g++ -Wall will warn "suggest parentheses around comparison" here --
    //   that warning IS the lesson: chained comparisons are a real trap.
    std::cout << "2 + 3 * 4        = " << r1 << "\n";
    std::cout << "(2 + 3) * 4      = " << r2 << "\n";
    std::cout << "10 - 2 - 3       = " << r3 << "\n";
    std::cout << "1 < 2 == 2 < 1   = " << r4 << "\n";

    std::cout << "\n--- increment/decrement: pre vs post ---\n";
    int x = 5;
    int postResult = x++; // x++ RETURNS the old value, THEN increments
    std::cout << "x = 5, x++ returned: " << postResult << ", now x = " << x << "\n";

    int y = 5;
    int preResult = ++y; // ++y increments FIRST, THEN returns the new value
    std::cout << "y = 5, ++y returned: " << preResult << ", now y = " << y << "\n";

    std::cout << "\n--- bitwise (binary is easier to reason about here) ---\n";
    unsigned char p = 0b00001100; // 12
    unsigned char q = 0b00001010; // 10
    std::cout << "p = 12 (00001100), q = 10 (00001010)\n";
    std::cout << "p & q  = " << (int)(p & q)  << "  (AND)\n";
    std::cout << "p | q  = " << (int)(p | q)  << "  (OR)\n";
    std::cout << "p ^ q  = " << (int)(p ^ q)  << "  (XOR)\n";
    std::cout << "p << 1 = " << (int)(p << 2) << "  (left shift = multiply by 2)\n"; // how left shift works: 00001100 << 1 = 00011000
    std::cout << "p >> 1 = " << (int)(p >> 2) << "  (right shift = divide by 2)\n"; // how right shift works: 00001100 >> 1 = 00000110

    return 0;
}

/*
   CHALLENGE: without running the file, work out r4 by hand using
   C++ operator precedence rules (< binds tighter than ==). Write your
   hand-worked answer as a comment, THEN compile and check yourself.
*/
