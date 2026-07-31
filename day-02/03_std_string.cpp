#include <iostream>
#include <string>

int main() {
    std::cout << "--- declaring and concatenating ---\n";
    std::string greeting = "Hello";
    std::string full = greeting + ", World!";   // '+' just works -- no strcat needed
    std::cout << "full = " << full << "\n";

    std::cout << "\n--- growing at runtime (no fixed buffer size!) ---\n";
    full += " Nice to meet you.";   // std::string resizes itself automatically
    std::cout << "full after += : " << full << "\n";
    std::cout << "full.length()  = " << full.length() << "\n";

    std::cout << "\n--- indexing and comparing ---\n";
    std::cout << "full[0] = " << full[0] << "\n";
    std::string apple = "apple", banana = "banana";
    std::cout << "apple == banana ? " << (apple == banana ? "true" : "false")
              << "  (operator== just works, unlike strcmp)\n";
    std::cout << "apple < banana  ? " << (apple < banana ? "true" : "false") << "\n";

    std::cout << "\n--- useful member functions ---\n";
    std::cout << "full.find(\"World\") = " << full.find("World") // 7 is the answer, is that correct? 
              << "  (index where \"World\" starts)\n";
    std::cout << "full.substr(7, 5)  = " << full.substr(7, 5)
              << "  <-- PREDICT which 5 characters this extracts\n"; // Is 'World' right?   

    std::cout << "\n--- SAFETY: at() checks bounds, operator[] does not ---\n";
    // TODO: uncomment the next line. Unlike a raw char array reading garbage,
    // .at() THROWS a std::out_of_range exception you can actually catch --
    // it fails loudly and safely instead of silently corrupting memory.
    std::cout << full.at(9) << "\n";
    std::cout << "(try full.at(9999) above once you've read the note)\n";

    std::cout << "\n--- passing to a function ---\n";
    auto shout = [](std::string s) {   // pass by value here: gets its OWN copy
        for (auto& ch : s) ch = toupper(ch);
        return s;
    };
    std::cout << "shout(full) = " << shout(full) << "\n";
    std::cout << "full is unchanged: " << full << "  <-- PREDICT: did shout() modify the original?\n";

    return 0;
}

/*
   COMPARE WITH 02_cstyle_strings.cpp: same operations (copy, concatenate,
   compare), but no manual '\0', no strcpy buffer-size math, and .at() gives
   you a safe bounds-checked option that a raw char array can never offer.
   That's "automatic memory management" and "ease of use" from Day_02.md's
   learning outcomes, made concrete.
*/
