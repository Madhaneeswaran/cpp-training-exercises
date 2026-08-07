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

    if(std::cin.fail() || year <= 0) {
        std::cout << "Error: That is not valid year to check whether it's a leap year or not. \n";
    } else {
        checkLeapYear(year);
    }

}