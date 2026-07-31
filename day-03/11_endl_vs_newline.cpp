#include <iostream>
#include <chrono>

int main() {
    std::cout << "--- both LOOK identical on screen ---\n";
    std::cout << "line with endl" << std::endl;
    std::cout << "line with \\n" << "\n";
    std::cout << "(no visible difference above -- the difference is what happens\n"
              << " BEHIND the scenes, not what you see.)\n";

    std::cout << "\n--- endl = '\\n' PLUS a forced flush ---\n";
    std::cout << "std::endl does two things: (1) writes a newline character, exactly\n"
              << "like '\\n', then (2) forces the output buffer to flush immediately,\n"
              << "pushing everything written so far out to the terminal/file right now,\n"
              << "even if the buffer wasn't full yet.\n";

    std::cout << "\n--- measuring the cost: many endl vs many '\\n' ---\n";
    const int iterations = 100000;

    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        std::cout << i << std::endl;   // flushes EVERY single iteration
    }
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        std::cout << i << "\n";        // only flushes when the buffer fills up naturally
    }
    auto end2 = std::chrono::high_resolution_clock::now();

    auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

    std::cout << "\n--- results (this output itself just used a LOT of endl, oops) ---\n";
    std::cout << "100,000 lines with std::endl took: " << ms1 << " ms\n";
    std::cout << "100,000 lines with '\\n'      took: " << ms2 << " ms\n";
    std::cout << "<-- PREDICT before running: which one is slower, and roughly how much?\n";

    std::cout << "\n--- rule of thumb ---\n";
    std::cout << "use '\\n' for routine output inside loops/hot paths.\n"
              << "use std::endl only when you specifically NEED the flush right now --\n"
              << "e.g. right before a program might crash, or when writing progress\n"
              << "you want visible immediately (not buffered and shown late).\n";

    return 0;
}

/*
   NOTE: exact timings above depend heavily on whether your terminal itself
   is slow to render (a real terminal window can dominate the timing more
   than the flush does). Redirect to a file to see a cleaner comparison:
     ./11_endl_vs_newline.exe > output.txt
*/
