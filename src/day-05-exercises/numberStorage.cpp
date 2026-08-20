#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<double> uniqueNumbers;
    std::string userInput;
    std::cout << "Enter numbers. Type 'exit' to stop:\n";

    while(std::cin >> userInput) {
        try {
            if (userInput == "exit") {
                break; 
            }
    
            double doubleNum = std::stod(userInput);
            uniqueNumbers.insert(doubleNum);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    if (std::cin.eof()) {
        std::cout << "Stream reached End-of-File (EOF). Exiting cleanly.\n";
    } else if (std::cin.fail()) {
        std::cerr << "Stream encountered a parsing failure.\n";
    }

    std::cout << "\n--- Program Stopped ---" << std::endl;
    std::cout << "You successfully stored " << uniqueNumbers.size() << " numbers:\n";

    for (double num : uniqueNumbers) {
        std::cout << num << ' ';
    }

    std::cout << '\n';

    return 0;
}