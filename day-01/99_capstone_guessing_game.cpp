// CAPSTONE: Number Guessing Game
// Combines everything from today: variables, constants, operators, loops,
// decision making, numbers (random), and functions.

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const int MAX_ATTEMPTS = 7;

// Returns 0 if correct, negative if guess too low, positive if too high.
int compareGuess(int guess, int secret) {
    if (guess < secret) return -1;
    if (guess > secret) return 1;
    return 0;
}

int countAttemptsSoFar() {
    static int attempts = 0; // storage class: static -> survives across calls
    attempts++;
    return attempts;
}

int main() {
    std::srand((unsigned)std::time(nullptr));
    int secret = (std::rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;

    std::cout << "Guess a number between " << MIN_NUMBER << " and " << MAX_NUMBER
              << ". You have " << MAX_ATTEMPTS << " attempts.\n";

    bool won = false;
    int attempt = 0;

    while (attempt < MAX_ATTEMPTS) {
        attempt = countAttemptsSoFar();
        std::cout << "Attempt " << attempt << "/" << MAX_ATTEMPTS << " - your guess: ";

        int guess;
        if (!(std::cin >> guess)) {
            std::cout << "\nInput ended, stopping game.\n";
            break;
        }

        int result = compareGuess(guess, secret);
        if (result == 0) {
            std::cout << "Correct! The number was " << secret << ".\n";
            won = true;
            break;
        } else if (result < 0) {
            std::cout << "Too low.\n";
        } else {
            std::cout << "Too high.\n";
        }
    }

    if (!won) {
        std::cout << "Out of attempts! The number was " << secret << ".\n";
    }

    return 0;
}

/*
   TRY IT INTERACTIVELY:
     g++ -std=c++17 -Wall 99_capstone_guessing_game.cpp -o 99_capstone.exe
     ./99_capstone.exe

   TEST IT NON-INTERACTIVELY (feeds guesses via a pipe, useful for quick
   sanity checks without typing):
     echo "50 25 75 60 65 62 63" | ./99_capstone.exe

   STRETCH GOALS (optional, once the base game works):
   1. Track and print the BEST (fewest-attempt) win across multiple games
      using a static variable, similar to countAttemptsSoFar().
   2. Add a difficulty menu (easy/medium/hard) using a switch statement
      that changes MAX_ATTEMPTS.
   3. Reject out-of-range guesses (below MIN_NUMBER or above MAX_NUMBER)
      without consuming an attempt.
*/
