#include <iostream>
#include <cmath>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

int main() {
    std::cout << "--- math functions ---\n";
    double v = -7.6;
    std::cout << "v = " << v << "\n";
    std::cout << "abs(v)   = " << std::abs(v)   << "\n";
    std::cout << "floor(v) = " << std::floor(v) << "  (rounds toward -infinity)\n";
    std::cout << "ceil(v)  = " << std::ceil(v)  << "  (rounds toward +infinity)\n";
    std::cout << "sqrt(49) = " << std::sqrt(49) << "\n";
    std::cout << "pow(2,10)= " << std::pow(2, 10) << "\n";

    std::cout << "\n--- classic C-style random numbers ---\n";
    std::srand((unsigned)std::time(nullptr)); // seed with current time
    std::cout << "3 random numbers from 1 to 6 (like a dice roll):\n";
    for (int i = 0; i < 3; i++) {
        int roll = (std::rand() % 6) + 1; // rand() % 6 gives 0-5, +1 gives 1-6
        std::cout << "roll " << (i + 1) << ": " << roll << "\n";
    }

    std::cout << "\n--- MODERN C++ alternative: <random> (better quality) ---\n";
    // Old rand() has known statistical weaknesses. Modern code prefers this:
    // #include <random>
    // std::mt19937 rng(std::random_device{}());
    // std::uniform_int_distribution<int> dist(1, 6);
    // int roll = dist(rng);
    std::cout << "(see the commented block above -- try swapping it in!)\n";

    return 0;
}

/*
   EXPERIMENT: run this program 3 separate times (recompiling isn't needed,
   just re-run the .exe). Do you get different dice rolls each time? Now
   remove the std::srand(...) line entirely and run it 3 times again --
   what changes? This is how you learn WHY seeding matters.
*/
