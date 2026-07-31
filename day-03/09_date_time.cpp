#include <iostream>
#include <ctime>

int main() {
    std::cout << "--- getting the current time ---\n";
    std::time_t now = std::time(nullptr);   // seconds since Jan 1, 1970 (the "epoch")
    std::cout << "raw time_t value = " << now << "  (not very human-readable yet)\n";

    std::cout << "\n--- converting to a readable string ---\n";
    std::cout << "ctime(&now) = " << std::ctime(&now);   // ctime() already includes '\n'

    std::cout << "\n--- breaking it into a `tm` struct (year, month, day, etc.) ---\n";
    std::tm* localTime = std::localtime(&now);
    std::cout << "year  = " << (localTime->tm_year + 1900)
              << "  <-- PREDICT: why +1900? (tm_year counts YEARS SINCE 1900, a classic C gotcha)\n";
    std::cout << "month = " << (localTime->tm_mon + 1)
              << "  <-- PREDICT: why +1? (tm_mon is 0-11, January = 0, another gotcha)\n";
    std::cout << "day   = " << localTime->tm_mday << "  (tm_mday IS 1-31, no offset needed)\n";
    std::cout << "hour  = " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << "\n";

    std::cout << "\n--- formatting with strftime (like a mini template engine) ---\n";
    char formatted[64];
    std::strftime(formatted, sizeof(formatted), "%Y-%m-%d %H:%M:%S", localTime);
    std::cout << "formatted = " << formatted << "\n";

    char justDate[16];
    std::strftime(justDate, sizeof(justDate), "%d/%m/%Y", localTime);
    std::cout << "justDate  = " << justDate << "\n";

    std::cout << "\n--- measuring elapsed time ---\n";
    std::clock_t start = std::clock();
    long busyWork = 0;
    for (long i = 0; i < 50000000; i++) busyWork += i; // just to burn a little time
    std::clock_t end = std::clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "that loop took about " << seconds << " seconds (busyWork = " << busyWork << ")\n";

    return 0;
}

/*
   JS BRIDGE: this whole file is C++'s (much older, much clunkier)
   equivalent of `new Date()` and `Date.prototype.toLocaleDateString()`.
   The `tm_year + 1900` / `tm_mon + 1` gotchas above are notorious --
   they've caused real Y2K-adjacent date bugs in production C/C++ code.
   Modern C++ (C++20's <chrono> calendar features) fixes this ergonomics
   problem, but the <ctime> API above is still extremely common in existing
   codebases, which is why Day_03.md has you learn it first.
*/
