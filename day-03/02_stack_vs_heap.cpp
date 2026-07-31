#include <iostream>

// JS BRIDGE: JS objects are ALWAYS heap-allocated and ALWAYS garbage
// collected -- you never choose. C++ makes you choose, every time, between
// two very different kinds of memory:
//   STACK: automatic. Created and destroyed for you. Fast. Limited size.
//   HEAP:  manual. YOU create it (new) and YOU destroy it (delete). Slower
//          to allocate, but can be huge, and can outlive the function that
//          created it.

struct BigStruct {
    int data[1000]; // 4000 bytes -- deliberately chunky for this demo
};

void stackAllocation() {
    std::cout << "--- stack allocation ---\n";
    BigStruct onStack; // created instantly, destroyed automatically at '}'
    onStack.data[0] = 1;
    std::cout << "onStack created at " << &onStack << " (destroyed automatically when this function returns)\n";
}

void heapAllocation() {
    std::cout << "\n--- heap allocation ---\n";
    BigStruct* onHeap = new BigStruct(); // YOU asked for this memory...
    onHeap->data[0] = 1;
    std::cout << "onHeap created at " << onHeap << " (will NOT be destroyed unless we delete it)\n";
    delete onHeap; // ...so YOU must give it back. Forget this and it's a leak (see 05).
    std::cout << "deleted -- memory returned to the heap\n";
}

int main() {
    stackAllocation();
    heapAllocation();

    std::cout << "\n--- lifetime: heap memory can OUTLIVE the function that created it ---\n";
    // TODO: this is impossible to do safely with a stack variable. Try
    // writing a function `int* makeOnStack() { int x = 5; return &x; }` and
    // call it -- it will compile (maybe with a warning), but the returned
    // pointer is already dangling (see 06_dangling_pointers.cpp). A
    // heap-allocated int has no such problem:
    int* survivesTheFunction = [] {
        int* p = new int(99); // heap memory doesn't die when this lambda returns
        return p;
    }();
    std::cout << "*survivesTheFunction = " << *survivesTheFunction
              << "  (still valid, even though the lambda that created it already returned)\n";
    delete survivesTheFunction;

    std::cout << "\n--- STACK OVERFLOW: the stack is fast but SMALL ---\n";
    std::cout << "(commented out below on purpose -- it WILL crash your program)\n";
    // TODO: uncomment this function and the call to it below to see a real
    // stack overflow. Each call pushes another frame onto the stack with no
    // way to stop, until the stack runs out of space and the OS kills the
    // process. This is the literal mechanism behind Day_03.md's memory
    // concept diagram.
    /*
    void infinite() {
        int wastesSpace[1000]; // makes each frame bigger, overflows FASTER
        wastesSpace[0] = 1;
        infinite();
    }
    infinite();
    */

    return 0;
}

/*
   RULE OF THUMB: use the stack (plain local variables) by default -- it's
   faster and you can never forget to clean it up. Reach for the heap
   (`new`) only when you need memory to survive past the function that
   created it, or when the data is too large/variable-sized for the stack.
*/
