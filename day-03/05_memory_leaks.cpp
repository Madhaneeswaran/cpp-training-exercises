#include <iostream>

// A LEAK is heap memory that's still "allocated" (the OS considers it in
// use) but NOTHING in your program can reach it anymore -- you lost the
// only pointer that pointed to it. It's not deleted, but it's also
// unusable. Forever, until the program exits.

void obviousLeak() {
    int* leaked = new int(123);
    std::cout << "allocated an int inside obviousLeak(), value = " << *leaked << "\n";

    // @claude: Here `delete leaked;` is enough to avoid memory leak or should we also do `leaked = nullptr;`

    // TODO: there is no `delete leaked;` here on purpose. When this
    // function returns, the LOCAL VARIABLE `leaked` (the pointer, on the
    // stack) dies -- but the int it pointed to (on the heap) does NOT.
    // Nothing points to that memory anymore. It's gone for good, but the
    // memory is still "reserved". That's a leak.
}

void leakInALoop() {
    std::cout << "\n--- a more realistic leak: overwriting the pointer in a loop ---\n";
    int* ptr = nullptr;

    // Method 1
    for (int i = 0; i < 5; i++) {
        ptr = new int(i);            // each iteration allocates a NEW block...
        std::cout << "allocated block holding " << *ptr << "\n";
        // ...and immediately abandons the PREVIOUS block, because `ptr` now
        // points somewhere else. Only the LAST allocation (i=4) ever gets
        // a chance to be deleted -- the other 4 are already unreachable.
    }
    delete ptr; // this only cleans up the last one!
    std::cout << "deleted only the LAST allocation -- 4 earlier ones already leaked\n";

    /* // Can we delete like below - Method 2
    int *ptr2 = new int[5];
    for (int i = 0; i < 5; i++) {
        ptr2[i] = i;
        std::cout << "stored " << ptr2[i] << " at index " << i << "\n";
    }
    delete[] ptr2;
    ptr2 = nullptr; */
}

void fixedVersion() {
    std::cout << "\n--- the fix: delete BEFORE you lose the pointer ---\n";
    int* ptr = nullptr;
    for (int i = 0; i < 5; i++) {
        ptr = new int(i);
        std::cout << "allocated and immediately using block holding " << *ptr << "\n";
        delete ptr;   // clean up THIS iteration's allocation before the next one
        std::cout << "After delete " << ptr << std::endl;
        ptr = nullptr; // @claude: What happens if we don't do ptr = nullptr;
        std::cout << "After null ptr " << ptr << std::endl;
    }
    std::cout << "no leaks: every allocation was matched with a delete\n";
}

int main() {
    obviousLeak();
    leakInALoop();
    fixedVersion();

    std::cout << "\n--- why this matters in a real program ---\n";
    std::cout << "This tiny program leaks a few bytes and then exits -- the OS reclaims\n"
              << "ALL of a process's memory when it exits, leak or not, so you won't\n"
              << "see any damage here. The real danger is a LONG-RUNNING program (a\n"
              << "server, a game, an app left open for days) that leaks a little bit\n"
              << "on every request or every frame -- memory usage climbs and climbs\n"
              << "until the machine runs out.\n";

    return 0;
}

/*
   JS BRIDGE: this entire failure mode is what JS's garbage collector exists
   to prevent -- it tracks reachability for you and frees anything nothing
   points to anymore. C++ gives you the raw power (and the raw risk)
   instead. This is also exactly the problem `unique_ptr`/`shared_ptr`
   (07/08) are designed to solve: automatic delete, without a garbage
   collector.
*/
