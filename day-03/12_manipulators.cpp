#include <iostream>
#include <iomanip>   // setw, setprecision, setfill, left/right, fixed, etc.

int main() {
    std::cout << "--- setw: minimum field WIDTH (applies to the NEXT output only) ---\n";
    std::cout << "[" << std::setw(10) << 42 << "]\n";
    std::cout << "[" << std::setw(10) << "hi" << "]\n";
    std::cout << "<-- PREDICT: is the text left-aligned or right-aligned by default?\n";

    std::cout << "\n--- setw only applies ONCE -- a classic gotcha ---\n";
    std::cout << std::setw(6) << 1 << std::setw(6) << 22 << std::setw(6) << 333 << "\n";
    std::cout << "(all three numbers still got padded, because setw was written before\n"
              << " EACH one -- if you only write it once, only the FIRST value is padded)\n";

    std::cout << "\n--- left vs right alignment ---\n";
    std::cout << std::left  << "[" << std::setw(10) << "left"  << "]\n";
    std::cout << std::right << "[" << std::setw(10) << "right" << "]\n";

    std::cout << "\n--- setfill: change the PADDING character (default is space) ---\n";
    std::cout << std::setfill('*') << std::setw(10) << 42 << "\n";
    std::cout << std::setfill('0') << std::setw(5)  << 7  << "  (classic zero-padding, e.g. \"00007\")\n";
    std::cout << std::setfill(' '); // reset back to normal, or every following field gets padded oddly

    std::cout << "\n--- setprecision + fixed: controlling decimal places ---\n";
    double pi = 3.14159265358979;
    std::cout << "default:              " << pi << "\n";
    std::cout << "setprecision(3):      " << std::setprecision(3) << pi
              << "  <-- PREDICT: does this round to 3 decimal places, or 3 SIGNIFICANT digits?\n";
    std::cout << "fixed + precision(3): " << std::fixed << std::setprecision(3) << pi
              << "  (fixed changes precision's MEANING to 'decimal places')\n";
    std::cout << std::setprecision(6); // restore the default precision (6, unfixed)

    std::cout << "\n--- a practical table, combining several manipulators ---\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(12) << "Item" << std::right << std::setw(8) << "Price" << "\n";
    std::cout << std::left << std::setw(12) << "Coffee" << std::right << std::setw(8) << 3.5 << "\n";
    std::cout << std::left << std::setw(12) << "Sandwich" << std::right << std::setw(8) << 6.99 << "\n";

    return 0;
}

/*
   GOTCHA WORTH REMEMBERING: setw() resets itself after ONE use, but fixed,
   setprecision(), setfill(), left/right, and std::boolalpha DO NOT reset --
   they stay in effect for every std::cout call after them until you
   explicitly change them again. Mixing these up (forgetting a manipulator
   "stuck" from earlier output) is a very common source of "why does my
   number formatting look wrong 20 lines later" bugs.
*/
