#include <iostream>

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    std::cout << "--- a reference is an ALIAS, not a separate variable ---\n";
    int x = 10;
    int& ref = x;   // ref and x now name the SAME memory
    std::cout << "x   = " << x << "\n";
    std::cout << "ref = " << ref << "\n";
    std::cout << "&x  = " << &x << "\n";
    std::cout << "&ref = " << &ref << "  <-- PREDICT: same address as &x, or different?\n";

    std::cout << "\n--- changing through the reference changes the original ---\n";
    ref = 999;
    std::cout << "after ref = 999, x = " << x
              << "  (no '*' needed to write through a reference, unlike a pointer)\n";

    std::cout << "\n--- a reference MUST be initialized, and CANNOT be reseated ---\n";
    int y = 20;
    // TODO: uncomment the next line. A reference has no "empty" state like
    // nullptr, so it cannot be declared without immediately binding to a
    // variable -- this line fails to compile.
    // int& danglingRef;

    ref = y;   // PREDICT: does this make `ref` an alias for `y` now?
    std::cout << "after ref = y, ref = " << ref << ", x = " << x << ", y = " << y << "\n";
    // ^ `ref = y` does NOT rebind ref to y. `ref` is still permanently bound
    // to `x`. This line COPIES y's value INTO x (because ref IS x).

    std::cout << "\n--- classic use: swap two variables with reference parameters ---\n";
    int p = 1, q = 2;
    std::cout << "before swap: p = " << p << ", q = " << q << "\n";
    swapByReference(p, q);
    std::cout << "after swap:  p = " << p << ", q = " << q
              << "  <-- this only works because the parameters are references\n";

    return 0;
}

/*
   CHALLENGE: change swapByReference's parameters from `int&` to plain
   `int` (pass by value) and predict, then verify, whether p and q still
   swap in main(). Put the answer in a comment. This is the exact
   difference Day_02.md's "pass by reference vs pass by value" learning
   outcome is testing.
*/
