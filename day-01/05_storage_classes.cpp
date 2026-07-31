#include <iostream>

// Demonstrates: static (function-local), global, and auto (default) storage.
// NOTE: `register` is deprecated/ignored by modern compilers, so we skip it
// here rather than teach a keyword that no longer does anything useful.

void greetWithLocalCounter() {
    int localCount = 0;   // storage class: automatic (default) -> resets every call
    localCount++;
    std::cout << "greetWithLocalCounter: localCount = " << localCount
              << "  <-- PREDICT: will this ever print more than 1?\n"; // no. is that correct? yes, because localCount is created and destroyed each time the function is called. So it will always be 1 when printed.
}

void greetWithStaticCounter() {
    static int staticCount = 0; // initialized ONCE, ever. Survives between calls. // What is static? It is a storage class specifier that tells the compiler to keep the variable in memory for the lifetime of the program, rather than creating and destroying it each time the function is called. This means that the variable will retain its value between function calls.
    staticCount++;
    std::cout << "greetWithStaticCounter: staticCount = " << staticCount
              << "  <-- PREDICT: what will this print on the 3rd call?\n"; // 3. is that correct?
}

int main() {
    std::cout << "--- calling each function 3 times ---\n";
    for (int i = 0; i < 3; i++) {
        greetWithLocalCounter();
    }
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        greetWithStaticCounter();
    }

    std::cout << "\n--- static local variable memory ---\n";
    std::cout << "A `static` local lives in the same memory region as globals,\n"
              << "NOT on the stack -- that's exactly why it survives after the\n"
              << "function returns, unlike a normal local variable.\n";

    return 0;
}

/*
   NEXT: open 05b_extern_main.cpp and 05b_extern_helper.cpp side by side.
   That pair demonstrates `extern` -- sharing ONE real variable across
   TWO different .cpp files, which is something a single-file demo can't
   show you.
*/
