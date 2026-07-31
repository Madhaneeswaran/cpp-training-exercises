#include <iostream>

// A DANGLING pointer is the opposite problem from a leak: instead of
// forgetting to delete, you deleted (or otherwise lost) the memory but kept
// USING the pointer anyway. The memory might be reused by something else
// entirely -- reading or writing through a dangling pointer is undefined
// behavior: could print garbage, could crash, could silently corrupt
// unrelated data.

int* returnsDanglingPointer() {
    int localValue = 99;      // lives on THIS function's stack frame
    return &localValue;       // returning its address...
} // ...but localValue DIES right here, when the function returns!

int main() {
    std::cout << "--- classic case 1: returning the address of a local variable ---\n";
    std::cout << "(compile this file and read the g++ warning above -- it should say\n"
              << " something like 'address of local variable returned'. The compiler\n"
              << " CAN catch this specific case; it can't catch every dangling pointer.)\n";
    int* danger = returnsDanglingPointer();
    std::cout << "danger = " << danger << "  (the address still LOOKS valid...)\n";
    // TODO: uncomment the next line. `danger` points to stack memory that
    // no longer belongs to any variable -- it might still show 99 by pure
    // luck (nothing overwrote that stack slot yet), or it might show
    // garbage. Either way, relying on it is a bug, whether or not it
    // "looks fine" right now.
    // std::cout << "*danger = " << *danger << "  <-- UNDEFINED BEHAVIOR\n";

    std::cout << "\n--- classic case 2: using a pointer AFTER delete ---\n";
    int* heapValue = new int(50);
    std::cout << "*heapValue before delete = " << *heapValue << "\n";
    delete heapValue;    // the memory is now free for reuse by anything
    // TODO: uncomment the next line. `heapValue` still holds the OLD
    // address, but that memory is no longer "yours" -- some other
    // allocation could already be sitting there.
    std::cout << "*heapValue after delete  (should give a garbage value) = " << *heapValue << "  <-- UNDEFINED BEHAVIOR\n";

    std::cout << "\n--- THE FIX: null it immediately after delete ---\n";
    heapValue = nullptr; // this is the "prevent by setting to nullptr" rule from Day_03.md
    std::cout << "heapValue = " << heapValue << "\n";
    if (heapValue != nullptr) {
        std::cout << "*heapValue = " << *heapValue << "\n";
    } else {
        std::cout << "heapValue is null -- we SAFELY skipped using it, instead of guessing.\n";
    }
    std::cout << "(a nullptr dereference crashes LOUDLY and IMMEDIATELY -- which is far\n"
              << " better than a dangling pointer that corrupts memory SILENTLY.)\n";

    return 0;
}

/*
   JS BRIDGE: this bug class cannot exist in JS. As long as ANY reference to
   an object exists, the garbage collector guarantees it stays alive -- you
   can never "delete out from under yourself" by accident. In C++ that
   guarantee doesn't exist unless YOU build it -- which is exactly what
   smart pointers (07_unique_ptr.cpp, 08_shared_weak_ptr.cpp) automate.
*/
