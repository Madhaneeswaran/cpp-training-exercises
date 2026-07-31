// CAPSTONE: Roster Reverser
// Combines everything from today: arrays, std::string, pointers, references,
// pass-by-pointer vs pass-by-reference, and the memory model behind both.

#include <iostream>
#include <string>
#include <cstring>

const int ROSTER_SIZE = 5;

// PASS BY REFERENCE: swap two std::string slots directly, no pointer syntax
// needed at the call site.
void swapNames(std::string& a, std::string& b) {
    std::string temp = a;
    a = b;
    b = temp;
}

// PASS BY POINTER: walks the array using pointer arithmetic (arr + i) instead
// of the [] operator, and reverses it in place using swapNames() above.
void reverseRoster(std::string* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int mirror = size - 1 - i;
        swapNames(*(arr + i), *(arr + mirror));   // *(arr+i) is the same slot as arr[i]
    }
}

// Returns the INDEX of the alphabetically-first name, using pointer
// comparison instead of [] to prove the two are interchangeable.
int findFirstAlphabetically(const std::string* arr, int size) {
    int bestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *(arr + bestIndex)) {
            bestIndex = i;
        }
    }
    return bestIndex;
}

int main() {
    std::string roster[ROSTER_SIZE] = {"Priya", "Arjun", "Zoya", "Kiran", "Divya"};

    std::cout << "--- original roster ---\n";
    for (int i = 0; i < ROSTER_SIZE; i++) {
        std::cout << i << ": " << roster[i] << "\n";
    }

    std::cout << "\n--- reversing in place (pointer-walked array + reference swap) ---\n";
    reverseRoster(roster, ROSTER_SIZE);
    for (int i = 0; i < ROSTER_SIZE; i++) {
        std::cout << i << ": " << roster[i] << "\n";
    }
    std::cout << "<-- PREDICT before running: was \"Divya\" originally last, and is it first now?\n";

    std::cout << "\n--- finding the alphabetically-first name ---\n";
    int firstIndex = findFirstAlphabetically(roster, ROSTER_SIZE);
    std::cout << "alphabetically first: " << roster[firstIndex]
              << " (at index " << firstIndex << ")\n";

    std::cout << "\n--- building a C-style badge from the winner (std::string -> char[]) ---\n";
    char badge[32];
    strcpy(badge, roster[firstIndex].c_str());   // .c_str() exposes the underlying char*
    strcat(badge, "'s Badge");
    std::cout << "badge = " << badge << "\n";

    std::cout << "\n--- proving reference params see the SAME memory as the array slot ---\n";
    std::cout << "&roster[0]        = " << &roster[0] << "\n";
    std::string& firstSlotRef = roster[0];
    std::cout << "&firstSlotRef     = " << &firstSlotRef
              << "  <-- PREDICT: identical to &roster[0]?\n";

    return 0;
}

/*
   TRY IT:
     g++ -std=c++17 -Wall 99_capstone_roster_reverser.cpp -o 99_capstone.exe
     ./99_capstone.exe

   STRETCH GOALS (optional, once the base program works):
   1. Add a `bool rosterContains(const std::string* arr, int size, const
      std::string& name)` function and call it with both a named string
      variable AND a raw string literal -- confirm both bind fine to the
      `const std::string&` parameter (this is the const-ref flexibility
      from 08_lvalue_rvalue.cpp).
   2. Rewrite reverseRoster() to take `std::string arr[]` syntax instead of
      `std::string* arr` and confirm the generated behavior is identical --
      this proves an array parameter always decays to a pointer.
   3. Add a buffer-size TODO on purpose: shrink `badge` to 10 bytes and
      predict what strcpy/strcat does when the badge text no longer fits.
*/
