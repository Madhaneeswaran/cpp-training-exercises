#include <iostream>

void checkLeapYear(int year) {
    if (year % 400 == 0) {
        std::cout << year << " is a leap year.\n";
    } else if ((year % 100 != 0) && (year % 4 == 0)) {
        std::cout << year << " is a leap year.\n";
    } else {
        std::cout << year << " is not a leap year.\n";
    }
}

int main () {
    int year;

    std::cout << "Enter a year: ";
    std::cin >> year;

    checkLeapYear(year);
}

// #include <iostream>
// #include <cstring>
// #include <algorithm>

// int numOfCharToStore(char* str) {
//     return strlen(str) + 1;
// }

// void getSortedName(char* name) {
//     std::sort(name, name + strlen(name));
// }

// int main() {
//     char name[100];
//     std::cout << "Enter your name :- ";
//     std::cin.getline(name, 100);

//     std::cout << numOfCharToStore(name) << " - number of bytes required to store your name!" << std::endl;

//     getSortedName(name);
//     std::cout << "Sorted name:- " << name << '\n';
// }