#include <iostream>

int main() {
    std::cout << "--- for loop: counting up ---\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "\n--- while loop: same thing, different shape ---\n";
    int i = 1;
    while (i <= 5) {
        std::cout << i << " ";
        i++;
    }
    std::cout << "\n";

    std::cout << "\n--- do-while: PREDICT how many times this prints ---\n";
    int n = 100; // condition is already false before we even start
    do {
        std::cout << "n = " << n << " (do-while runs body at least ONCE)\n";
        n++;
    } while (n < 5);

    std::cout << "\n--- break vs continue ---\n";
    std::cout << "break stops the loop entirely at 4: ";
    for (int j = 1; j <= 10; j++) {
        if (j == 4) break;
        std::cout << j << " ";
    }
    std::cout << "\n";

    std::cout << "continue skips just one iteration (skipping 4): ";
    for (int j = 1; j <= 6; j++) {
        if (j == 4) continue;
        std::cout << j << " ";
    }
    std::cout << "\n";

    std::cout << "\n--- CHALLENGE: pyramid pattern (nested loops) ---\n";
    // TODO: complete this so it prints:
    // *
    // **
    // ***
    // ****
    // *****
    int rows = 5;
    for (int r = 1; r <= rows; r++) {
        for (int c = 0; c < r; c++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    std::cout << "\n--- CHALLENGE 2: FizzBuzz, 1 to 20 ---\n";
    // Rule: multiples of 3 -> "Fizz", multiples of 5 -> "Buzz",
    // multiples of both -> "FizzBuzz", else print the number.
    // TODO: implement this loop yourself (delete the hint below once done).
    for (int i = 0; i <= 20; i++) {
        if ((i % 3 == 0) && (i % 5 == 0)) {
            std::cout << "FizzBuzz " << i << "\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz " << i << "\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz " << i << "\n";
        } 
    }

    return 0;
}

/*
   NOTE: FizzBuzz is solved here so you can see it run once -- but the real
   exercise is to close this file, open a blank one, and re-type the FizzBuzz
   loop from memory without peeking. That's the difference between reading
   code and knowing code.
*/ // Solved fizzbuzz problem by myself
