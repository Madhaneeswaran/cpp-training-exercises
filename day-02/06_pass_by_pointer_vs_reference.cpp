#include <iostream>

// PASS BY VALUE: gets a COPY. Caller's variable is untouched.
void doubleByValue(int n) {
    n = n * 2;
}

// PASS BY POINTER: caller must pass an ADDRESS (&x). Must dereference (*p)
// to read/write the real value. Can be nullptr -- you SHOULD check.
void doubleByPointer(int* p) {
    if (p == nullptr) return; // pointers can be null, so a real function should guard
    
    *p = *p * 2;
}

// PASS BY REFERENCE: caller passes the variable directly, looks identical
// to pass-by-value at the call site. No dereference needed. CANNOT be null.
void doubleByReference(int& r) {
    r = r * 2;
}

int main() {
    std::cout << "--- same operation, three ways ---\n";

    int a = 5;
    doubleByValue(a);
    std::cout << "doubleByValue(a):     a = " << a
              << "  <-- PREDICT: changed to 10, or still 5?\n"; // still 5

    int b = 5;
    doubleByPointer(&b);   // must explicitly take the address
    std::cout << "doubleByPointer(&b):  b = " << b
              << "  <-- PREDICT: changed to 10, or still 5?\n"; // 10

    int c = 5;
    doubleByReference(c);  // looks just like pass-by-value, but ISN'T
    std::cout << "doubleByReference(c): c = " << c
              << "  <-- PREDICT: changed to 10, or still 5?\n"; // 10

    std::cout << "\n--- the safety difference: pointers can lie about existing ---\n";
    int* maybeNull = nullptr;
    doubleByPointer(maybeNull);   // safe here ONLY because we added the null check above
    std::cout << "doubleByPointer(nullptr) did not crash, because we checked for it.\n";
    // TODO: remove the `if (p == nullptr) return;` guard inside doubleByPointer,
    // rerun this exact test, and watch it crash. A reference parameter can
    // NEVER be null in the first place -- that whole failure mode doesn't exist.

    std::cout << "\n--- readability at the call site ---\n";
    std::cout << "doubleByValue(a)      -- can I tell if 'a' might change? No.\n";
    std::cout << "doubleByPointer(&b)   -- the '&' is a visible warning: this might change.\n";
    std::cout << "doubleByReference(c)  -- looks safe, but IS silently mutating. Read the signature!\n";

    return 0;
}

/*
   RULE OF THUMB (matches Day_02.md): prefer references when the argument
   must always exist and you want clean syntax. Prefer pointers when the
   argument might legitimately be "nothing" (nullptr), or when you need to
   change WHICH variable you're pointing at later (reseating).
*/
