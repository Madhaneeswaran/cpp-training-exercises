#include <iostream>

// JS BRIDGE: in JavaScript you never think about WHERE a variable lives --
// the engine hides it completely. In C++ every piece of data lives in one
// of a few distinct memory "segments", and which one matters a lot for
// lifetime and performance. This file makes those segments visible by
// printing real addresses from each one.

int globalVar = 10;              // DATA segment (has an initial value)
int globalUninitialized;         // BSS segment (zero-initialized, no value given)

void showStackFrame() {
    int localVar = 20;           // STACK segment -- lives only during this call
    std::cout << "localVar (stack)          = " << &localVar << "\n";
}

int main() {
    std::cout << "--- CODE segment: where the compiled instructions live ---\n";
    std::cout << "address of main itself    = " << (void*)main
              << "  (functions are code, they live here too)\n";

    std::cout << "\n--- DATA / BSS segment: globals live here, for the WHOLE program ---\n";
    std::cout << "globalVar (data)          = " << &globalVar << "\n";
    std::cout << "globalUninitialized (bss) = " << &globalUninitialized << "\n";
    std::cout << "(PREDICT: are these two addresses close together? Globals tend to\n"
              << " cluster near each other, separate from everything below.)\n";

    std::cout << "\n--- STACK segment: local variables, function call frames ---\n";
    int localInMain = 30;
    std::cout << "localInMain (stack)       = " << &localInMain << "\n";
    showStackFrame();
    std::cout << "(notice showStackFrame's localVar printed a DIFFERENT stack address --\n"
              << " each function call gets its own frame, stacked on top of main's.)\n";

    std::cout << "\n--- HEAP segment: memory YOU request explicitly, YOU must free ---\n";
    int* heapVar = new int(40);
    std::cout << "*heapVar (heap)           = " << heapVar
              << "  <-- PREDICT: near the stack addresses above, or far away?\n";
    std::cout << "(heap addresses are typically in a totally different range than stack\n"
              << " addresses -- the OS hands out stack and heap memory from opposite\n"
              << " ends of the process's address space.)\n";
    delete heapVar; // more on this in 04_new_delete.cpp

    std::cout << "\n--- SUMMARY: four things, four different lifetimes ---\n";
    std::cout << "CODE:  exists for the entire program run, never changes\n";
    std::cout << "DATA:  globals, exist for the entire program run\n";
    std::cout << "STACK: local variables, die when their function/block ends\n";
    std::cout << "HEAP:  YOUR variables, exist until YOU call delete (or the program ends)\n";

    return 0;
}

/*
   WHY THIS MATTERS: every bug in the rest of today's files -- dangling
   pointers, memory leaks, stack overflows -- is really just "I misjudged
   which segment this memory was in, and how long it actually lives." Refer
   back to this file whenever the next files feel abstract.
*/
