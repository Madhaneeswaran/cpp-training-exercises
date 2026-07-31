#include <iostream>

int main() {
    std::cout << "--- everything is an address under the hood ---\n";
    int value = 42;
    int* pointerToValue = &value;
    int& referenceToValue = value;

    std::cout << "&value             = " << &value << "\n";
    std::cout << "pointerToValue     = " << pointerToValue
              << "  <-- PREDICT: same address as &value?\n";
    std::cout << "&referenceToValue  = " << &referenceToValue
              << "  <-- PREDICT: same address as &value?\n";
    std::cout << "(all three lines print the SAME address -- a reference isn't a\n"
              << " second box in memory, it's just another NAME the compiler uses\n"
              << " for the exact same box that 'value' uses.)\n";

    std::cout << "\n--- but the POINTER VARIABLE itself also lives somewhere ---\n";
    std::cout << "&pointerToValue    = " << &pointerToValue
              << "  <-- this is a DIFFERENT address: where the pointer variable\n"
              << "                       itself is stored, not where it points TO.\n";
    // A reference has no equivalent "&referenceToValue is its own separate
    // address" story -- the compiler doesn't give a reference its own
    // storage the way it does for a pointer variable. This is why you
    // cannot ask "how big is a reference" the same way you ask sizeof(pointer).

    std::cout << "\n--- local variables often sit near each other on the stack ---\n";
    int first = 1;
    int second = 2;
    int third = 3;
    std::cout << "&first  = " << &first  << "\n";
    std::cout << "&second = " << &second << "\n";
    std::cout << "&third  = " << &third  << "\n";
    std::cout << "(PREDICT: are these addresses close together, or scattered randomly?\n"
              << " They're usually close because the compiler lays out one function's\n"
              << " locals in one contiguous stack region -- but never RELY on the\n"
              << " exact gap; it depends on compiler, optimization level, and platform.)\n";

    std::cout << "\n--- why *ptr and ref both 'just work' the same way ---\n";
    *pointerToValue = 500;
    std::cout << "after *pointerToValue = 500, value = " << value << "\n";
    referenceToValue = 999;
    std::cout << "after referenceToValue = 999, value = " << value
              << "  <-- both writes landed on the SAME memory location as 'value'\n";

    std::cout << "Madhan printing pointer variable & reference var, pointer " << pointerToValue << " ref address :- " << &referenceToValue << '\n';

    return 0;
}

/*
   THE MENTAL MODEL: a pointer is a real variable that HOLDS an address as
   its value -- you can inspect, copy, and reassign that address. A
   reference is a compiler-level alias with no address-of-its-own story --
   once bound, using it is 100% indistinguishable from using the original
   variable directly. Both ultimately compile down to "an address is
   stored/passed somewhere"; the difference is what the LANGUAGE lets you
   do with that address (reseat it, null it, arithmetic on it) versus what
   it hides from you for safety.
*/
