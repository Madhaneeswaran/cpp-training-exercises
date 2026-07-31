#include <iostream>
#include <cstring>   // strcpy, strcat, strlen, strcmp

int main() {
    std::cout << "--- a C-style string IS a char array ---\n";
    char greeting[20] = "Hello";   // compiler adds the '\0' terminator for you here
    std::cout << "greeting = " << greeting << "\n";
    std::cout << "greeting[0] = " << greeting[0] << ", greeting[4] = " << greeting[4] << "\n";

    std::cout << "\n--- the null terminator is what makes it a 'string' ---\n";
    std::cout << "sizeof(greeting)  = " << sizeof(greeting) << "  (the full buffer, 20 bytes)\n";
    std::cout << "strlen(greeting)  = " << strlen(greeting)
              << "  <-- PREDICT: why is this smaller than sizeof?\n";
    // strlen counts characters UP TO (not including) the first '\0'. Everything
    // after that '\0' in the buffer is just unused leftover memory.

    std::cout << "\n--- strcpy / strcat ---\n";
    char full[40];
    strcpy(full, greeting);      // full = "Hello"
    strcat(full, ", World!");    // full = "Hello, World!"
    std::cout << "full = " << full << "\n";

    std::cout << "\n--- strcmp ---\n";
    char a[] = "apple";
    char b[] = "banana";
    std::cout << "strcmp(\"apple\", \"banana\") = " << strcmp(a, b)
              << "  (negative means a < b alphabetically)\n";

    // b[] is greater than a[] alphabetically

    std::cout << "\n--- THE DANGER: strcpy does not check buffer size ---\n";
    char tiny[6]; // just enough for "Hello" + '\0'
    strcpy(tiny, "Hello");
    std::cout << "tiny = " << tiny << "  (fits exactly)\n";
    // TODO: uncomment the next line. "Hello, World!" is 14 characters + '\0',
    // but `tiny` only has room for 6. strcpy will happily write PAST the end
    // of `tiny` into whatever memory comes after it -- this is a real
    // buffer overflow, the same bug class behind decades of security CVEs.
    strcpy(tiny, "Hello, World!");
    std::cout << "tiny after overflow = " << tiny << "\n";

    return 0;
}

/*
   WHY THIS MATTERS: every quirk above -- manual null terminators, strlen vs
   sizeof, and strcpy's total lack of bounds checking -- is exactly why
   std::string exists. Open 03_std_string.cpp next and do the SAME
   operations (copy, concatenate, compare) and notice how many ways to
   shoot yourself in the foot simply disappear.
*/
