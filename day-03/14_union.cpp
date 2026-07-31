#include <iostream>

// A union looks like a struct but means something totally different:
// ALL members share the exact SAME memory. Writing to one member
// overwrites whatever was in the others -- a union only ever holds ONE
// value at a time, no matter how many fields it lists.

union Number {
    int asInt;
    float asFloat;
    char asBytes[4];   // same 4 bytes, viewed as individual bytes
};

struct NumberStruct {   // for comparison: a STRUCT with the same fields
    int asInt;
    float asFloat;
    char asBytes[4];
};

int main() {
    std::cout << "--- size comparison: this is the whole point of a union ---\n";
    std::cout << "sizeof(Number)       (union)  = " << sizeof(Number)
              << "  <-- PREDICT: same as the biggest member, or the SUM of all members?\n";
    std::cout << "sizeof(NumberStruct) (struct) = " << sizeof(NumberStruct)
              << "  (a struct reserves separate space for EVERY field)\n";

    std::cout << "\n--- writing to one member OVERWRITES the others ---\n";
    Number n;
    n.asInt = 65;
    std::cout << "n.asInt = " << n.asInt << "\n";
    std::cout << "n.asFloat (same memory, reinterpreted!) = " << n.asFloat
              << "  <-- PREDICT: is this a sensible float, or nonsense?\n";
    // ^ we never wrote to asFloat -- we're reading the SAME 4 bytes that
    // asInt wrote, just interpreted as a different type. The bit pattern
    // for the int 65 is almost never a "nice" float value.

    std::cout << "\n--- using it as intended: examine the raw bytes of a value ---\n";
    n.asInt = 65;   // same bit pattern as the char 'A' -- set it fresh
    std::cout << "n.asInt = 65, viewed one byte at a time:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "  asBytes[" << i << "] = " << (int)n.asBytes[i] << "\n";
    }
    std::cout << "(this is a real, common use of unions: inspecting how a value is\n"
              << " actually laid out in memory, byte by byte.)\n";

    std::cout << "\n--- struct vs union, side by side ---\n";
    NumberStruct s;
    s.asInt = 65;
    s.asFloat = 65.0f;
    std::cout << "s.asInt = " << s.asInt << ", s.asFloat = " << s.asFloat
              << "  <-- a struct keeps BOTH values independently, at the same time\n";

    return 0;
}

/*
   WHY THIS MATTERS TODAY: unions are used for memory optimization when you
   KNOW only one of several fields will ever be needed at once (e.g. a
   variant/tagged-union type that's either "an int result" OR "an error
   code", never both). Modern C++ mostly reaches for std::variant instead
   (type-safe, tracks which member is active for you) -- but the raw union
   above is what std::variant is built on top of, and you'll still see it
   in lower-level or legacy C-style code.

   WARNING: reading a union member you didn't just write to (like we did
   deliberately with asFloat above) is technically undefined behavior in
   strict C++ -- we did it here ON PURPOSE to make the memory-sharing
   visible. In real code, only read back the member you most recently wrote.
*/
