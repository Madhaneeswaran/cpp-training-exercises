#include <iostream>
#include <climits>   // INT_MAX, CHAR_MAX, SHRT_MAX ...
#include <cfloat>    // FLT_MAX, DBL_MAX ...

int main() {
    // ---- PREDICT FIRST ----
    // Before running, guess (roughly) how many BYTES each of these takes
    // on a typical 64-bit machine: bool, char, int, float, double.
    // Write your guesses in a comment here:
    // bool = ?   char = ?   int = ?   float = ?   double = ?

    std::cout << "--- sizeof (in bytes) ---\n";
    std::cout << "bool:   " << sizeof(bool)   << "\n";
    std::cout << "char:   " << sizeof(char)   << "\n";
    std::cout << "int:    " << sizeof(int)    << "\n";
    std::cout << "float:  " << sizeof(float)  << "\n";
    std::cout << "double: " << sizeof(double) << "\n";

    std::cout << "\n--- ranges ---\n";
    std::cout << "int range:   " << INT_MIN << " to " << INT_MAX << "\n";
    std::cout << "char range:  " << (int)CHAR_MIN << " to " << (int)CHAR_MAX << "\n";
    std::cout << "float max:   " << FLT_MAX << "\n";
    std::cout << "double max:  " << DBL_MAX << "\n";

    // ---- OVERFLOW EXPERIMENT ----
    // An int can't hold more than INT_MAX. What happens if we push past it?
    int maxed = INT_MAX;
    std::cout << "\nINT_MAX:      " << maxed << "\n";
    std::cout << "INT_MAX + 1:  " << maxed + 1 << "  <-- PREDICT this before running!\n";

    // ---- PRECISION EXPERIMENT ----
    // float has ~7 significant digits, double has ~15-17.
    float f = 1.085f / 3.020f;
    double d = 1.085 / 3.020;
    std::cout << "\n1/3 as float:  " << f << "\n";
    std::cout << "1/3 as double: " << d << "\n";
    std::cout << "(Notice how much more precision the double keeps.)\n";

    // ---- CHAR IS SECRETLY A NUMBER ----
    char letter = 'A';
    std::cout << "\nchar 'A' printed as char: " << letter << "\n";
    std::cout << "char 'A' printed as int:  " << (int)letter << "\n";
    // TODO: print 'A' + 1 as a char. What letter do you get? Why?

    std::cout << "char A + 1 is :- " << (int)(letter+1) << '\n' << std::endl;

    return 0;
}

/*
   CHALLENGE: A `bool` only needs 1 bit (true/false) but sizeof(bool) above
   is NOT 1 bit. Why not? (Hint: think about the smallest addressable unit
   of memory on real hardware.)

   // Because the smallest addressable unit of memory on real hardware is 1 byte. Is that correct? 
   // Yes, that's correct. A bool is stored in a byte, even though it only needs 1 bit to represent true/false. This is due to the way memory is organized and accessed in most computer architectures.
*/
