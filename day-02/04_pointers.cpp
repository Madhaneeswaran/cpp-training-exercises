#include <iostream>
#include <string>

void pointerArrayChallenge() {
    std::string pizzas[6] = {"Pizza1", "Pizza2", "Pizza3", "Pizza4", "Pizza5", "Pizza6"};

    std::string *pPizzas = pizzas;

    for (int i = 1; i <= 6; i++) {
        std::cout << pPizzas + i << '\n';
    }
}

int main() {
    // std::cout << "--- a pointer stores an ADDRESS ---\n";
    // int x = 42;
    // int* p = &x;   // '&' = "address of x". p now holds x's address, not 42.
    // std::cout << "x        = " << x << "\n";
    // std::cout << "&x       = " << &x << "  (x's address)\n";
    // std::cout << "p        = " << p << "  <-- PREDICT: same as &x, or different?\n"; // different.
    // std::cout << "*p       = " << *p << "  ('*' = dereference: follow the address to the value)\n";

    // std::cout << "\n--- writing through a pointer changes the original ---\n";
    // *p = 100;
    // std::cout << "after *p = 100, x = " << x
    //           << "  <-- PREDICT: did x change, even though we never touched 'x' by name?\n";

    // std::cout << "\n--- nullptr: a pointer that points to nothing ---\n";
    // int* empty = nullptr;
    // std::cout << "empty = " << empty << "\n";
    // // TODO: uncomment the next line. Dereferencing a null pointer is
    // // undefined behavior -- on most systems it crashes immediately
    // // (segmentation fault). That crash is actually the SAFE outcome: it's
    // // loud and immediate, unlike quieter memory bugs.
    // // std::cout << *empty << "\n";

    // std::cout << "\n--- pointer arithmetic: pointers understand array element size ---\n";
    // int arr[4] = {10, 20, 30, 40};
    // int* ptr = arr;          // array decays to a pointer to its first element
    // std::cout << "*ptr       = " << *ptr << "\n";
    // std::cout << "*(ptr + 1) = " << *(ptr + 1)
    //           << "  <-- PREDICT: ptr+1 means 'add 1 BYTE' or 'add 1 int (4 bytes)'?\n";
    // for (int i = 0; i < 4; i++) {
    //     std::cout << "*(ptr + " << i << ") = " << *(ptr + i) << " address :- " << &ptr[i] << "\n";
    // }

    // std::cout << "\n--- sizeof(pointer) is FIXED regardless of what it points to ---\n";
    // double bigThing = 3.14;
    // double* bigPtr = &bigThing;
    // std::cout << "sizeof(p)      = " << sizeof(p) << "  (pointer to int)\n";
    // std::cout << "sizeof(bigPtr) = " << sizeof(bigPtr)
    //           << "  (pointer to double, same size!) -- an address is an address\n";


    pointerArrayChallenge();
    return 0;
}

/*
   CHALLENGE: declare `int a = 1, b = 2, c = 3;` and an array of THREE
   int pointers `int* arr[3] = {&a, &b, &c};`. Loop over `arr` and print
   *arr[i] for each -- this is a pointer array, different from an array
   accessed through a pointer above. Notice how the syntax rhymes.
*/
