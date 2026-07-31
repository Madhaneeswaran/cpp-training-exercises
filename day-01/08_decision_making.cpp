#include <iostream>

int main() {
    std::cout << "--- if / else if / else: grade calculator ---\n";
    int scores[] = {95, 82, 71, 60, 40};
    int count = 5;

    for (int i = 0; i < count; i++) {
        int score = scores[i];
        char grade;
        if (score >= 90)      grade = 'A';
        else if (score >= 80) grade = 'B';
        else if (score >= 70) grade = 'C';
        else if (score >= 60) grade = 'D';
        else                  grade = 'F';
        std::cout << "score " << score << " -> grade " << grade << "\n";
    }

    std::cout << "\n--- switch: day of week ---\n";
    int day = 3;
    switch (day) {
        case 1: std::cout << "Monday\n"; break;
        case 2: std::cout << "Tuesday\n"; break;
        case 3: std::cout << "Wednesday\n"; break;
        case 4: std::cout << "Thursday\n"; break;
        case 5: std::cout << "Friday\n"; break;
        case 6:
        case 7: std::cout << "Weekend\n"; break;
        default: std::cout << "Invalid day\n"; break;
    }

    std::cout << "\n--- switch fallthrough TRAP: predict the output ---\n";
    int x = 2;
    switch (x) {
        case 1: std::cout << "one\n";
        case 2: std::cout << "two\n";
        case 3: std::cout << "three\n";
        default: std::cout << "default\n";
    }
    // ^ notice: NO break statements above. PREDICT what prints before running,
    // then run it and see how "falling through" cases actually behaves.
    // two and default is the ouput. is that correct?

    std::cout << "\n--- nested conditions: is it a leap-ish check? (practice, not the assignment) ---\n";
    int year = 2028;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << year << ": divisible by 4, 100, and 400\n";
            } else {
                std::cout << year << ": divisible by 4 and 100 but NOT 400\n";
            }
        } else {
            std::cout << year << ": divisible by 4 but not 100\n";
        }
    } else {
        std::cout << year << ": not divisible by 4\n";
    }

    // 2028 is divisible by 4 but not by 100. is that correct?

    return 0;
}

/*
   NOTE: The nested if-chain above is deliberately similar in SHAPE to the
   leap year rule, but Assignment 1 asks you to write the actual leap year
   checker yourself -- don't copy this block for that, it's a warm-up for
   reading nested conditions, not the answer.
*/

// Any exercises for me from this section? Yes! Try to predict the output of the switch fallthrough example before running it. Also, try modifying the nested conditions to check for leap years correctly based on the actual rules.