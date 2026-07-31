#include <iostream>

int main() {
    std::cout << "--- new: allocate ONE object on the heap ---\n";
    int* single = new int(42);      // ( ) initializes it to 42, like a constructor call
    std::cout << "*single = " << *single << "\n";
    delete single;                  // give the memory back
    single = nullptr;               // best practice: null it so you can't use it by accident
    std::cout << "deleted and nulled: single = " << single << "\n";

    std::cout << "\n--- new[]: allocate an ARRAY on the heap ---\n";
    int size = 5; // notice: this can be a RUNTIME variable, unlike a stack array's fixed size
    int* dynamicArray = new int[size];
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10;
    }
    std::cout << "dynamicArray: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";
    delete[] dynamicArray;          // MUST use delete[] to match new[] -- see below
    dynamicArray = nullptr;

    std::cout << "\n--- WHY new[] NEEDS delete[], not plain delete ---\n";
    std::cout << "`new[]` stores extra bookkeeping (how many elements) right before\n"
              << "the array in memory, so `delete[]` knows how many destructors to run.\n"
              << "`delete` (no brackets) doesn't know to look for that bookkeeping --\n"
              << "using the wrong one is undefined behavior: it might work by luck on\n"
              << "simple types like int, but WILL corrupt memory for objects with\n"
              << "real destructors (like std::string).\n";
    // TODO: change the `delete[] dynamicArray;` above to plain `delete
    // dynamicArray;` (before it was set to nullptr) and note that this file
    // uses only `int`s, so you likely won't SEE a crash -- that's the scary
    // part. The bug is real even when you get lucky and nothing visibly
    // breaks.

    std::cout << "\n--- new returning a stack-unfriendly SIZE ---\n";
    int hugeSize = 10; // small here so the demo is safe -- imagine this from user input
    // double* prices = new double[hugeSize];

    double* prices = new double[hugeSize];

    for (int i = 0; i < 10; i++) prices[i] = i + 0.99;
    std::cout << "prices[9] = " << prices[9] << '\n'
              << "  (a stack array `double prices[hugeSize]` wouldn't even compile --\n"
              << "   stack arrays need a size known AT COMPILE TIME, heap arrays don't)\n";
    delete[] prices;
    prices = nullptr;

    return 0;
}

/*
   JS BRIDGE: `new SomeClass()` in JS also creates an object, but you never
   call the JS equivalent of `delete` -- the garbage collector finds objects
   nobody references anymore and frees them automatically, whenever it feels
   like it. C++'s `new` looks similar but is only HALF the story: YOU are
   the garbage collector now. Forget the `delete`, and nothing ever
   automatically cleans up (see 05_memory_leaks.cpp next).
*/
