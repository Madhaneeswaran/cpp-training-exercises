#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>

class DivisionByZeroException : public std::exception {
    private: 
        int errorCode;
        std::string message;
    public:
        DivisionByZeroException(int code, const std::string& msg) : errorCode(code), message(msg) {}

        int code() const [[nodiscard]] {
            return errorCode;
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
};

int divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException(1001, "For division operation - Denominator cannot be zero");
    }
    return a/b;
}

int add(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

int main() {
    int num1;
    int num2;
    std::string userInput;

    
    try {
        std::cout << "Enter the first whole number: ";
        if(!(std::cin >> num1)) {
            throw std::runtime_error("First input is not a valid whole number.");
        }

        std::cout << "Enter the second whole number: ";
        if (!(std::cin >> num2)) {
            throw std::runtime_error("Second input is not a valid whole number.");
        }

        std::cout << "Enter an operation (add / subtract / multiply / divide): ";
        if (!(std::cin >> userInput)) {
            throw std::runtime_error("Failed to read the operation string.");
        }

        if (userInput == "add") {
            std::cout << add(num1, num2) << '\n';
        } else if (userInput == "subtract") {
            std::cout << subtract(num1, num2) << '\n';
        } else if(userInput == "multiply") {
            std::cout << multiply(num1, num2) << '\n';  
        } else if (userInput == "divide") {
            std::cout << divide(num1, num2) << '\n';
        } else {
            throw std::invalid_argument("Enter add / subtract / multiply / divide");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Input Error: " << e.what() << '\n';
        return 1;
    } catch (const DivisionByZeroException& e) {
        std::cerr << "Error [" << e.code() << "]: " << e.what() << '\n';
        return 1;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument - " << e.what() << "\n";
        return 1;
    }

    return 0;
}

