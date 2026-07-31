#include <iostream>

// DECLARATION vs DEFINITION:
// `extern int shared;` would be a declaration (promise it exists elsewhere).
// `int shared;` at file scope below is a DEFINITION (creates storage) and
// also a global variable, visible to every function in this file.
int shared = 100;

void showScopeDeath() {
    std::cout << "\n--- showScopeDeath() ---\n";
    int x = 10; // 'x' is born here (function scope)
    std::cout << "x = " << x << " (only x exists so far)\n";
    {
        int y = 20; // 'y' is born here (block scope, nested)
        std::cout << "x = " << x << ", y = " << y << " (both alive)\n";

        {
            int z = 30; // even more nested
            std::cout << "x=" << x << " y=" << y << " z=" << z << " (all three alive)\n";
        } // <-- z DIES here
        // TODO: uncomment the next line. It will FAIL to compile.
        // std::cout << z;  // z is out of scope, compiler error expected

    } // <-- y DIES here
    // TODO: uncomment the next line. It will also fail.
    // std::cout << y;

    std::cout << "x = " << x << " (y and z are gone, only x remains)\n";
} // <-- x DIES here

void modifyLocalVsGlobal() {
    int shared = 5; // this LOCAL 'shared' hides (shadows) the global one!
    std::cout << "\n--- modifyLocalVsGlobal() ---\n";
    std::cout << "local shared = " << shared << "\n";
    std::cout << "global shared (via ::shared) = " << ::shared << "\n";
    shared = 999; // only changes the LOCAL copy
}

int main() {
    std::cout << "global shared at start = " << shared << "\n";

    showScopeDeath();

    modifyLocalVsGlobal();
    std::cout << "\nglobal shared after modifyLocalVsGlobal() = " << shared
              << "  <-- PREDICT: did it change to 999, or stay 100?\n";

    return 0;
}

/*
   EXPERIMENT: comment out the two "TODO: uncomment" lines' guidance and
   actually uncomment them one at a time. Compile. Read the EXACT compiler
   error message g++ gives you (it will say something like
   "'z' was not declared in this scope"). Learning to read that message
   is 80% of debugging in C++.
*/
