#include <exception>
#include <iostream>

class InvalidInputError : public std::exception {
    private: 
        int errorCode;
        std::string message;
    public:
        InvalidInputError(int code, std::string msg) : errorCode(code), message(msg) {}

        int code() const noexcept {
            return errorCode;
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
};

int divide(int a, int b) {
    if (b == 0) {
        throw InvalidInputError(1001, "For division operation - Denominator cannot be zero");
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
        std::cin >> num1;

        std::cout << "Enter the second whole number: ";
        std::cin >> num2;

        std::cout << "Enter an operation (add / subtract / multiply / divide): ";
        std::cin >> userInput;
        std::cin.ignore();

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
    } catch (const InvalidInputError& e) {
        std::cerr << "Error [" << e.code() << "]: " << e.what() << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument - " << e.what() << "\n";
    }

    return 0;
}

