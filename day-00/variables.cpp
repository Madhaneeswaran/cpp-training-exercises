#include <iostream>

int g; // Global variable

int main() {
    bool isStudent = true;
    std::cout << "Am I a student? " << (isStudent ? "Yes" : "No") << std::endl;

    int a, b;

    a = 10;
    b = 20;

    g = a + b;
    
    std::cout << g;
    return 0;
}