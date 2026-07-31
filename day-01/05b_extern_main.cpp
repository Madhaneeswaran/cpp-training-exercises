#include <iostream>

// `extern` here means: "this variable exists somewhere (in another .cpp
// file after linking), don't allocate storage for it here, just let me
// use it." The real storage is in 05b_extern_helper.cpp.
extern int sharedAcrossFiles;
extern void bumpSharedValue();

int main() {
    std::cout << "sharedAcrossFiles (from another file) = " << sharedAcrossFiles << "\n";
    bumpSharedValue(); // defined in the OTHER file, modifies the SAME variable
    std::cout << "after bumpSharedValue(): " << sharedAcrossFiles
              << "  <-- proves both files see the same memory\n";
    return 0;
}

/*
   BUILD THIS ONE MANUALLY (it needs both files linked together):
     g++ -std=c++17 -Wall 05b_extern_main.cpp 05b_extern_helper.cpp -o 05b_extern.exe
     ./05b_extern.exe

   The Makefile in this folder already does this for you as target `extern`.
*/
