#include <iostream>

void takesLvalueRef(int& r) {
    std::cout << "takesLvalueRef got: " << r << "\n";
}

void takesRvalueRef(int&& r) {
    std::cout << "takesRvalueRef got a temporary: " << r << "\n";
}

// Accepts EITHER an lvalue or an rvalue -- this is why most real function
// signatures you'll see use `const T&`, not plain `T&`.
void takesConstRef(const int& r) {
    std::cout << "takesConstRef got: " << r << "\n";
}

int main() {
    std::cout << "--- lvalue: has a name, has an address, outlives the expression ---\n";
    int x = 10;         // x is an lvalue -- you can take &x
    std::cout << "x = " << x << ", &x = " << &x << "\n";

    std::cout << "\n--- rvalue: a temporary with no lasting address ---\n";
    std::cout << "5 + 3 = " << (5 + 3) << "  <-- this result is an rvalue: it exists\n"
              << "                        just long enough to be printed, then it's gone.\n";
    // TODO: uncomment the next line. You cannot take the address of a
    // temporary -- there's nothing stable to point at.
    // std::cout << &(5 + 3) << "\n";   // compiler error: lvalue required

    std::cout << "\n--- lvalue references (T&) bind ONLY to lvalues ---\n";
    takesLvalueRef(x);   // fine: x is an lvalue
    // TODO: uncomment the next line. `5 + 3` is a temporary rvalue with no
    // address -- an int& parameter has nothing real to bind to and refuses.
    // takesLvalueRef(5 + 3);   // compiler error

    std::cout << "\n--- rvalue references (T&&) bind ONLY to rvalues ---\n";
    takesRvalueRef(5 + 3);   // fine: 5 + 3 is a temporary
    // TODO: uncomment the next line. x is an lvalue (it has a name and an
    // address) -- an int&& parameter specifically wants a temporary, and x
    // isn't one.
    // takesRvalueRef(x);   // compiler error

    std::cout << "\n--- const T& is the flexible middle ground ---\n";
    takesConstRef(x);       // works: binds to the lvalue
    takesConstRef(5 + 3);   // ALSO works: a const reference can bind to a temporary
    std::cout << "(this is why so many real-world function parameters are `const T&`:\n"
              << " callers can pass either a variable or a raw computed value.)\n";

    return 0;
}

/*
   QUICK TEST: for each of the following, decide lvalue or rvalue, then
   check your answer by trying to take its address with &(...):
     1. a variable you declared            -> ? lvalue
     2. the literal 42                     -> ? rvalue
     3. the result of a function returning by value, e.g. someFunc()  -> ? rvalue
     4. *ptr (dereferencing a pointer)     -> ? lvalue
   (Answers: 1 lvalue, 2 rvalue, 3 rvalue, 4 lvalue -- *ptr names a real
   memory location, so it behaves like a variable even though it has no
   fixed identifier of its own.)
*/
