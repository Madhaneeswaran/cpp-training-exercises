#include <iostream>
#include <set>

int main() {
    std::set<double> uniqueNumbers;
    std::string userInput;
    std::cout << "Enter numbers. Type 'exit' to stop:\n";

    while(true) {
        try {
            std::cin >> userInput;
            if (userInput == "exit") {
                break; 
            }
    
            double doubleNum = std::stod(userInput);
            
            uniqueNumbers.insert(doubleNum);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input \n";
        }
    }

    std::cout << "\n--- Program Stopped ---" << std::endl;
    std::cout << "You successfully stored " << uniqueNumbers.size() << " numbers:\n";

    for (double num : uniqueNumbers) {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    return 0;
}