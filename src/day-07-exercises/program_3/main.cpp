#include <iostream>
#include "factorial.h" 

int main() {
    int number;

    std::cout << "Enter a number from 1 - 20: ";
    std::cin >> number;

    if (!std::cin || number < 1 || number > 20) {
        std::cerr << "Invalid input. Please enter an integer between 1 and 20.\n";
        return 1;
    }

    unsigned long long fact = calculate_factorial(number);
    
    std::cout << "The factorial of " << number << " is: " << fact << std::endl;
    return 0;
}