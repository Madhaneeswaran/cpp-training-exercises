#include <iostream>

// I'm a javascript programmer, is this session easy to learn? 
// Yes, but C++ is a bit more verbose than JS. You have to declare types, and you have to manage memory more explicitly. 
// But the concepts are similar, and once you get used to the syntax, it becomes easier.

// Is the below function correct?
int findLargestIndex(int arr[], int size) {
    int largest = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = i;
        }
    }

    return largest;
}

int main() {
    std::cout << "--- declaring and initializing ---\n";
    int scores[5] = {90, 82, 74, 61, 55};   // fixed size, fixed type
    std::cout << "scores[0] = " << scores[0] << "  (arrays are 0-based: first element is index 0)\n";
    std::cout << "scores[4] = " << scores[4] << "  (last valid index is size-1, i.e. 4)\n";

    std::cout << "\n--- modifying an element ---\n";
    scores[2] = 100;
    std::cout << "scores[2] after edit = " << scores[2] << "\n";

    std::cout << "\n--- sizeof an array ---\n";
    std::cout << "sizeof(scores)        = " << sizeof(scores) << " bytes\n";
    std::cout << "sizeof(scores[0])     = " << sizeof(scores[0]) << " bytes (one int)\n";
    int count = sizeof(scores) / sizeof(scores[0]);
    std::cout << "element count (sizeof trick) = " << count
              << "  <-- PREDICT: is this 5, or something else?\n";
              // It is 5, because sizeof(scores) is 20 bytes (5 ints * 4 bytes each), and sizeof(scores[0]) is 4 bytes, so 20 / 4 = 5.

    std::cout << "\n--- looping over every element ---\n";
    for (int i = 0; i < count; i++) {
        std::cout << "scores[" << i << "] = " << scores[i] << "\n";
    }

    std::cout << "\n--- OUT OF BOUNDS: PREDICT before running ---\n";
    // TODO: uncomment the next line. It will most likely NOT crash, and will
    // NOT give a compiler error either -- it will print garbage/nearby
    // memory. C++ does NOT check array bounds for you. This is undefined
    // behavior: it might work, might crash, might silently corrupt something
    // else entirely. That unpredictability IS the lesson.
    std::cout << "scores[10] (out of bounds) = " << scores[10] << "\n";

    std::cout << "\n--- array name decays to a pointer (preview of next file) ---\n";
    std::cout << "scores        = " << scores << "  (address of scores[0])\n";
    std::cout << "&scores[1]    = " << &scores[1] << "  <-- PREDICT: same address, or different?\n"; // different address

    std::cout << "Largest among scores :- " << findLargestIndex(scores, count) << std::endl;
    
    return 0;
}

/*
   CHALLENGE: write a loop that finds the largest value in `scores` without
   using any library function -- just a running "best so far" variable
   updated inside the loop. Print which INDEX held the largest value too.
*/
// Check the findLargest function above, it is correct and returns the largest value in the array. You can also modify it to return the index of the largest value if needed.