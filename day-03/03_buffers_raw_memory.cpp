#include <iostream>
#include <cstring>

// A "buffer" is just a contiguous chunk of memory with NO type safety --
// you decide what the bytes mean. This is the raw material underneath
// char arrays (Day 02), std::string's internals, and file/network I/O.

int main() {
    std::cout << "--- a buffer is just bytes ---\n";
    char buffer[8];                 // 8 raw bytes, meaning undecided yet
    std::memset(buffer, 0, sizeof(buffer)); // zero them all out first (good habit)
    std::cout << "buffer is now 8 zero bytes\n";

    std::cout << "\n--- writing into it as TEXT ---\n";
    std::memcpy(buffer, "Hi!", 4);  // 3 chars + '\0' = 4 bytes
    std::cout << "as text: " << buffer << "\n";

    std::cout << "\n--- the SAME bytes, reinterpreted as NUMBERS ---\n";
    for (int i = 0; i < 8; i++) {
        // (int) cast so it prints as a number, not as a character
        std::cout << "buffer[" << i << "] as a number = " << (int)buffer[i] << "\n";
    }
    std::cout << "<-- PREDICT: 'H' is what number in ASCII? Check buffer[0] against it.\n"; //72

    std::cout << "\n--- an int written into a buffer is really 4 bytes, not '1 number' ---\n";
    char numberBuffer[4];
    int value = 65;                  // same value as ASCII 'A', on purpose
    std::memcpy(numberBuffer, &value, sizeof(value)); // copy the RAW BYTES of `value`
    std::cout << "value = " << value << "\n";
    std::cout << "numberBuffer read back as an int = ";
    int roundTrip;
    std::memcpy(&roundTrip, numberBuffer, sizeof(roundTrip));
    std::cout << roundTrip << "  <-- PREDICT: does it survive the round trip through raw bytes?\n";
    std::cout << "numberBuffer[0] read as a CHAR = " << numberBuffer[0]
              << "  (65 the number and 'A' the character are THE SAME BYTE)\n";

    std::cout << "\n--- THE RISK: buffers don't know their own size ---\n";
    char tiny[4];
    std::cout << "sizeof(tiny) = " << sizeof(tiny) << " bytes\n";
    // TODO: uncomment the next line. memcpy has NO idea `tiny` only holds 4
    // bytes -- you told it to copy 8, so it will, writing 4 bytes past the
    // end of `tiny` into whatever memory happens to be next. This is the
    // exact same bug class as 02_cstyle_strings.cpp's strcpy overflow, but
    // now you're doing it directly at the byte level, with no string
    // functions to hide it.
    std::memcpy(tiny, "OVERFLOW", 8);

    std::cout << tiny << '\n';

    return 0;
}

/*
   WHY THIS MATTERS: every "safe" abstraction you've used so far
   (std::string, std::vector, arrays with bounds-checked .at()) is built
   ON TOP of raw buffers like this one. Understanding that the underlying
   memory has NO idea what it "means" -- text, numbers, whatever -- is what
   makes bugs like buffer overflows and endianness issues make sense later.
*/
